// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasicCharacter.generated.h"

UCLASS()
class INTERACTABLE_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void StrafeRight(float Value);
	void Interact();
	UPROPERTY(EditAnywhere)
	float Reach = 300.f;
};