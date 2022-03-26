// Fill out your copyright notice in the Description page of Project Settings.


#include "amerikeCharacter.h"

// Sets default values
AamerikeCharacter::AamerikeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->TargetArmLength = 300.f;
	cameraBoom->bUsePawnControlRotation = true;
	//Acomodar la cámara
	cameraBoom->SocketOffset = FVector(0.f, 50.f, 50.f);


	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	//Esto lo deja al final de la raiz del objeto al que lo estas agregando
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	followCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AamerikeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AamerikeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AamerikeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &AamerikeCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Horizontal", this, &AamerikeCharacter::MoveHorizontal);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void AamerikeCharacter::MoveForward(float value)
{
	if (IsControllerOk(value))
	{
		rotation = Controller->GetControlRotation();
		yawRotation = FRotator(0.f, rotation.Yaw, 0.f);
		direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(direction, value);
	}
}

void AamerikeCharacter::MoveHorizontal(float value)
{
	if (IsControllerOk(value))
	{
		rotation = Controller->GetControlRotation();
		yawRotation = FRotator(0.f, rotation.Yaw, 0.f);
		direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(direction, value);
	}
}

bool AamerikeCharacter::IsControllerOk(float& value) const
{
	return Controller != nullptr && value != 0.f;
}

