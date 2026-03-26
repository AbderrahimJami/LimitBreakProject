// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AmmoAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class LIMITBREAKSURVIVAL_API UAmmoAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAmmoAttributeSet();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData SmallAmmoReserve;
	ATTRIBUTE_ACCESSORS_BASIC(UAmmoAttributeSet, SmallAmmoReserve)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData MediumAmmoReserve;
	ATTRIBUTE_ACCESSORS_BASIC(UAmmoAttributeSet, MediumAmmoReserve)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData HeavyAmmoReserve;
	ATTRIBUTE_ACCESSORS_BASIC(UAmmoAttributeSet, HeavyAmmoReserve)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData ShellAmmoReserve;
	ATTRIBUTE_ACCESSORS_BASIC(UAmmoAttributeSet, ShellAmmoReserve)
	
};
