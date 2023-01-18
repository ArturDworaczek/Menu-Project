// Copyright 2019 Artur 'NijoMeisteR' Dworaczek. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "RuntimeInputOverride.generated.h"

UCLASS()
class MENUPROJECT_API URuntimeInputOverride : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/** Set new action key */
	UFUNCTION(BlueprintCallable, Category = "Keybindings")
		static bool SetNewActionKey(FName ActionName, FKey NewKey, FKey OldKey);
	/** Get all of the action keys */
	UFUNCTION(BlueprintPure, Category = "Keybindings")
		static TArray<FInputActionKeyMapping> GetActionKeys();
	/** Get all of the action keys */
	UFUNCTION(BlueprintPure, Category = "Keybindings")
		static FKey GetActionKeyFromName(FName ActionName);
};
