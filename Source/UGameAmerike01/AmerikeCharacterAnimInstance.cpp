// Fill out your copyright notice in the Description page of Project Settings.


#include "AmerikeCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UAmerikeCharacterAnimInstance::UpdateAnimationProperties(float deltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("Characterd started"));
	if (amerikeCharacter == nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Characterd started"));
		amerikeCharacter = Cast<AamerikeCharacter>(TryGetPawnOwner());
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Characterd running"));
		FVector velocity{ amerikeCharacter->GetVelocity() };
		velocity.Z = 0.f;
		speed = velocity.Size();

		bIsInAir = amerikeCharacter->GetCharacterMovement()->IsFalling();

		bIsAccelerating = amerikeCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f;
	}
}
void UAmerikeCharacterAnimInstance::NativeInitializeAnimation()
{
	//UE_LOG(LogTemp, Warning, TEXT("Characterd started"));
	amerikeCharacter = Cast<AamerikeCharacter>(TryGetPawnOwner());
}
