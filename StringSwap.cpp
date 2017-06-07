#include "StringSwap.h"

StringSwap::StringSwap(char* from, char* to)
{
	this->fromsize = strlen(from) + 1;
	this->from = new char[fromsize];
	for (size_t i = 0; i < fromsize; i++)
	{
		this->from[i] = from[i];
	}

	this->tosize = strlen(to) + 1;
	this->to = new char[tosize];
	for (size_t i = 0; i <tosize; i++)
	{
		this->to[i] = to[i];
	}
}

StringSwap::StringSwap(const StringSwap& other)
{
	copyFrom(other);
}
StringSwap::~StringSwap()
{
	clear();
}
StringSwap& StringSwap:: operator=(const StringSwap& other)
{
	if (this != &other)
	{
	clear();
	copyFrom(other);
	}
	return *this;
}

void StringSwap::copyFrom(const StringSwap& other)
{
	this->fromsize = other.fromsize + 1;
	this->from = new char[fromsize];
	for (size_t i = 0; i < fromsize; i++)
	{
		this->from[i] = other.from[i];
	}

	this->tosize = other.tosize + 1;
	this->to = new char[tosize];
	for (size_t i = 0; i <tosize; i++)
	{
		this->to[i] = other.to[i];
	}
}

void StringSwap::clear()
{
	delete[]from;
	delete[]to;
	fromsize = 0;
	tosize = 0;
}

void StringSwap::Transform(char*& text, size_t size)
{
	size_t cnt = count(text, size);
	size_t len = size + cnt*(tosize - fromsize);
	char* temp = new char[len + 1];
	size_t j = 0, i = 0, k = 0;
	for (; i < len; i++)
	{			
		if (text[i] == from[0] && findString(text + i,  size))
		{
			for (k = 0; k < tosize; k++)
			{
				temp[j] = to[k];
				j++;
			}
			i += fromsize - 1;
		}
		else
		{
			temp[j] = text[i];
			j++;
		}

	}

	text = temp;
}




bool StringSwap::findString(char* text, size_t textSize)const
{
	size_t j = 0, i;
	for (i = 0; i < textSize; i++)
	{
		if (text[i] == from[0]){
			for (; j < fromsize; j++)
			{
				if (text[i + j] != from[j])
					return false;
			}
		}
	}
	if (j == 0 && i == textSize) return false;
	else return true;
}
size_t StringSwap::count(char* text, size_t textSize)const
{
	size_t j = 0, i = 0;
	while (*text)
	{
		if (findString(text + i,  textSize))
		{
			j++;
			text += fromsize;
		}
		else text++;
	}
	return j;
}