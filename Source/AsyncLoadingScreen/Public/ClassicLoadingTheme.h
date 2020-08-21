/********************************************************************************** 
 * 
 * Copyright (C) 2020 Truong Bui. 
 * Website:	https://github.com/truong-bui/AsyncLoadingScreen 
 * Licensed under the MIT License. See 'LICENSE' file for full license information. 
 *  
 **********************************************************************************/

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "LoadingScreenSettings.h"
class FDeferredCleanupSlateBrush;

/**
 * Classic loading screen theme
 */
class SClassicLoadingTheme : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SClassicLoadingTheme) {}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, const FALoadingScreenSettings& ScreenDescription);

	static float PointSizeToSlateUnits(float PointSize)
	{
		const float SlateFreeTypeHorizontalResolutionDPI = 96.0f;
		const float FreeTypeNativeDPI = 72.0;
		const float PixelSize = PointSize * (SlateFreeTypeHorizontalResolutionDPI / FreeTypeNativeDPI);
		return PixelSize;
	}

	EActiveTimerReturnType Foo(double InCurrentTime, float InDeltaTime);

	void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
private:
	float GetDPIScale() const;

private:
	bool bIsActiveTimerRegistered;
	TSharedPtr<FDeferredCleanupSlateBrush> LoadingThemeBrush;	
	float CurrentDeltaTime = 0.0f;
	TSharedPtr<SImage> IconImage;
	FALoadingScreenSettings InScreenDescription;
	int32 IconIndex;
};
