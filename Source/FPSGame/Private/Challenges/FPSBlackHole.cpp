// Fill out your copyright notice in the Description page of Project Settings.

#include "Challenges/FPSBlackHole.h"

#include "Components/SphereComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AFPSBlackHole::AFPSBlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereC"));
	SphereComp->SetupAttachment(MeshComp);

	ForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("Force"));
	ForceComp->ImpulseStrength = -100000;
	ForceComp->Radius = 100000;
	ForceComp->SetupAttachment(MeshComp);
}

// Called every frame
void AFPSBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ForceComp->FireImpulse();
}

inline void AFPSBlackHole::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	OtherActor->Destroy();
}