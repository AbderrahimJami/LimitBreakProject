// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"

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
