#pragma once
#include <fstream>
#include "RGB.h"
class BMP
{
private:
	long width;
	long heigh;
	short bit_on_pix;
	long long count_of_pixels;
	RGB *pixels;

public:
	BMP(char* _way_);
	~BMP();
	void get_info() const;

};