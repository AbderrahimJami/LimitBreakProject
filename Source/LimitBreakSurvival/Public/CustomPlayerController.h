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

	void OnMoveInputAction(const FInputActionValue& Value);
public:
	virtual void BeginPlay() override;
	virtual  void SetupInputComponent() override;

	void OnMoveInputAction(const FInputActionValue& Value);
	void OnAimInputAction(const FInputActionValue& Value);
	//Delegates

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* MoveInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	const UInputAction* AimInputAction = nullptr;
	
	virtual FMoveSignature* GetMoveDelegate() override;

	virtual FAimSignature* GetAimDelegate() override;

private:

	void Aim(const FInputActionValue& Value);
	
	FMoveSignature OnMoveInputEvent;
	FAimSignature OnAimInputEvent;

	
};
