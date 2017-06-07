#include"toLow.h"

bool Lowcase::isCapital(char c)
{
	return (c >= 'A'&&c <= 'Z');
}

void Lowcase::Transform(char*& text, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (isCapital(text[i]))
		{
			text[i] = text[i] - 'A' + 'a';
		}
	}
}