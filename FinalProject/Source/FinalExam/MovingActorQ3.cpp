// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingActorQ3.h"


// Sets default values
AMovingActorQ3::AMovingActorQ3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingActorQ3::BeginPlay()
{
	Super::BeginPlay();
	Start = GetActorLocation();
	End.X = Start.X + 800;
	End.Y = Start.Y + 800;
	End.Z = Start.Z + 800;
	Distance = 5;
	Counter = 0;

	
}

// Called every frame
void AMovingActorQ3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();
	if (Location.X > End.X || Location.Y > End.Y || Location.Z > End.Z){
		Distance = -Distance;
}
	if (Location.X < Start.X && (Location.Y < Start.Y || Location.Z < Start.Z)) {
		Distance = -Distance;
		if (Counter < 2)
			Counter = Counter + 1;
		else
			Counter = 0;
	}
	if (Counter == 0) {
		Location.X += Distance;
		Location.Z += Distance;
	}
	if (Counter == 1) {
	Location.Y += Distance;
	Location.Z += Distance;
	}
	if (Counter == 2) {
	Location.X += Distance;
	Location.Y += Distance;
	Location.Z += Distance;
	}


	SetActorLocation(Location);
}

