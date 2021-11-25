// Student 1  : Ethan Coyle                                                      //
// Student 2  : Daniel Portillo                                                  //
// User instructions: The program will prompt for the infile and outfile to read //
//                    enter the name of the infile to read from and outfile then //
//                    the code will compile. If the user would like to try anothe//
//                    sort, then run the program again and enter the name of the //
//                    next infile to read from and if want them in second output //
//                    specify a different output name to keep separate same for  //
//                    third infile run again and specifiy the input and output   //
//===============================================================================//
// Instructor : Dr. Colmenares                                                   //
// Class      : CMPS 3013 Advanced Algorithms                                    //
// Assignment : Program 4 counti Sort with (ascending,descending and rand input) //
//===============================================================================//
// What it does -                                                                //
//    This programs purpose isto utilize counting sort algorithm                 //
//    on the infile with specified   order                                       //
//    numbers 0 to 100000 and will catch the time                                //
//    that it takes for the program to run and                                   //
//    perform the sorting of the infile using                                    // 
//    the selection sorting on the infile contain                                //
//    the ascending order elements from 0- 100000                                //
//    amd then output the time in a nice, easy to                                //
//    read format for the viewer to see how long                                 //
//    it takes to read in the data and then the                                  //
//    ammount of time it takes to sort the given                                 //
//    input that is placed inside of an array                                    //
//===============================================================================//

//===============================================================================//
//    sorting code attributes by :                                               //
//                                                                               //
// https://www.bogotobogo.com/Algorithms/countingsort.php                        // 
//===============================================================================//

#include<iostream>
#include <fstream>
#include <chrono>    //for the start and stop time
#include <time.h>    //clock
using namespace std::chrono;// timer 
using namespace std;

//function prototypes
void openFiles(ifstream& InFile, ofstream& OutFile);
void print(int a[], int sz, ofstream& OutFile);


//#####################################################//
//f(x) name                                            // 
//  void openFiles(ifstream& InFile, ofstream& OutFile)//
//                                                     //
//what it does?                                        //
// -> purpose is to user input in and outfile          //
//                                                     //
//paramters                                            //
// -> utilizes the ofstream and outfile                //
//                                                     //
// return type                                         //
// -> no return type because  void                     //
//#####################################################//

void openFiles(ifstream& InFile, ofstream& OutFile)
{
	// Declare variable for the Files. 
	char inFileName[40];
	char outFileName[40];

	// Prompt the user for InFile name
	cout << "Enter the input file name: ";
	cin >> inFileName;

	// open input file
	InFile.open(inFileName);

	// Prompt the user for OutFile name
	cout << "Enter the output file name: ";
	cin >> outFileName;

	// Open outfile.
	OutFile.open(outFileName);
}

//*********************************************************************//
//* Function Name:												       //
//*	->void print(int a[], int sz,ofstream& OutFile)                    //
//*    -> prototype at the top                                         //
//																	   //
//* What does it do?												   //
//	  -> The purpose of this function is to parse through the array w/ //
//    -> a pointer and parse through the whole array and disaply the   //
//    -> values of the array from start to finish                      //
//						    	  	                                   //
//* Parameters:	    						                       	   //
//*  ->   This function takes two parameters a pointer int to array and//
//*  ->   the size of the array to loop through the whole length of arr//
//*																       //
//* Returns:														   //
//*   -> Void( the variables are being passed by reference so no return//   
//*********************************************************************//
void print(int a[], int sz,ofstream& OutFile) 
{
	OutFile << "\nThe Sorted Array is Disaplyed Below\n\n";
	OutFile << "====================================\n\n";
	for (int i = 0; i < sz; i++) 
		OutFile << a[i] << " "<< endl;
}

//*********************************************************************//
//* Function Name:												       //
//*	->void CountingSort(int arr[], int sz)                             //
//																	   //
//* What does it do?												   //
//	  -> The purpose of this function is to parse through the read in  //
//    -> Data and then perform the sorting algorithm on the data inside//
//    -> the array until it is fully sorted                            //
//						    	  	                                   //
//* Parameters:	    						                       	   //
//*  ->   This function takes two parameters, the integer array and the//
//   -> counter which will both be used inside of the sorting algorithm//
//*																       //
//* Returns:														   //
//*   ->There is no return because this function is void. However, This//
//*   -> finishes going through the whole array until there is no      //
//*   -> comparisons left to make                                      //   
//*********************************************************************//
void CountingSort(int arr[], int sz) 
{
	//initilize the variables
	int i, j, k;
	int idx = 0;
	int min, max;
	//min and max both equal to the first index
	min = max = arr[0];
	//loop through to find the min and max
	for (i = 1; i < sz; i++) 
	{
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	k = max - min + 1;
	/* creates k buckets */
	int* B = new int[k];
	for (i = 0; i < k; i++) B[i] = 0;

	//sorting the array
	for (i = 0; i < sz; i++) B[arr[i] - min]++;
	for (i = min; i <= max; i++)
		for (j = 0; j < B[i - min]; j++) arr[idx++] = i;
	delete[] B;// free up the dynamically allocated memory
}

// main driver of the program where all the calls and timing 
//will be made
int main()
{
	// create the in and out files 
	//go to the function to read in both files
	ifstream InFile;
	ofstream OutFile;
	openFiles(InFile, OutFile);// prompt for input output
	
	// size of the infile is 100001
	int size = 100001;
	// create te container array to hold the values
	int* Container = new int[size];
	int count = 0;
	// Reading till end of file
	while (!InFile.eof())
	{
		int n;
		// read in the elements from the infile
		// storing it into an array
		InFile >> n;
		Container[count] = n;
		// increment the counter to count through the data
		count++;
	}
	
	
	//if want to view the container holding the data call function
	//print(Container, sz);
	//start the timer for the program
	auto start = chrono::high_resolution_clock::now();

	//call the function to sort the data
	CountingSort(Container, count);
	//stop the timer after is done
	auto end = chrono::high_resolution_clock::now();
	// stop the timer and figure out how long it took
	// from start to stop
	auto int_s = chrono::duration_cast<chrono::milliseconds>(end - start);

	OutFile << "\n\nUsing Counting Sort, it took : " << int_s.count() <<
		" milliseconds to sort Ascending InFile" << "\n\n\n";

	// display the sorted array to show that array has been sorted
	//print(Container, count,OutFile);
	system("pause");

	//close the file and close out of program
	InFile.close();
	OutFile.close();
	return 0;
}
