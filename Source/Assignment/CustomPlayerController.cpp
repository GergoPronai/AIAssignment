// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	gameModeBase = (AAssignmentGameModeBase*)GetWorld()->GetAuthGameMode();
	_player = Cast<AMyCharacter>(GetCharacter());
	
	UUserWidget* hud = CreateWidget(this, hudClass);
	UGameplayStatics::PlaySound2D(GetWorld(), sound, 1.0f, 1.3f, 0.0f);
	if(hud != nullptr)
	{
		hud->AddToViewport();
	}
}

int ACustomPlayerController::GetPoints()
{
	return gameModeBase->GetPoints();
}

float ACustomPlayerController::GetHealth()
{
	if(_player)
	{
		return _player->GetHealth() / maxHealth;
	}
	return 100.0f / maxHealth;
}

