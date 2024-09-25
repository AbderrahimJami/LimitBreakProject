// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponentBase.h"

// Sets default values for this component's properties
UHealthComponentBase::UHealthComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	

	

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
	
	//Letting code know health changed
	OnHealthChanged.Broadcast(CurrentHealth);
	if (CurrentHealth <= 0)
	{
		isDead = true;
		//Letting rest of the code know the Owning Actor's dead now 
		OnDeath.Broadcast();
	}
	
}

void UHealthComponentBase::ApplyHealthOverTime(float DamagePerSecond, float Duration)
{
	timerDelegate.BindUFunction(this, FName("Heal"), DamagePerSecond);
	FTimerHandle durationTimer;
	GetWorld()->GetTimerManager().SetTimer(Timer, timerDelegate, 1.0f, true);
	GetWorld()->GetTimerManager().SetTimer(durationTimer, FTimerDelegate::CreateLambda([&]
	{
		GetWorld()->GetTimerManager().ClearTimer(Timer);

	}), Duration, false);
	
}


// Called when the game starts
void UHealthComponentBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponentBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

