// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStateBase.h"
#include "StateManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LIMITBREAKSURVIVAL_API UStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStateManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Finite State Machine" )
	FString InitialState;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Finite State Machine" )
	TMap<FString, TSubclassOf<UPlayerStateBase>> AvailableStates;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Finite State Machine" )
	bool bDebug = false;

	UPROPERTY(BlueprintReadOnly)
	TArray<UPlayerStateBase*> StateHistory;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Finite State Machine" , meta = (ClampMin = "0", ClampMax = "10", UIMin = "0", UIMax = "10"))
	int32 StateHistoryLength;

	UPROPERTY(BlueprintReadOnly)
	UPlayerStateBase* CurrentState = nullptr;

	UPROPERTY()
	TMap<FString, UPlayerStateBase*> StateMap;

	UFUNCTION(BlueprintCallable, Category = "Finite State Machine")
	void SwitchStateByKey(FString StateKey);

	UFUNCTION(BlueprintCallable, Category = "Finite State Machine")
	void SwitchState(UPlayerStateBase* NewState);

	UFUNCTION(BlueprintCallable, Category = "Finite State Machine")
	void InitStateManager();


private:
	bool bCanTickState = false;
	void InitializeStates();

};
