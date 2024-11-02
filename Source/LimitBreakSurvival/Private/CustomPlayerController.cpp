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

void ACustomPlayerController::OnAimInputAction(const FInputActionValue& Value)
{
	FVector AimInput = Value.Get<FVector>();
	if (OnMoveInputEvent.IsBound())
	{
		OnMoveInputEvent.Broadcast(AimInput);
	}
}

void ACustomPlayerController::OnInteractInputAction(const FInputActionValue& Value)
{
	if (OnInteractInputEvent.IsBound())
	{
		OnInteractInputEvent.Broadcast();
	}
}


void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerMappingContext, 0);
	}

	ClamCameraPitch();
	
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Bind Actions here!
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ACustomPlayerController::OnMoveInputAction);
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Completed, this, &ACustomPlayerController::OnMoveInputAction);
		//Bind Aim function to AimInputAction
		EnhancedInputComponent->BindAction(AimInputAction, ETriggerEvent::Triggered, this, &ACustomPlayerController::Aim);
		EnhancedInputComponent->BindAction(AimInputAction, ETriggerEvent::Completed, this, &ACustomPlayerController::Aim);
		//Bind callback function to Broadcast input action event trigger to listening states
		EnhancedInputComponent->BindAction(AimInputAction, ETriggerEvent::Completed, this, &ACustomPlayerController::OnAimInputAction);
		EnhancedInputComponent->BindAction(AimInputAction, ETriggerEvent::Completed, this, &ACustomPlayerController::OnAimInputAction);
		
		//Bind Interact callback function to InteractInputAction
		EnhancedInputComponent->BindAction(InteractInputAction, ETriggerEvent::Triggered, this, &ACustomPlayerController::OnInteractInputAction);
	}
	
}

FMoveSignature* ACustomPlayerController::GetMoveDelegate()
{
	return &OnMoveInputEvent;
}

FAimSignature* ACustomPlayerController::GetAimDelegate()
{
	return &OnAimInputEvent;
}

FInteractSignature* ACustomPlayerController::GetInteractDelegate()
{
	return &OnInteractInputEvent;
}

void ACustomPlayerController::Aim(const FInputActionValue& Value)
{
	FVector MouseInput = Value.Get<FVector>();
	GetPawn()->AddControllerYawInput(MouseInput.X);
	GetPawn()->AddControllerPitchInput(MouseInput.Y * -1);

}


void ACustomPlayerController::ClamCameraPitch() const
{
	PlayerCameraManager->ViewPitchMax = CameraPitchLimit;
	PlayerCameraManager->ViewPitchMin = -CameraPitchLimit;
}
