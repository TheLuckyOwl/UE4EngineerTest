// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ScreenShots.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIREVERIE_CHALLENGE_API UScreenShots : public USceneComponent
{
	GENERATED_BODY()

public:	
	virtual void TakeTheShot();
};
