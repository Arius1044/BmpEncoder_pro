#include <iostream>
#include <fstream>
#include <iostream>
#include "BMP.h"

using namespace std;



int main()
{
	BMP image("tiger1.bmp");
	image.DeCoder();

	cout << int('I') << endl;
	cout << int(' ')<<endl;
	cout << int('l')<<endl;
	cout << int('o') << endl;
	cout << int('v') << endl;
	cout << int('e') << endl;
	image.get_info();
	image.Coder("I love you baby~", "tiger1.bmp");
	system("pause");
	return 0;
}
