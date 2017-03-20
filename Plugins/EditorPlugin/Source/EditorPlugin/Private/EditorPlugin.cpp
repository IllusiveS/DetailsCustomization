// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "EditorPlugin.h"
#include "MyActorCustomization.h"
#include "PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "FEditorPluginModule"



void FEditorPluginModule::StartupModule()
{
	auto& PropertyModule = FModuleManager::LoadModuleChecked< FPropertyEditorModule >("PropertyEditor");

	// Register our customization to be used by a class 'UMyClass' or 'AMyClass'. Note the prefix must be dropped.
	PropertyModule.RegisterCustomClassLayout(
		AMyActor::StaticClass()->ClassConfigName,
		FOnGetDetailCustomizationInstance::CreateStatic(&MyActorCustomization::MakeInstance)
	);

	PropertyModule.NotifyCustomizationModuleChanged();
}

void FEditorPluginModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		auto& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

		PropertyModule.UnregisterCustomClassLayout("MyClass");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorPluginModule, EditorPlugin)
