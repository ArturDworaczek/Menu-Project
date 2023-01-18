// Copyright 2019 Artur 'NijoMeisteR' Dworaczek. All Rights Reserved.

#include "RuntimeInputOverride.h"
#include "GameFramework/InputSettings.h"
#include "Engine.h"

// Set new action key
bool URuntimeInputOverride::SetNewActionKey(FName ActionName, FKey NewKey, FKey OldKey) {
	// Get Input Settings
	UInputSettings* Settings = UInputSettings::StaticClass()->GetDefaultObject<UInputSettings>();
	if (!Settings) { return false; }

	for (int8 Index = 0; Index < Settings->GetActionMappings().Num(); Index++)
	{
		if (Settings->GetActionMappings()[Index].Key == NewKey) {
			return false;
		}
	}

	// Remove Previous Binding
	FInputActionKeyMapping OldInput(ActionName, OldKey, false, false, false, false);
	Settings->RemoveActionMapping(OldInput);

	// Use New Binding
	FInputActionKeyMapping NewInput(ActionName, NewKey, false, false, false, false);
	Settings->AddActionMapping(NewInput);

	return true;
}
// Get all of the action keys
TArray<FInputActionKeyMapping> URuntimeInputOverride::GetActionKeys() {
	// Get Input Settings
	UInputSettings* Settings = UInputSettings::StaticClass()->GetDefaultObject<UInputSettings>();

	return Settings->GetActionMappings();
}
// Gets key from the action name
FKey URuntimeInputOverride::GetActionKeyFromName(FName ActionName) {
	// Get Input Settings
	UInputSettings* Settings = UInputSettings::StaticClass()->GetDefaultObject<UInputSettings>();

	TArray<FInputActionKeyMapping> ActionKeys;

	if (Settings) {
		Settings->GetActionMappingByName(ActionName, ActionKeys);
	}

	return ActionKeys[0].Key;
}