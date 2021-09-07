// This program demonstrates the ability of a pointer to
// point to different variables.
#include <iostream>
using namespace std;

int main()
{
	int x = 25, y = 50, z = 75;        // Three int variables
	int *ptr;                          // Pointer variable

   // Display the contents of x, y, and z.
	cout << "===========================================" << endl;
	cout << "BEFORE: Here are the values of x, y, and z:\n";
	cout << x << "  " << y << "  " << z << endl;
	cout << "===========================================" << endl;
   // Use the pointer to manipulate x, y, and z
	
	ptr = &x;         // Store the address of x in ptr
	*ptr *= 2;        // Multiply value in x by 2
	
	ptr = &y;         // Store the address of y in ptr
	*ptr *= 2;        // Multiply value in y by 2
	
	ptr = &z;         // Store the address of z in ptr
	*ptr *= 2;        // Multiply value in z by 2
	
	// Display the contents of x, y, and z
    cout << "AFTER: Once again, here are the values "
	     << "of x, y, and z:\n";
	cout << x << "  " << y << "  " << z << endl;
	cout << "===========================================" << endl;
	return 0;
}
