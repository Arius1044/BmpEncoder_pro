#pragma once
#include <fstream>
#include "RGB.h"
#include "Header.h"
class BMP
{
private:

	char* Massage;
	unsigned int Max_size_Massage;
	BMPINFO File_INFO;
	RGB **pixels;

	int Tcode(int byte);

public:
	BMP(char* _way_);
	~BMP();
	void get_info() const;
	void DeCoder();
	void Coder(char* _massage_);
	void Shifrator();


};
