// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"

#include "PlayerCharacter.h"
#include "StateManagerComponent.h"
#include "GameFramework/Character.h"

void UIdleState::EnterState(ACharacter* player)
{
	Super::EnterState(player);
	
}

void UIdleState::EnterState_Implementation(ACharacter* Player)
{
	Super::EnterState_Implementation(Player);
}

void UIdleState::ExitState(ACharacter* Player)
{
	Super::ExitState(Player);
}

void UIdleState::ExitState_Implementation(ACharacter* Player)
{
	Super::ExitState_Implementation(Player);
}

void UIdleState::Tick(ACharacter* Player, const float DeltaSeconds)
{
	Super::Tick(Player, DeltaSeconds);

}

void UIdleState::Tick_Implementation(ACharacter* Player, float DeltaSeconds)
{
	Super::Tick_Implementation(Player, DeltaSeconds);

	
}

void UIdleState::OnMoveAction(FVector MoveInput)
{
	Super::OnMoveAction(MoveInput);
	//Change state
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::MakeRandomColor(), "Move Action from IdleState");
	
	PlayerCharacterRef->StateManager->SwitchStateByKey("Walk");
	PlayerCharacterRef->bIsMoving = true;
}

void UIdleState::OnInteractAction_Implementation()
{
	Super::OnInteractAction_Implementation();
	
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::MakeRandomColor(), "Interact Action from IdleState");
}





