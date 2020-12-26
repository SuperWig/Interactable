#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class INTERACTABLE_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

	void Open();
	void Close();

	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY()
	USceneComponent* DummyRoot;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	FRotator TargetRot;
	UPROPERTY(EditAnywhere)
	float RotateSpeed = 1.f;
	bool bShouldOpen = false;
};
