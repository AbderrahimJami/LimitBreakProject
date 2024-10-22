// Fill out your copyright notice in the Description page of Project Settings.


#include "WalkingState.h"



void UWalkingState::EnterState_Implementation(ACharacter* player)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "WalkingState::EnterState_Implementation");
}

void UWalkingState::ExitState(ACharacter* player)
{
	Super::ExitState(player);
}

void UWalkingState::ExitState_Implementation(ACharacter* player)
{
	Super::ExitState_Implementation(player);
}

void UWalkingState::Tick(ACharacter* player, float DeltaSeconds)
{
	Super::Tick(player, DeltaSeconds);
}

void UWalkingState::Tick_Implementation(ACharacter* player, float DeltaSeconds)
{
	Super::Tick_Implementation(player, DeltaSeconds);
}
