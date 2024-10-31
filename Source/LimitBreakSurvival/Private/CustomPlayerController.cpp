// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"



void ACustomPlayerController::OnMoveInputAction(const FInputActionValue& Value)
{
	FVector MoveInputVector = Value.Get<FVector>();
	if (OnMoveInputEvent.IsBound())
	{
		OnMoveInputEvent.Broadcast(MoveInputVector);
	}
}

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerMappingContext, 0);
	}
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Bind Actions here!
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ACustomPlayerController::OnMoveInputAction);
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Completed, this, &ACustomPlayerController::OnMoveInputAction);
		
		EnhancedInputComponent->BindAction(AimInputAction, ETriggerEvent::Triggered, this, &ACustomPlayerController::Aim);
		EnhancedInputComponent->BindAction(AimInputAction, ETriggerEvent::Completed, this, &ACustomPlayerController::Aim);
		
	}
	
}

FMoveSignature* ACustomPlayerController::GetMoveDelegate()
{
	return &OnMoveInputEvent;
}
void ACustomPlayerController::Aim(const FInputActionValue& Value)
{
	FVector MouseInput = Value.Get<FVector>();
	GetPawn()->AddControllerYawInput(MouseInput.X);
	GetPawn()->AddControllerPitchInput(MouseInput.Y * -1);
}
