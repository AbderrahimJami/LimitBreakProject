// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "PlayerControllerInterface.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class LIMITBREAKSURVIVAL_API ACustomPlayerController : public APlayerController, public IPlayerControllerInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual  void SetupInputComponent() override;

	void OnMoveInputAction(const FInputActionValue& Value);
	void OnAimInputAction(const FInputActionValue& Value);
	void OnInteractInputAction(const FInputActionValue& Value);
	//Delegates

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* MoveInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	const UInputAction* AimInputAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	const UInputAction* InteractInputAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	float CameraPitchLimit = 80.0f;

	
	virtual FMoveSignature* GetMoveDelegate() override;

	virtual FAimSignature* GetAimDelegate() override;

	virtual FInteractSignature* GetInteractDelegate() override;

private:

	void Aim(const FInputActionValue& Value);
	void ClamCameraPitch() const;

	
	FMoveSignature OnMoveInputEvent;
	FAimSignature OnAimInputEvent;
	FInteractSignature OnInteractInputEvent;
	
};
