// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class DETAILSCUSTOMIZATION_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = "Cat A")
		FString BaseString;

	UPROPERTY(EditAnywhere, Category = "Cat A")
		int32 Count;

	UPROPERTY(VisibleAnywhere, Category = "Cat B")
		TArray<FString> GeneratedList;

	UPROPERTY(EditAnywhere, Category = "Cat B")
		bool Show;
	
};
