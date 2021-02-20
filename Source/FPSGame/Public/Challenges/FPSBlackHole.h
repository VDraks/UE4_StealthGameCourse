// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FPSBlackHole.generated.h"

class URadialForceComponent;
class USphereComponent;

UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFPSBlackHole();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ForceComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
