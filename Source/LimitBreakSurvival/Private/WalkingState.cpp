﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "WalkingState.h"



void UWalkingState::EnterState_Implementation(ACharacter* Player)
{
	Super::EnterState_Implementation(Player);

}

void UWalkingState::ExitState(ACharacter* Player)
{
	Super::ExitState(Player);
}

void UWalkingState::ExitState_Implementation(ACharacter* Player)
{
	Super::ExitState_Implementation(Player);
}

void UWalkingState::Tick(ACharacter* Player, const float DeltaSeconds)
{
	Super::Tick(Player, DeltaSeconds);
}

void UWalkingState::Tick_Implementation(ACharacter* Player, float DeltaSeconds)
{
	Super::Tick_Implementation(Player, DeltaSeconds);
}

void UWalkingState::OnMoveAction(FVector MoveInput)
{
	Super::OnMoveAction(MoveInput);
}
