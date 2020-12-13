// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MouseEventManager.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = 1;
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MouseClick", IE_Pressed, this, &AMyCharacter::OnMousePressed);
	PlayerInputComponent->BindAction("MouseClick", IE_Released, this, &AMyCharacter::OnMouseReleased);
}

void AMyCharacter::OnMousePressed()
{
	FVector2D mousePosition;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(mousePosition.X, mousePosition.Y);
	MouseEventManager::Get()->mouseButtonDownEvent.Broadcast(mousePosition);
}

void AMyCharacter::OnMouseReleased()
{
	FVector2D mousePosition;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(mousePosition.X, mousePosition.Y);
	MouseEventManager::Get()->mouseButtonReleaseEvent.Broadcast(mousePosition);
}