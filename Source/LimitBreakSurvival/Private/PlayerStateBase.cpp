// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateBase.h"

#include "PlayerCharacter.h"
#include "PlayerControllerInterface.h"
#include "Kismet/GameplayStatics.h"

void UPlayerStateBase::OnMoveAction(FVector MoveInput)
{
	//Handle OnMoveAction Event triggered
}

void UPlayerStateBase::OnAimAction(FVector AimInput)
{
	//Handle OnAimAction Event triggered
}

void UPlayerStateBase::OnInteractAction()
{
	//Handle OnInputAction Event triggered
}

void UPlayerStateBase::EnterState_Implementation(ACharacter* player)
{
	if (!PlayerCharacterRef)
	{
		PlayerCharacterRef = CastChecked<APlayerCharacter>(player);
	}

	//Bind Input Delegates
	//Cache PlayerController
	if (!PlayerControllerRef)
	{
		//Interpret the Playercontroller as if it's an interface
		PlayerControllerRef = CastChecked<IPlayerControllerInterface>(UGameplayStatics::GetPlayerController(this, 0));
		//Bind Functions
	}

	//Binding and Unbinding from Input delegates can be done in 2 ways here, either the base class binds to all input delegates,
	//using a overridable virtual function actual states can then override and do something about, or you let them bind/unbind
	//Individually.
	PlayerControllerRef->GetMoveDelegate()->AddUObject(this, &UPlayerStateBase::OnMoveAction);
	PlayerControllerRef->GetAimDelegate()->AddUObject(this, &UPlayerStateBase::OnAimAction);
	PlayerControllerRef->GetInteractDelegate()->AddUObject(this, &UPlayerStateBase::OnInteractAction);
}	

void UPlayerStateBase::ExitState_Implementation(ACharacter* Player)
{
	//Unbind all callback functions from Input event delegates
	PlayerControllerRef->GetMoveDelegate()->RemoveAll(this);
	PlayerControllerRef->GetAimDelegate()->RemoveAll(this);
	PlayerControllerRef->GetInteractDelegate()->RemoveAll(this);
}




void UPlayerStateBase::Tick_Implementation(ACharacter* player, float DeltaSeconds)
{
	//This is just for Debugging
	// GEngine->AddOnScreenDebugMessage(-1, 3, FColor::MakeRandomColor(), "Ticking State");
}
