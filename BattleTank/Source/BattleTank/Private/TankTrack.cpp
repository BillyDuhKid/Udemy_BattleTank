// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	// BUG FIX: Mesh Disappearing
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Tank/tank_fbx_Track.tank_fbx_Track"));
	if (staticMesh.Object != nullptr){SetStaticMesh(staticMesh.Object);}
}

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	// TODO: clamp actual throttle value so player can't overdrive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
