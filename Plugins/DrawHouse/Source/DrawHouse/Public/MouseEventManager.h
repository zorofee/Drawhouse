// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_EVENT_OneParam(MouseEventManager, MouseButtonDownEvent, const FVector2D&);
DECLARE_EVENT_OneParam(MouseEventManager, MouseButtonReleaseEvent, const FVector2D&);

/**
 * 
 */
class DRAWHOUSE_API MouseEventManager
{
private:
	MouseEventManager();

public:
	static MouseEventManager* Get();

private:
	static MouseEventManager* instance;

public:
	MouseButtonDownEvent mouseButtonDownEvent;

	MouseButtonReleaseEvent mouseButtonReleaseEvent;
};
