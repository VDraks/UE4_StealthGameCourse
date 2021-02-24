// Fill out your copyright notice in the Description page of Project Settings.


#include "Challenges/FPSLaunchPad.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetBoxExtent(FVector(75.f, 75.f, 50.f));
	RootComponent = OverlapComp;
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::HandleOverlap);
}

inline void AFPSLaunchPad::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::SpawnEmitterAtLocation(this, EnterFX, GetActorLocation());

	const FVector FinalVelocity = GetActorRotation().RotateVector(FVector(500.f, 0.f, 1000.f));

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{		
		Character->LaunchCharacter(FinalVelocity, true, true);
	}
	else if (OtherComp && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->SetPhysicsLinearVelocity(FinalVelocity);
	}
}

