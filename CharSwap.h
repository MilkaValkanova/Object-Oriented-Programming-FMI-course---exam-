#include "Transformation.h"

#pragma once

class CharSwap :public Transformation
{
private:
	 char from;
	 char to;
public:
	CharSwap(char , char);
	~CharSwap(){};
	CharSwap(const CharSwap&)=default;
	CharSwap& operator=(const CharSwap&)=default;

	void Transform(char*&,size_t);
};