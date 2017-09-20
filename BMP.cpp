#include "BMP.h"
#include "RGB.h"
#include <iostream>
#include <fstream>

using namespace std;

BMP::BMP(char* _way_)
{
	ifstream file_image(_way_);

	file_image.seekg(18); file_image.read((char*)&width, sizeof(int));
	file_image.seekg(22); file_image.read((char*)&heigh, sizeof(int));
	file_image.seekg(28); file_image.read((char*)&bit_on_pix, sizeof(short));
	count_of_pixels = width*heigh;
	file_image.seekg(54);
	

	pixels = new RGB[count_of_pixels];

	for (long long i = 0; i < count_of_pixels; i++)
	{
		file_image.read((char*)&pixels[i].c_R, sizeof(int));
		file_image.read((char*)&pixels[i].c_G, sizeof(int));
		file_image.read((char*)&pixels[i].c_B, sizeof(int));
	}
	file_image.close();
}

void BMP::get_info() const
{
	cout << width << "\n";
	cout << heigh << "\n";
	cout << count_of_pixels<<"\n";
	cout << bit_on_pix << "\n";
	cout << pixels[0].c_R << "  " << pixels[0].c_G << "  " << pixels[0].c_B;
}

BMP::~BMP()
{

}
