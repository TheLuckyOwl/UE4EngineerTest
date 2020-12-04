// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Misc/Paths.h"
#include "Robot.generated.h"

UCLASS()
class AIREVERIE_CHALLENGE_API ARobot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARobot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Takes Screenshots everytick and looks for the actors inside.
	virtual void TakeTheShot();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class URobotMovement* CustomMovementComponent;
	
	//Movement Component
	virtual UPawnMovementComponent* GetMovementComponent() const override;

protected:
	//ForNamingFiles
	int currentNumber = 0;
	//For File Path 
	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString filePath = FPaths::ProjectSavedDir() + FString("Data/");
};
