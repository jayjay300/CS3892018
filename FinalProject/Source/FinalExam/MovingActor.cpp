// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingActor.h"


AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	Start = GetActorLocation();
	End.X = Start.X + 1000;
	Distance = 5;
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	if (Location.X > End.X)
		Distance = -Distance;
	if (Location.X < Start.X)
		Distance = -Distance;
	Location.X += Distance;
	SetActorLocation(Location);
}


