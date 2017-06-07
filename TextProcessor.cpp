#include "TextProcessor.h"

TextProcessor::TextProcessor(const char* str) : apply()
{
	beforeSize = strlen(str);
	afterSize = beforeSize;
	this->before = new char[beforeSize + 1];
	this->after = new char[beforeSize + 1];
	for (size_t i = 0; i <= beforeSize; i++)
	{
		before[i] = str[i];
		after[i] = str[i];
	}	 
}

TextProcessor& TextProcessor::operator=(const TextProcessor& other)
{
	if (this != &other)
	{
		clean();
		copyFrom(other);
	}
	return *this;
}

TextProcessor::TextProcessor(const char* str, DynamicArr<Transformation*>& transformation) :TextProcessor(str)
{
	apply = transformation;
	for (size_t i = 0; i < apply.getsize(); i++)
	{
		apply[i]->Transform(after, afterSize);
	}
}
TextProcessor::~TextProcessor()
{
	clean();
}

TextProcessor::TextProcessor(const TextProcessor& other)
{
	copyFrom(other);
}

TextProcessor& TextProcessor:: operator+=(const char* str)
{
	size_t len = strlen(str) + beforeSize;
	char* temp = new char[len + 1];
	size_t i,j;
	for ( i = 0; i < beforeSize; i++)
	{
		temp[i] = before[i];
	}
	for (j = 0, i = beforeSize; i < len; i++, j++)
	{
		temp[i] = str[j];
	}

	delete[]before;
	beforeSize = len;
	before = temp;

	afterSize = len;
	delete[]after;

	after = new char[len + 1];
	for (i = 0; i < afterSize; i++)
	{
		after[i] = before[i];
	}

	for (size_t i = 0; i < apply.getsize(); i++)
	{
		apply[i]->Transform(after, afterSize);
	}
	return *this;
}

TextProcessor& TextProcessor::operator+=(Transformation* t)
{
	apply.addEl(t);
	apply[apply.getsize()-1]->Transform(after, afterSize);
	return*this;
}

char TextProcessor:: operator[](size_t idx)const
{
	for (size_t i = 0; i < beforeSize; i++)
	{
		if (i == idx - 1)
		{
		return before[i];
		}
	}
}

std::ostream& operator<<(std::ostream& os, const TextProcessor& object)
{
	if (object.transformationTurn)
	{
		for (size_t i = 0; i < object.afterSize; i++)
		{
			os << object.after[i];
		}
	}

	else
	{
		for (size_t i = 0; i < object.beforeSize; i++)
		{
			os << object.before[i];
		}
	}

	return os;
}

bool TextProcessor::operator==(const TextProcessor& other)
{
	if (this->afterSize != other.afterSize) return false;

	for (size_t i = 0; i < afterSize; i++)
		{
			if (before[i] = !other.before[i])
			{
				return false;
			}
		}
	return true;
}

TextProcessor& TextProcessor::operator-=(size_t idx)
{
	apply.removeEl(idx);
	afterSize = beforeSize;
	for (size_t i = 0; i < afterSize; i++)
	{
		after[i] = before[i];
	}
	for (size_t i = 0; i < apply.getsize(); i++)
	{
		apply[i]->Transform(after, afterSize);
	}
	return*this;
}


void TextProcessor:: operator-()
{
	if(transformationTurn == false) 
	transformationTurn=true;
	else transformationTurn = false;
}


void TextProcessor::copyFrom(const TextProcessor& other)
{
	this->transformationTurn = other.transformationTurn;
	this->beforeSize = other.beforeSize + 1;
	this->before = new char[beforeSize];
	for (size_t i = 0; i < beforeSize; i++)
	{
		this->before[i] = other.before[i];
	}

	this->afterSize = other.afterSize + 1;
	this->after = new char[afterSize];
	for (size_t i = 0; i <afterSize; i++)
	{
		this->after[i] = other.after[i];
	}
	this->apply = other.apply;

}

void TextProcessor::clean()
{
	delete[]before;
	delete[]after;
	beforeSize = 0;
	afterSize = 0;
	transformationTurn = true;
}
