// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AttributeSets/WeaponOffensiveAttributeSet.h"
UWeaponOffensiveAttributeSet::UWeaponOffensiveAttributeSet()
{
	BaseDamage = 50.0f;
	WeakSpotMultiplier = 1.5f;
	ArmorPenetration = 10.f;
	StoppingPower = 1.0f;
	StaggerPower = 1.0f;
	RateOfFire = 1.0f;
	HitScanRangeFallOff = 100.0f;
	CritChance = 0.2f;
}
