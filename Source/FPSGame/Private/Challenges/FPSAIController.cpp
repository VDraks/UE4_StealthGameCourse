// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAIController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "IFPSGuard.h"

AFPSAIController::AFPSAIController() :
	Guard(nullptr),
	CurrentPointIndex(0)
{
}

void AFPSAIController::BeginPlay()
{
	Super::BeginPlay();
	
	GoToNextPoint();
}

void AFPSAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	Guard = Cast<IFPSGuard>(InPawn);
}

void AFPSAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	
	GoToNextPoint();
}

void AFPSAIController::GoToNextPoint()
{
	if (Guard == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AFPSAIController::GoToNextPoint Guard == nullptr"));
		return;
	}

	if (Guard->GetGuardState() != EAIState::Idle)
	{
		return;
	}
	
	const TArray<AActor*>& Waypoints = Guard->GetWaypoints();
	
	if (Waypoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("AFPSAIController::GoToNextPoint Waypoints is zero"));
		return;
	}
	
	CurrentPointIndex++;
	CurrentPointIndex = CurrentPointIndex % Waypoints.Num();

	UAIBlueprintHelperLibrary::SimpleMoveToActor(this, Waypoints[CurrentPointIndex]);
	// MoveToActor(Waypoints[CurrentPointIndex]); - does not work ???
}
