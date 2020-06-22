// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "TankTrack.h"
#include "..\Public\TankTrack.h"

//StaticMesh'/Game/Tank/tank_fbx_Track.tank_fbx_Track'

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

//	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Tank/tank_fbx_Track.tank_fbx_Track'"));
//	if (MeshAsset.Object != nullptr)
//	{
	//	SetStaticMesh(MeshAsset.Object);
//	}
}


void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	// TODO: clamp actual throttle value so player can't overdrive
}

