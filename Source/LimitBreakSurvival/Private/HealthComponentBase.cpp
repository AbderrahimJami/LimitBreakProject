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

void UHealthComponentBase::Heal(float healAmount)
{
	if (CurrentHealth == healAmount) return;
	CurrentHealth += healAmount;
	if (CurrentHealth >= MaxHealth)
		CurrentHealth = MaxHealth;
	//Broadcast Health Change
	OnHealthChanged.Broadcast(CurrentHealth);

}

bool UHealthComponentBase::IsDead() const
{
	return isDead;
}

void UHealthComponentBase::TakeDamage(float damageAmount)
{
	
	CurrentHealth -= damageAmount;
	//Check if there's an active timer 
	if (CurrentHealth <= 0)
	{
		isDead = true;
		//Letting rest of the code know the Owning Actor's dead now 
		OnDeath.Broadcast();

		//Check if there's damage is being applied over time
		if (damageTimer.IsValid())
		{
			GetWorld()->GetTimerManager().ClearTimer(damageTimer);
		}
	}
	//Letting code know health changed
	OnHealthChanged.Broadcast(CurrentHealth);
	
}

void UHealthComponentBase::ApplyHealthOverTime(float HealthPerSecond, float Duration)
{
	healthTimerDelegate.BindUFunction(this, FName("Heal"), HealthPerSecond);
	FTimerHandle durationTimer;
	GetWorld()->GetTimerManager().SetTimer(healthTimer, healthTimerDelegate, 1.0f, true);
	GetWorld()->GetTimerManager().SetTimer(durationTimer, FTimerDelegate::CreateLambda([&]
	{
		GetWorld()->GetTimerManager().ClearTimer(healthTimer);

	}), Duration, false);
	
}

void UHealthComponentBase::ApplyDamageOverTime(float DamagePerSecond, float Duration)
{
	damageTimerDelegate.BindUFunction(this, FName("TakeDamage"), DamagePerSecond);
	FTimerHandle durationTimer;
	GetWorld()->GetTimerManager().SetTimer(damageTimer, damageTimerDelegate, 1.0f, true);
	GetWorld()->GetTimerManager().SetTimer(durationTimer, FTimerDelegate::CreateLambda([&]
	{
		GetWorld()->GetTimerManager().ClearTimer(damageTimer);
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

