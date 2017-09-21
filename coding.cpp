#include <iostream>
using namespace std;
void Coding(int size);
int main()
{
	int size;
	cout << "Enter the size of your array of symbols - ";
	cin >> size;
	
	Coding(size);
	
	system("pause");
	return 0;
}
void Coding(int size) {
	int *mas_int;
	char *mas_char;
	mas_char = new char[size];
	mas_int = new int[size];

	cout << "Enter the array of symbols - ";
	for (int i = 0; i < size; ++i)
	{
		cin >> mas_char[i];
	}
	for (int i = 0; i < size; ++i)
	{

		cout << mas_char[i] << "  ";
	}
	cout << endl;


	cout << "Your char_int array : " << endl;
	for (int i = 0; i < size; ++i)
	{
		mas_int[i] = int(mas_char[i]);
		cout << mas_int[i] << "  ";
	}
	cout << endl;
	cout << "Your int_code : " << endl;
	for (int i = 0; i < size; ++i) {

		int b = mas_int[i];
		cout << mas_char[i] << " - ";
		while (b > 0)
		{
			cout << b % 2;
			b /= 2;
		}
		cout << endl;
	}
	cout << endl;
}
