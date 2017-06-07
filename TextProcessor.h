#pragma once
#include <fstream>
#include "CharSwap.h"
#include "toCapital.h"
#include "toLow.h"
#include "StringSwap.h"
#include "DynamicArray.hpp"

class TextProcessor
{
	private:
		char* before;
		char* after;
		size_t beforeSize;
		size_t afterSize;
		bool transformationTurn = true;
		DynamicArr<Transformation*> apply;

	public:

		TextProcessor(const TextProcessor&);
		TextProcessor(const char*);
		TextProcessor(const char*, DynamicArr<Transformation*>&);
		TextProcessor& operator=(const TextProcessor&);
		~TextProcessor();

	private:
		void copyFrom(const TextProcessor&);
		void clean();

	public:
		TextProcessor& operator+=(const char*);
		TextProcessor& operator+=(Transformation*);
		TextProcessor& operator-=(size_t);
		void operator-();
		char operator[](size_t)const;
		bool operator==(const TextProcessor&);
		friend std::ostream& operator<<(std::ostream&, const TextProcessor&);
};
