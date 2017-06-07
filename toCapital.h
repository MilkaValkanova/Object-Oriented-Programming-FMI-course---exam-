#include "Transformation.h"
#pragma once

class Capital :public Transformation
{
	public:
		Capital() = default;
		Capital(const Capital&) = default;
		Capital& operator=(const Capital&)=default;
		~Capital(){};

		void Transform(char*&, size_t size);

	private:
		bool isLowcase(char);
};