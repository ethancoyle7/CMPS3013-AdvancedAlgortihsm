// Student 1  : Ethan Coyle                                                      //
// Student 2  : Daniel Portillo                                                  //
// User instructions: The program will prompt for the outfile to print to this   //
//                    one will read from the random order input file and then    //
//                    perform and run the program and time the timing that it    //
//                    takes to iterate through the whole infile and sort it.     //
//                    Once Brought into Visual Studios attach the corresponding  //
//                    infile and then run the program and it will compile in the //
//                    solution explorer and the program will compile if need be, //
//                    inside of the infile and exfile read in the user can input //
//                    the relative path to the input file and that will compile  //
//                    as well.                                                   //
//===============================================================================//
// Instructor : Dr. Colmenares                                                   //
// Class      : CMPS 3013 Advanced Algorithms                                    //
// Assignment : Program 4 Selection Sort with (RandomOrder.txt)                  //
//===============================================================================//
// What it does -                                                                //
//    This programs purpose isto utilize selection sort                          //
//    on the infile with specified   order                                       //
//    numbers 0 to 100000 and will catch the time                                //
//    that it takes for the program to run and                                   //
//    perform the sorting of the infile using                                    // 
//    the selection sorting on the infile contain                                //
//    the rnadom    order elements from 0- 100000                                //
//    amd then output the time in a nice, easy to                                //
//    read format for the viewer to see how long                                 //
//    it takes to read in the data and then the                                  //
//    ammount of time it takes to sort the given                                 //
//    input that is placed inside of an array                                    //
//===============================================================================//

//===============================================================================//
//    sorting code attributes by :                                               //
//                                                                               //
// https://www.tutorialspoint.com/cplusplus-program-to-implement-selection-sort  // 
//===============================================================================//
#include<iostream>
#include <fstream>
#include <chrono>    //for the start and stop time
#include <time.h>    //clock, clock_t
using namespace std::chrono;
using namespace std;

// function prototypes
void openFiles(ifstream& InFile, ofstream& OutFile);
void selectionSort(int* array, int size);
void swapping(int& a, int& b);
void display(int* array, int, ofstream& OutFile);

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
    
    char outFileName[40];

    // open input file
    InFile.open("RandomOrder.txt");

    // Prompt the user for OutFile name
    cout << "Enter the output file name: ";
    cin >> outFileName;

    // Open outfile.
    OutFile.open(outFileName);
}

// for isplaying purposes for reader and viewer easement
//*********************************************************************//
//* Function Name:												       //
//*	->void swapping(int &a, int &b)                                    //
//*    -> prototype at the top                                         //
//																	   //
//* What does it do?												   //
//	  -> The purpose of this function is that when it is called when   //
//    -> parsing through the array, if there is a min value, to swap   //
//    -> the values in the compared element by pointing to the address //
//    -> and accessing the elemnt inside of those comparisons          //
//						    	  	                                   //
//* Parameters:	    						                       	   //
//*  ->   This function takes two parameters: address to the first     //
//*  ->   element and the address to second element so can swap        //
//*																       //
//* Returns:														   //
//*   -> Void( the variables are being passed by reference so no return//   
//*********************************************************************//
void swapping(int& a, int& b)
{
    //swap the content of a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
}
// for isplaying purposes for reader and viewer easement
//*********************************************************************//
//* Function Name:												       //
//*	->void display(int *array, int size)                               //
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
void display(int* array, int size, ofstream& OutFile)
{
    OutFile << "The Sorted Array is Disaplyed Below\n\n";
    OutFile << "====================================\n\n";
    for (int i = 0; i < size; i++)
        OutFile << array[i] << " " << endl;
}

//*********************************************************************//
//* Function Name:												       //
//*	->void selectionSort(int *array, int size)                         //
//*    -> prototype at the top                                         //
//																	   //
//* What does it do?												   //
//	  -> The purpose of this function is to compare values in the array//
//	  -> with a pointer to the elements for the whole size of the array//
//    -> and then compare for min value and if there is a min in compar//
//	  -> swap the values and call the swap function					   //
//						    	  	                                   //
//* Parameters:	    						                       	   //
//*  ->   This takes a integer pointer to an array and the size of arra//
//*   ->   as its parameters                                           //
//*																       //
//* Returns:														   //
//*   -> Void( the variables are being passed by reference so no return//   
//*********************************************************************//
void selectionSort(int* array, int size)
{
    int i, j, imin;
    for (i = 0; i < size - 1; i++) {
        imin = i;   //get index of minimum data
        for (j = i + 1; j < size; j++)
            if (array[j] < array[imin])
                imin = j;
        //placing in correct position
        swap(array[i], array[imin]);
    }
}




int main()
{
    srand(time(NULL)); //set time to null
    // size of the infile is 100001
    int size = 100001;
    // create te container array to hold the values
    int* Container = new int[size];
    // start tge counter for the index and the element
    int count = 0;
    int n = 0;

    ifstream InFile;
    ofstream OutFile;
    openFiles(InFile, OutFile);// prompt for input output

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
    // start the timer
    auto start = chrono::high_resolution_clock::now();

    // call the function to do the work on sorting
    selectionSort(Container, count);

    //stop the timer after is done
    auto end = chrono::high_resolution_clock::now();
    // stop the timer and figure out how long it took
    // from start to stop
    auto int_s = chrono::duration_cast<chrono::seconds>(end - start);

    OutFile << "\n\nUsing Selection Sort, it took : " << int_s.count() <<
        " seconds to sort Random InFile" << endl;
    // display the sorted array to show that array has been sorted
    display(Container, count, OutFile);
    system("pause");

    //close the file and close out of program
    InFile.close();
    OutFile.close();
    return 0;
}
