#include "Transformation.h"
#pragma once

class Lowcase :public Transformation
{
	public:
		Lowcase() = default;
		Lowcase(const Lowcase&) = default;
		Lowcase& operator=(const Lowcase&) = default;
		~Lowcase(){};
		void Transform(char*&, size_t);

	private:
		bool isCapital(char);
};