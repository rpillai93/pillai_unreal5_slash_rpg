#pragma once
#include "DrawDebugHelpers.h"

#define PRINT_DEBUG_MESSAGE(Message, Args) if(GEngine) GEngine->AddOnScreenDebugMessage(0, 60.f, FColor::Cyan, FString::Printf(TEXT(Message),Args));
#define LOG_DEBUG_MESSAGE(Message, Args) UE_LOG(LogTemp, Warning, TEXT(Message), Args);
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);
#define DRAW_SPHERE_NOT_PERSISTENT(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);
#define DRAW_LINE(StartLocation, EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_LINE_NOT_PERSISTENT(StartLocation, EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 10.f);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 10.0f, FColor::Red, true);
#define DRAW_POINT_NOT_PERSISTENT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 10.0f, FColor::Red, false,-1.f);
#define DRAW_VECTOR(StartLocation,EndLocation) if(GetWorld()) \
   { \
	   DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true); \
       DrawDebugPoint(GetWorld(), EndLocation, 10.0f, FColor::Red, true); \
   }
#define DRAW_VECTOR_NOT_PERSISTENT(StartLocation,EndLocation) if(GetWorld()) \
   { \
	   DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false,-1.f, 0, 1.f); \
       DrawDebugPoint(GetWorld(), EndLocation, 10.0f, FColor::Red, false, -1.f); \
   }