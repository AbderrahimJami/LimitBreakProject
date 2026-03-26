// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "StaminaAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class LIMITBREAKSURVIVAL_API UStaminaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UStaminaAttributeSet();
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UStaminaAttributeSet, Stamina)
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UStaminaAttributeSet, MaxStamina)
};
