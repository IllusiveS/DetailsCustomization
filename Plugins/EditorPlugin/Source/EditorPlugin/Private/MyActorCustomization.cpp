// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPlugin.h"
#include "MyActorCustomization.h"
#include "MyActor.h" // The class we're customizing
#include "PropertyEditing.h"
#include "STextBlock.h"

#define LOCTEXT_NAMESPACE "MyEditorModule"

DEFINE_LOG_CATEGORY_STATIC(EditorPluginLog, All, All)

TSharedRef< IDetailCustomization > MyActorCustomization::MakeInstance()
{
	return MakeShareable(new MyActorCustomization);
}

void MyActorCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{

	UE_LOG(EditorPluginLog, Warning, TEXT("Displaying details"));

	//TSharedRef< IPropertyHandle > Prop = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(AMyActor, BaseString));

	IDetailCategoryBuilder& Cat = DetailBuilder.EditCategory(TEXT("CatName"));

	TArray< TWeakObjectPtr< UObject > > Objects;
	DetailBuilder.GetObjectsBeingCustomized(Objects);

	TWeakObjectPtr< AMyActor > MyObject = Cast< AMyActor >(Objects[0].Get());

	auto OnGetWarningVisibility = [MyObject]
	{
		return MyObject.IsValid() && MyObject->Show ? EVisibility::Visible : EVisibility::Collapsed;
	};
	auto WarningVisibilityAttr = TAttribute< EVisibility >::Create(TAttribute< EVisibility >::FGetter::CreateLambda(OnGetWarningVisibility));

	Cat.AddCustomRow(LOCTEXT("MyWarningRowFilterString", "Search Filter Keywords"))
		.Visibility(WarningVisibilityAttr)
		.WholeRowContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("MyWarningTest", "BaseString should not be empty!"))
		];
	//DetailBuilder.ForceRefreshDetails();
}

#undef LOCTEXT_NAMESPACE