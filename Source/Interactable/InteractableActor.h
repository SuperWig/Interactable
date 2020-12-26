// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS()
class INTERACTABLE_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();
	void InteractWith();
	
private:
	UPROPERTY()
	USceneComponent* DummyRoot;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditInstanceOnly)
	class ARotatingActor* RotatingActor;
	bool bOpen = true;
};
