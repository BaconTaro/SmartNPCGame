// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SmartNPC_v1HUD.generated.h"

UCLASS()
class ASmartNPC_v1HUD : public AHUD
{
	GENERATED_BODY()

public:
	ASmartNPC_v1HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

