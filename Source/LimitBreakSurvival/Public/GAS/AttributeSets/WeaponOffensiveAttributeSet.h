// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "WeaponOffensiveAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class LIMITBREAKSURVIVAL_API UWeaponOffensiveAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UWeaponOffensiveAttributeSet();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData BaseDamage;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, BaseDamage)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData WeakSpotMultiplier;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, WeakSpotMultiplier)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, ArmorPenetration)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData StoppingPower;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, StoppingPower)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData StaggerPower;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, StaggerPower)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData RateOfFire;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, RateOfFire)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData HitScanRangeFallOff;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, HitScanRangeFallOff)

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData CritChance;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponOffensiveAttributeSet, CritChance)
};
