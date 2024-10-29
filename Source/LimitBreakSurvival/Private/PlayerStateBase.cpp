// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateBase.h"

#include "PlayerCharacter.h"
#include "PlayerControllerInterface.h"
#include "Kismet/GameplayStatics.h"

void UPlayerStateBase::OnMoveAction(FVector MoveInput)
{
	//Handle OnMoveAction Event triggered
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
	PlayerControllerRef->GetMoveDelegate()->AddUObject(this, &UPlayerStateBase::OnMoveAction);
	
}	

void UPlayerStateBase::ExitState_Implementation(ACharacter* Player)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::MakeRandomColor(), "Exiting State");
	//Unbind all callback functions from OnMoveEvent Delegate
	// int sdfjsdkjlf = 23;
	PlayerControllerRef->GetMoveDelegate()->RemoveAll(this);
	
}




void UPlayerStateBase::Tick_Implementation(ACharacter* player, float DeltaSeconds)
{
	//This is just for Debugging
	// GEngine->AddOnScreenDebugMessage(-1, 3, FColor::MakeRandomColor(), "Ticking State");
}
