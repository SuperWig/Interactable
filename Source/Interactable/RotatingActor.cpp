#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	DummyRoot = CreateDefaultSubobject<USceneComponent>("Dummy");
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");

	RootComponent = DummyRoot;
	MeshComponent->SetupAttachment(DummyRoot);
}

void ARotatingActor::Open()
{
	bShouldOpen = true;
}

void ARotatingActor::Close()
{
	bShouldOpen = false;
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotation;
	if (bShouldOpen)
	{
		Rotation = FMath::RInterpTo(MeshComponent->GetRelativeRotation(), TargetRot, DeltaTime, RotateSpeed);
	}
	else
	{
		Rotation = FMath::RInterpTo(MeshComponent->GetRelativeRotation(), FRotator(0), DeltaTime, RotateSpeed);
	}
	MeshComponent->SetRelativeRotation(Rotation);
}
