// Copyright Epic Games, Inc. All Rights Reserved.


#include "AssignmentGameModeBase.h"

#include "Kismet/GameplayStatics.h"

AAssignmentGameModeBase::AAssignmentGameModeBase()
{
}

void AAssignmentGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	points = 0;
	UE_LOG(LogTemp, Warning, TEXT("Shoot amount: %d"), points);
}

void AAssignmentGameModeBase::Win()
{
	UGameplayStatics::OpenLevel(GetWorld(), "WinLevel");
}

void AAssignmentGameModeBase::End()
{
	UGameplayStatics::OpenLevel(GetWorld(), "EndLevel");
}

void AAssignmentGameModeBase::AddScore()
{
	points++;
	UE_LOG(LogTemp, Warning, TEXT("Shoot amount: %d"), points);
	if (points == 10)
	{
		Win();
	}
}

int AAssignmentGameModeBase::GetPoints()
{
	return points;
}
