// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"
#include "MainHUD.h"

AMyGameModeBase::AMyGameModeBase()
{
	HUDClass = AMainHUD::StaticClass();
	DefaultPawnClass = AMyCharacter::StaticClass();
}
