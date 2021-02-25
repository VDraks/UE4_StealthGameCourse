#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "IFPSGuard.generated.h"

UENUM(BlueprintType)
enum class EAIState : uint8
{
	Idle,
    Suspicious,
    Alerted
};

UINTERFACE()
class FPSGAME_API UFPSGuard : public UInterface
{
	GENERATED_BODY()
};

class FPSGAME_API IFPSGuard
{
	GENERATED_IINTERFACE_BODY()

	virtual const TArray<AActor*>& GetWaypoints() = 0;

	virtual EAIState GetGuardState() = 0;
};
