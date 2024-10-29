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


	//Delegates

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* MoveInputAction;

	virtual FMoveSignature* GetMoveDelegate() override;

private:
	FMoveSignature OnMoveInputEvent;

	
};
