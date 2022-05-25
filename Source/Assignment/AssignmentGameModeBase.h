// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AssignmentGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API AAssignmentGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	UFUNCTION()
		void Win();
	
	UPROPERTY()
		int points;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	
	AAssignmentGameModeBase();
	
	UFUNCTION()
		void End();

	UFUNCTION()
		void AddScore();
	
	UFUNCTION()
		int GetPoints();
};
