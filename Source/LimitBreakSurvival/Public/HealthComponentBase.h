// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, newHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRevive);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class LIMITBREAKSURVIVAL_API UHealthComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponentBase();

	/*
	Increases current health, up to the maximum health limit 
	 */
	UFUNCTION(BlueprintCallable, Category="Health")
	void Heal(float healAmount = 10.f);
	
	
	UFUNCTION(Blueprintable, Category = "Health")
	bool IsDead() const;

	/*
	Reduces current health based on the damage received, potentially
	triggering death if health reaches zero.
	 */
	UFUNCTION(BlueprintCallable, Category="Damage Handling")
	void TakeDamage(float damageAmount = 10);

	/*
	Applies gradual damage over a set duration
	 */
	UFUNCTION(BlueprintCallable, Category="Health")
	void ApplyHealthOverTime(float HealthPerSecond, float Duration);

	/*
	Applies gradual damage over a set duration
	 */
	UFUNCTION(BlueprintCallable, Category="Health")
	void ApplyDamageOverTime(float DamagePerSecond, float Duration);

	
	/*
	 Resets current health to the maximum value, useful for respawns or healing events
	 */
	UFUNCTION(BlueprintCallable, Category="Health")
	void RestoreToMaxHealth();
	
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	/*
	Tracks the enemy's or player's current health status.
	This value decreases when damage is taken and determines
	when the character is defeated
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health", meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
	bool bMaxHealthSetOnStart;
	
	
	//Event Dispatchers
	UPROPERTY(BlueprintAssignable, Category = "Health Events")
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Health Events")
	FOnDeath OnDeath;

	UPROPERTY(BlueprintAssignable, Category = "Health Events")
	FOnRevive OnRevive;
	
private:
	bool isDead = false;
	FTimerDelegate healthTimerDelegate;
	FTimerHandle healthTimer;

	FTimerDelegate damageTimerDelegate;
	FTimerHandle damageTimer;

	
	

};
