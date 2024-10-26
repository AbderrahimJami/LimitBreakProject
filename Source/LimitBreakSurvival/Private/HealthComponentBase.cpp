// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponentBase.h"

#include "Editor.h"

// Sets default values for this component's properties
UHealthComponentBase::UHealthComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	CurrentHealth = 0.f;
	MaxHealth = 100.f;
	bMaxHealthSetOnStart = false;

	

	// ...
}

void UHealthComponentBase::Heal(float HealAmount)
{
	if (CurrentHealth == MaxHealth) return;
	CurrentHealth += HealAmount;
	if (CurrentHealth > MaxHealth)
		CurrentHealth = MaxHealth;
	//Broadcast Health Change
	//Pass Old Health as well 
	OnHealthChanged.Broadcast(CurrentHealth);

}

bool UHealthComponentBase::IsDead() const
{
	return bIsDead;
}

void UHealthComponentBase::TakeDamage(float DamageAmount)
{
	
	CurrentHealth -= DamageAmount;
	//Check if there's an active timer 
	if (CurrentHealth <= 0)
	{
		bIsDead = true;
		//Letting rest of the code know the Owning Actor's dead now 
		OnDeath.Broadcast();

		//Check if there's damage is being applied over time
		if (DamageTimer.IsValid())
		{
			GetWorld()->GetTimerManager().ClearTimer(DamageTimer);
		}
	}
	//Letting code know health changed
	OnHealthChanged.Broadcast(CurrentHealth);
	
}

void UHealthComponentBase::ApplyHealthOverTime(float HealthPerSecond, float Duration)
{
	HealthTimerDelegate.BindUFunction(this, FName("Heal"), HealthPerSecond);
	FTimerHandle durationTimer;
	GetWorld()->GetTimerManager().SetTimer(HealthTimer, HealthTimerDelegate, 1.0f, true);
	GetWorld()->GetTimerManager().SetTimer(durationTimer, FTimerDelegate::CreateLambda([&]
	{
		GetWorld()->GetTimerManager().ClearTimer(HealthTimer);

	}), Duration, false);
	
}

void UHealthComponentBase::ApplyDamageOverTime(float DamagePerSecond, float Duration)
{
	DamageTimerDelegate.BindUFunction(this, FName("TakeDamage"), DamagePerSecond);
	FTimerHandle durationTimer;
	GetWorld()->GetTimerManager().SetTimer(DamageTimer, DamageTimerDelegate, 1.0f, true);
	GetWorld()->GetTimerManager().SetTimer(durationTimer, FTimerDelegate::CreateLambda([&]
	{
		GetWorld()->GetTimerManager().ClearTimer(DamageTimer);
	}), Duration, false);

	
}

void UHealthComponentBase::RestoreToMaxHealth()
{
	if (CurrentHealth >= MaxHealth) return;
	if (CurrentHealth <= 0)
		OnRevive.Broadcast();
	
	CurrentHealth = MaxHealth;
	OnHealthChanged.Broadcast(CurrentHealth);
	
}


// Called when the game starts
void UHealthComponentBase::BeginPlay()
{
	Super::BeginPlay();

	if (bMaxHealthSetOnStart)
		CurrentHealth = MaxHealth;
	
	// ...
	
}


// Called every frame
void UHealthComponentBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

