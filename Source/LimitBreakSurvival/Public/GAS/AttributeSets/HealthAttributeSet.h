// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.generated.h"

/**
 *
 */
UCLASS()
class LIMITBREAKSURVIVAL_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UHealthAttributeSet();
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HealingReceivedMultiplier;
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, HealingReceivedMultiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DamageTakenMultiplier;
	ATTRIBUTE_ACCESSORS_BASIC(UHealthAttributeSet, DamageTakenMultiplier)
};
