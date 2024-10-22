// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerStateBase.generated.h"


//Forward Declare PlayerCharacter

UCLASS(Blueprintable, BlueprintType)
class LIMITBREAKSURVIVAL_API UPlayerStateBase : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PlayerState", meta = (DefaultToSelf = "player"))
	void EnterState(ACharacter* player);
	virtual void EnterState_Implementation(ACharacter* player);

	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PlayerState", meta = (DefaultToSelf = "player"))
	void ExitState(ACharacter* player);
	virtual void ExitState_Implementation(ACharacter* player);

	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PlayerState", meta = (DefaultToSelf = "player"))
	void Tick(ACharacter* player, float DeltaSeconds);
	virtual void Tick_Implementation(ACharacter* player, float DeltaSeconds);
	
};
