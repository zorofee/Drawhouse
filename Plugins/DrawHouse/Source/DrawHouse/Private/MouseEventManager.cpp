// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseEventManager.h"

MouseEventManager::MouseEventManager()
{

}

MouseEventManager* MouseEventManager::instance = new MouseEventManager();

MouseEventManager* MouseEventManager::Get()
{

	return instance;
}

