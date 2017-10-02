#pragma once
#include <game\components\graphics\assets\Asset.h>

class ButtonAsset: public Asset
{
public:
	ButtonAsset(LTexture* texture);
	~ButtonAsset();
public:
	virtual bool init() = 0;
};

