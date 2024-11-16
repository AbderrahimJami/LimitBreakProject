// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"

#include "PlayerCharacter.generated.h"

class UCameraComponent;
class UStateManagerComponent;
class UInputAction;
class UInputMappingContext;
class UHealthComponentBase;
class UPlayerStateBase;
class UIdleState;
class UWalkingState;

UCLASS()
class LIMITBREAKSURVIVAL_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* PlayerMappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	const UInputAction* MoveInputAction = nullptr;

	
	UPROPERTY(Category=Character, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
	class USceneComponent* PivotPoint;
	
	UPROPERTY(Category=Character, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	
	void Move(const FInputActionValue& Value);
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	class UHealthComponentBase* HealthComp;

	
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = Input)
	FVector2D MoveInput;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Finite State Machine")
	UStateManagerComponent* StateManager;

	UPROPERTY(BlueprintReadOnly, Category = "Animation Trigger Variables")
	bool bIsMoving = false;

private:
	UPlayerStateBase* PlayerState;
	UIdleState* IdleState;
	UWalkingState* WalkingState;



};
