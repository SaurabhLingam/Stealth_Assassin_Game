// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAssassinCharacter.h"

// Sets default values
AMainAssassinCharacter::AMainAssassinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainAssassinCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainAssassinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainAssassinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainAssassinCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainAssassinCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Stab"), EInputEvent::IE_Pressed, this, &AMainAssassinCharacter::Stab);
	PlayerInputComponent->BindAction(TEXT("FastWalk"), EInputEvent::IE_Pressed, this, &AMainAssassinCharacter::FastWalk);

}

void AMainAssassinCharacter::MoveForward(float AxisValue)
{
	
	AddMovementInput(GetActorForwardVector() * AxisValue);
}
void AMainAssassinCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AMainAssassinCharacter::Stab()
{
	UE_LOG(LogTemp, Warning, TEXT("stabbed..."));
}

void AMainAssassinCharacter::FastWalk()
{
	UE_LOG(LogTemp,Warning, TEXT("Walking Faster..."));
}