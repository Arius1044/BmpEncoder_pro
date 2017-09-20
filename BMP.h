#pragma once
#include <fstream>
#include "RGB.h"
#include "Header.h"
class BMP
{
private:
	BMPINFO File_INFO;
	RGB **pixels;

	 int Tcode(int byte);

public:
	BMP(char* _way_);
	~BMP();
	void get_info() const;

};