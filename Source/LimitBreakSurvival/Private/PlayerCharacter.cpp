// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "HealthComponentBase.h"
#include "Components/InputComponent.h"
#include "HealthComponentBase.h"
#include "StateManagerComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StateManager = CreateDefaultSubobject<UStateManagerComponent>(TEXT("StateManager"));
	HealthComp = CreateDefaultSubobject<UHealthComponentBase>(TEXT("HealthComp"));


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPS Camera"));
	if (Camera)
	{
		Camera->SetupAttachment(GetMesh(), "head");
	}

	
	//Add Pivot point scene comp
	PivotPoint = CreateDefaultSubobject<USceneComponent>(TEXT("PivotPoint"));
	if (PivotPoint)
	{
		PivotPoint->SetupAttachment(RootComponent);
		PivotPoint->SetWorldLocation(Camera->GetComponentLocation());
		//Make Mesh from ACharacter class a child of the Pivot point in code.. 
		GetMesh()->SetupAttachment(PivotPoint);
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	StateManager->InitStateManager();
	
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	MoveInput = Value.Get<FVector2D>();
	
	
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


