// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"
#include "RotatingActor.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DummyRoot = CreateDefaultSubobject<USceneComponent>("DummyRoot");
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");

	RootComponent = DummyRoot;
	MeshComponent->SetupAttachment(DummyRoot);
}

void AInteractableActor::InteractWith()
{
	if (RotatingActor)
	{
		if (bOpen)
		{
			RotatingActor->Open();
		}
		else
		{
			RotatingActor->Close();
		}
		bOpen = !bOpen;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("You didn't select a rotating actor for %s"), *GetName())
	}
}