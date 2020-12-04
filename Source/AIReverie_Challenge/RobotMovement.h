// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "RobotMovement.generated.h"

/**
 * 
 */
UCLASS()
class AIREVERIE_CHALLENGE_API URobotMovement : public UPawnMovementComponent
{
	GENERATED_BODY()

public:
	virtual void Move(float DeltaTime);

private:
	float Timer = 0.0f;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool moved = false;
};
