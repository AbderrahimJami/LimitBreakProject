// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateBase.h"

void UPlayerStateBase::EnterState_Implementation(ACharacter* player)
{
	GEngine->AddOnScreenDebugMessage(-2, 3, FColor::MakeRandomColor(), "Entering State");
}

void UPlayerStateBase::ExitState_Implementation(ACharacter* player)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::MakeRandomColor(), "Exiting State");
}

void UPlayerStateBase::Tick_Implementation(ACharacter* player, float DeltaSeconds)
{
	//This is just for Debugging
	// GEngine->AddOnScreenDebugMessage(-1, 3, FColor::MakeRandomColor(), "Ticking State");
}
