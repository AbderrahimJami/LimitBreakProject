// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "WeaponHandlingAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class LIMITBREAKSURVIVAL_API UWeaponHandlingAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
	
public:
	UWeaponHandlingAttributeSet();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData Spread;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, Spread)	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData AimSpeed;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, AimSpeed)	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData HipFireSpread;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, HipFireSpread)	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData RecoilHorizontal;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, RecoilHorizontal)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData RecoilVertical;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, RecoilVertical)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData SwayIntensity;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, SwayIntensity)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData AimStability;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, AimStability)
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData HandlingSpeed;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, HandlingSpeed)
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData ReloadSpeed;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, ReloadSpeed)
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData EquipSpeed;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, EquipSpeed)
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData ADSInTime;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, ADSInTime)
				
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData ADSOutTime;
	ATTRIBUTE_ACCESSORS_BASIC(UWeaponHandlingAttributeSet, ADSOutTime)
	

};
