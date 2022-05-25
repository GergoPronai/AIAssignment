// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "AssignmentGameModeBase.h"
#include "Bullet.h"
#include "GameFramework/Character.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacter.generated.h"

UCLASS()
class ASSIGNMENT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	
private:
	UPROPERTY()
		AAssignmentGameModeBase* gameModeBase;

	UPROPERTY()
		FTimerHandle timer;

	UPROPERTY()
		float fEndCounter;
	
	UPROPERTY()
		float health;
	
	UPROPERTY(EditAnywhere)
		int score;
	
	UPROPERTY(EditAnywhere)
		float castRange;
	
	UPROPERTY(VisibleAnywhere)
		USceneComponent* bulletSpawnPoint;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABullet> bulletClass;
	
	UPROPERTY(VisibleAnywhere)
		FVector deltaLocation;

	UPROPERTY(VisibleAnywhere)
		FQuat deltaRotation;

	UPROPERTY()
		float moveSpeed;

	UPROPERTY()
		float rotateSpeed;

	UPROPERTY()
		float damage;
	
	UPROPERTY(EditAnywhere)
		bool bIsPlayer;
	
	UPROPERTY()
		bool bIsHit;
	
	UFUNCTION()
		void MoveForward(float value);

	UFUNCTION()
		void Strafe(float value);
	
	UFUNCTION()
		void LookUp(float value);

	UFUNCTION()
		void Turn(float value);

	bool GetIsPlayer();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void Shooting();

	UFUNCTION()
		float GetHealth();

private:
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
};
