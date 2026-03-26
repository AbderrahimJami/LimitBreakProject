// Fill out your copyright notice in the Description page of Project Settings.


#include "StateManagerComponent.h"

#include "Evaluation/MovieSceneEvaluationCustomVersion.h"
#include "GameFramework/Character.h"


// Sets default values for this component's properties
UStateManagerComponent::UStateManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeStates();
	
}


// Called every frame
void UStateManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bCanTickState)
	{
		CurrentState->Tick(Cast<ACharacter>(GetOwner()), DeltaTime); 
	}
	if (bDebug)
	{
		if (CurrentState)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, FString::Printf(TEXT("Current state is: %s"), *CurrentState->GetName()));
			for (auto State : StateHistory)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Blue, FString::Printf(TEXT("Past state is: %s"), *State->GetName()));
			}
		}
	}
	
}

void UStateManagerComponent::SwitchStateByKey(FString StateKey)
{
	UPlayerStateBase* NewState = StateMap.FindRef(StateKey);

	if (NewState->IsValidLowLevel())
	{
		/*If there is no current state, it means we are at init*/
		if (!CurrentState)
		{
			CurrentState = NewState;
		}
		else
		{
			if (CurrentState->GetClass() == NewState->GetClass() && CurrentState->bCanRepeat == false)
			{
				if (bDebug)
				{
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("%s switch failed"), *StateKey));
				}
			}
			else
			{
				bCanTickState = false;
				CurrentState->ExitState(Cast<ACharacter>(this->GetOwner()));
				if (StateHistory.Num() < StateHistoryLength)
				{
					StateHistory.Push(CurrentState);
				}
				else
				{
					StateHistory.RemoveAt(0);
					StateHistory.Push(CurrentState);
				}

				CurrentState = NewState;
			}
		}

		if (CurrentState)
		{
			CurrentState->EnterState(Cast<ACharacter>(GetOwner()));
			bCanTickState = true;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("%s is an invalid state"), *StateKey));
	}
}

void UStateManagerComponent::SwitchState(UPlayerStateBase* NewState)
{
}

void UStateManagerComponent::InitStateManager()
{
	SwitchStateByKey(InitialState);
	
}

void UStateManagerComponent::InitializeStates()
{
	for (auto StateName : AvailableStates)
	{
		UPlayerStateBase* State = NewObject<UPlayerStateBase>(this, StateName.Value);
		StateMap.Add(StateName.Key, State);
	}
}

