// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapon/Weapon.h"
#include "Characters/SlashCharacter.h"

void AWeapon::Equip(USceneComponent* InParent, FName InSocket)
{
	if (InParent) {

		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, false);

		ItemMesh->AttachToComponent(InParent, TransformRules, InSocket);
	}
}


void AWeapon::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	ASlashCharacter* Slashcharacter = Cast<ASlashCharacter>(OtherActor);
	if (Slashcharacter) {
		Slashcharacter->SetOverlappingItem(this);
	}
}

void AWeapon::OnSphereOverLapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereOverLapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	ASlashCharacter* Slashcharacter = Cast<ASlashCharacter>(OtherActor);
	if (Slashcharacter) {
		Slashcharacter->SetOverlappingItem(nullptr);
	}
}
