#include "BMP.h"
#include "RGB.h"
#include <iostream>
#include <fstream>
#include "Header.h"


using namespace std;


int BMP::Tcode(int byte)
{

	int copy_mask = File_INFO.S_Mask;
	int	mask_shift = 0;

	while (!(copy_mask & 1)) {
		copy_mask >>= 1;
		mask_shift++;
	}

	return (byte & File_INFO.S_Mask) >> mask_shift;
}



BMP::BMP(char* _way_)
{
	ifstream file_image(_way_, ios_base::binary);

	file_image.seekg(14);
	file_image.read((char*)&File_INFO.Size, sizeof(File_INFO.Size));
	file_image.read((char*)&File_INFO.Width, sizeof(File_INFO.Width));
	file_image.read((char*)&File_INFO.Height, sizeof(File_INFO.Height));

	File_INFO.Count_of_Canals = 3;
	File_INFO.Bits_on_Color = 8;
	File_INFO.S_Mask = 255;

	file_image.seekg(54);

	Max_size_Massage = (3 * File_INFO.Width*File_INFO.Height)/8;

	pixels = new RGB *[File_INFO.Height];
	for (int i = 0; i < File_INFO.Height; i++)
		pixels[i] = new RGB[File_INFO.Width];


	int line_Padding = ((fileInfoHeader.biWidth * (fileInfoHeader.biBitCount / 8)) % 4) & 3;

	int code;


	for (int i = 0; i < File_INFO.Height; i++)
	{
		for (int j = 0; j < File_INFO.Width; j++)
		{
			file_image.read((char*)&code, 1);
			pixels[i][j].c_B = Tcode(code);
			file_image.read((char*)&code, 1);
			pixels[i][j].c_G = Tcode(code);
			file_image.read((char*)&code, 1);
			pixels[i][j].c_R = Tcode(code);

		}
		file_image.seekg(line_Padding, ios::cur);
	}

	file_image.close();


}

void BMP::get_info() const
{
	cout << "________________________________________________________________________________" << endl;
	cout << "                                |    INFO   |                                   " << endl;
	cout << "________________________________|___________|___________________________________" << endl;

	cout << "Size: " << File_INFO.Size << endl;
	cout << "Height: " << File_INFO.Height << endl;
	cout << "Width: " << File_INFO.Width << endl;
	cout << "Canals on a pixel: " << File_INFO.Count_of_Canals << endl;
	cout << "Bits on a color: " << File_INFO.Bits_on_Color << endl;
	cout << "Max size of text message: " << Max_size_Massage << endl;

	cout << "________________________________|___________|___________________________________" << endl;

	cout << "PIXELS: \n\n";
	for (int i = 0; i < File_INFO.Height; i++)
	{
		for (int j = 0; j < File_INFO.Width; j++)
		{
			cout << pixels[i][j].c_R << "  " << pixels[i][j].c_G << "  " << pixels[i][j].c_B << "  " << endl;

		}
		cout << "_____________________" << endl;
	}
}


void coding_massage(char* _massage_)
{

}


BMP::~BMP()
{
	for (int i = 0; i<File_INFO.Height; i++)
		delete[] pixels[i];
	delete[] pixels;

}



