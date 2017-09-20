#include <iostream>
#include <fstream>
#include <iostream>
#include "BMP.h"

using namespace std;



int main()
{
	BMP image("tiger.bmp");
	image.get_info();
	system("pause");
	return 0;
}
