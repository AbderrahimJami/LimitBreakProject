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
	virtual void EnterState_Implementation(ACharacter* player) override;

	void ExitState(ACharacter* player);
	virtual void ExitState_Implementation(ACharacter* player) override;

	void Tick(ACharacter* player, float DeltaSeconds);
	virtual void Tick_Implementation(ACharacter* player, float DeltaSeconds) override;

	
	
};
