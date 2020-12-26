#include "BasicCharacter.h"
#include "InteractableActor.h"

void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ABasicCharacter::MoveForward);
	PlayerInputComponent->BindAxis("StrafeRight", this, &ABasicCharacter::StrafeRight);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ABasicCharacter::Interact);
}

void ABasicCharacter::MoveForward(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ABasicCharacter::StrafeRight(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ABasicCharacter::Interact()
{
	FVector Start;
	FRotator Direction;
	GetController()->GetPlayerViewPoint(Start, Direction);

	const FVector End = Start + Direction.Vector() * Reach;

	FHitResult Hit;
	FCollisionQueryParams Params(NAME_None, false, this);
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Camera, Params);

	AInteractableActor* Interactable = Cast<AInteractableActor>(Hit.GetActor());
	if (Interactable)
	{
		Interactable->InteractWith();
	}
}
