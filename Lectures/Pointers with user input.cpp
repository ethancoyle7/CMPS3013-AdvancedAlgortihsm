// This program processes an array using pointer notation.
#include <iostream>
using namespace std;

int main()
{
   const int SIZE = 5;    // Size of the array
   int numbers[SIZE];     // Array of integers   

   // Get values to store in the array
   // Use pointer notation instead of subscripts
   cout << "===================================" << endl;
   cout << "Enter " << SIZE << " numbers: ";
   for (int count = 0; count < SIZE; count++)
      cin >> *(numbers + count);
   cout << "===================================" << endl;

   // Display the values in the array
   // Use pointer notation instead of subscripts		
   cout << "Here are the numbers you entered:\n";
   for (int count = 0; count < SIZE; count++)
      cout << *(numbers + count) << " ";
   cout << endl;
   cout << "===================================" << endl;
   return 0;
}
