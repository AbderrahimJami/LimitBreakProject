// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerStateBase.h"
#include "IdleState.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class LIMITBREAKSURVIVAL_API UIdleState : public UPlayerStateBase
{
	GENERATED_BODY()


public:
	void EnterState(ACharacter* player);
	virtual void EnterState_Implementation(ACharacter* Player) override;

	void ExitState(ACharacter* Player);
	virtual void ExitState_Implementation(ACharacter* Player) override;

	void Tick(ACharacter* Player, float DeltaSeconds);
	virtual void Tick_Implementation(ACharacter* Player, float DeltaSeconds) override;

	
	
};
