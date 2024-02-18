#include <iostream>
using namespace std;

int main()
{
	int num;
	char letter;
	double num2; // double é um número real (float) com MAIOR precisão
	bool bool_var = false;
	string string_var;
	
	cout << "Insert a NUMBER: ";
	cin >> num;
	
	cout << "Insert a LETTER: ";
	cin >> letter;
	
	cout << "Insert a DOUBLE NUMBER: ";
	cin >> num2;
	
	cout << "Insert a STRING: ";
	cin >> string_var;
	
	cout << "\nInt: " << num << endl;
	cout << "Char: " << letter << endl;
	cout << "Double: " << num2 << endl;
	cout << "Bool: " << bool_var << endl;
	cout << "String: " << string_var << endl;
	
	return 0;
}
