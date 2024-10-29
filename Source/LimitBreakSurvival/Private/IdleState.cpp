// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"

#include "GameFramework/Character.h"

void UIdleState::EnterState(ACharacter* player)
{
	Super::EnterState(player);
}

void UIdleState::EnterState_Implementation(ACharacter* player)
{
}

void UIdleState::ExitState(ACharacter* player)
{
	Super::ExitState(player);
}

void UIdleState::ExitState_Implementation(ACharacter* player)
{
	Super::ExitState_Implementation(player);
}

void UIdleState::Tick(ACharacter* player, float DeltaSeconds)
{
	Super::Tick(player, DeltaSeconds);

}

void UIdleState::Tick_Implementation(ACharacter* player, float DeltaSeconds)
{
	Super::Tick_Implementation(player, DeltaSeconds);
}
