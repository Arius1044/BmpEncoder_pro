#include <iostream>
#include <fstream>
#include <iostream>
#include "BMP.h"

using namespace std;



int main()
{
	char* way = new char[20];
	char* massage = new char[1000];

	cout << "\nEnter way to file: "; gets_s(way, 20);

	BMP image(way);

	int menu;
	cout << "\n\n\n";
	cout << "______________________________________________________________________________" << endl;
	cout << "                               |    Menu   |                                  " << endl;
	cout << "_______________________________|___________|__________________________________" << endl;
	cout << "1) Show_info;\n2) Decoding\n3) Coding\n4) Exit.\n\n\n";

	do
	{
		cout << "\n\nEnter number of menu: ";
		cin >> menu;
		switch (menu)
		{
		case 1: image.get_light_info(); break;
		case 2:
		{
			image.DeCoder();
			cout << "\n\nMassage: \n";
			image.PrintMassage();
		};
		break;
		case 3:
		{
			cout << "\n\nEnter Massage: \n"; cin >> massage;
			image.Coder(massage, way);
		};
		break;
		case 4: break;
		default: cout << ("Wrong number!!!") << "\n\n\n";
		}

	} while (menu != 4);
	system("pause");
	return 0;
}
