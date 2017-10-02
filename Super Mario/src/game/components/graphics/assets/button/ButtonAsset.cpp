#include "stdafx.h"
#include "ButtonAsset.h"

enum ButtonStates {
	Touched, NotTouched, Pressed, Released
};

ButtonAsset::ButtonAsset(LTexture* texture): Asset(texture)
{
}


ButtonAsset::~ButtonAsset()
{
}




