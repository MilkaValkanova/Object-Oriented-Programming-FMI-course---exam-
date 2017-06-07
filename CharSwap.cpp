#include "CharSwap.h"

CharSwap::CharSwap(char from, char to) 
:from(from), to(to){};

void CharSwap::Transform(char*& text, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (text[i] == from)
		{
			text[i] = to;
		}
	}
}
