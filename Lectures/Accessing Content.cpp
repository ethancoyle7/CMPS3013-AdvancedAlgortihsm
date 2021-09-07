// This program shows an array name being dereferenced with the *
// operator.
#include <iostream>
using namespace std;

int main()
{
	short numbers[] = {10, 20, 30, 40, 50};

	cout << "The first element of the array is ";
	cout << *numbers << endl;//accesses the first address contents

	cout << (*numbers +1 ) << endl;
  //add one to the first prints out 11
	cout << *(numbers +1)  << endl;
  //pointer on the outside access the array go to second value
	cout << (numbers)  << endl;
  //prints out the address of numbers first number
	cout << (numbers +1)  << endl;//address of the second
	cout << numbers[1] <<endl;//address of the second containing 20
	return 0;
}
