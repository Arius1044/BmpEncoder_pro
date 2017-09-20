#include "BMP.h"
#include "RGB.h"
#include <iostream>
#include <fstream>
#include "Header.h"
<<<<<<< HEAD
using namespace std;


=======

using namespace std;

>>>>>>> 7f84c35058ad61a68527de9a9813a7098c7bd3e2
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

<<<<<<< HEAD

BMP::BMP(char* _way_)
{
	ifstream file_image(_way_, ios_base::binary);

=======
BMP::BMP(char* _way_)
{
>>>>>>> 7f84c35058ad61a68527de9a9813a7098c7bd3e2
	file_image.seekg(14);
	file_image.read((char*)&File_INFO.Size, sizeof(File_INFO.Size));
	file_image.read((char*)&File_INFO.Width, sizeof(File_INFO.Width));
	file_image.read((char*)&File_INFO.Height, sizeof(File_INFO.Height));

	File_INFO.Count_of_Canals = 3;
	File_INFO.Bits_on_Color = 8;
	File_INFO.S_Mask = 255;

	file_image.seekg(54);


	pixels = new RGB *[File_INFO.Height];
	for (int i = 0; i < File_INFO.Height; i++)
		pixels[i] = new RGB[File_INFO.Width];


	int linePadding = 2;

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
		file_image.seekg(linePadding, ios::cur);
	}
	
	file_image.close();

	
}

void BMP::get_info() const
{
<<<<<<< HEAD

=======
>>>>>>> 7f84c35058ad61a68527de9a9813a7098c7bd3e2
	cout << "________________________________________________________________________________" << endl;
	cout << "                                |    INFO   |                                   " << endl;
	cout << "________________________________|___________|___________________________________" << endl;

	cout << "Size: " << File_INFO.Size << endl;
	cout << "Height: " << File_INFO.Height << endl;
	cout << "Width: " << File_INFO.Width << endl;
	cout << "Canals on a pixel: " << File_INFO.Count_of_Canals << endl;
	cout << "Bits on a color: " << File_INFO.Bits_on_Color<<endl;

	cout << "________________________________|___________|___________________________________" << endl;

	cout << "PIXELS: \n\n";
	for (int i = 0; i <  File_INFO.Height; i++)
	{
			for (int j = 0; j < File_INFO.Width; j++)
			{
				cout << pixels[i][j].c_R << "  " << pixels[i][j].c_G << "  " << pixels[i][j].c_B << "  " << endl;
			
	        }
			cout <<"_____________________"<< endl;
	}
}

BMP::~BMP()
{
<<<<<<< HEAD
	for (int i=0; i<File_INFO.Height; i++)
	    delete[] pixels[i];
	delete[] pixels;

}
=======
        for (int i=0; i<File_INFO.Height; i++)
	    delete[] pixels[i];
	delete[] pixels;
}
>>>>>>> 7f84c35058ad61a68527de9a9813a7098c7bd3e2
