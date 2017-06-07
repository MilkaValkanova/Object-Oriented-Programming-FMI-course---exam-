#pragma once
#include "Transformation.h"


class StringSwap :public Transformation
{
	private:
		char* from;
		char* to;
		size_t fromsize;
		size_t tosize;

	public:
		StringSwap(char*, char*);
		~StringSwap();
		StringSwap(const StringSwap&);
		StringSwap& operator=(const StringSwap&);
	
		void Transform(char*&, size_t);

	private:
		void copyFrom(const StringSwap&);
		void clear();
		size_t count(char*,size_t)const;// how many times from is in text
		bool findString(char*,size_t)const;//find from in text
};