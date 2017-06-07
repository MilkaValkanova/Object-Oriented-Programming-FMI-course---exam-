#pragma once
#include <iostream>
class Transformation
{

	public: 
		virtual  ~Transformation(){};
		virtual void Transform(char*&, size_t) = 0;
};
