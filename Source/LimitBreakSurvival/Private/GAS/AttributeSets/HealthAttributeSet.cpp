// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AttributeSets/HealthAttributeSet.h"
UHealthAttributeSet::UHealthAttributeSet()
{
	Health = 100.0f;
	MaxHealth = 100.0f;
	HealingReceivedMultiplier = 1.0f;
	DamageTakenMultiplier = 1.0f;
}
