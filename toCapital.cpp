#include"toCapital.h"

bool Capital::isLowcase(char c)
{
	return (c >= 'a'&&c <= 'z');
}

void Capital::Transform(char*& text, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (isLowcase(text[i]))
		{
			text[i] = text[i] + 'A' - 'a';
		}
	}
}