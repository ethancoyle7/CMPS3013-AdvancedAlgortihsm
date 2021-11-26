// Student 1  : Ethan Coyle                                                      //
// Student 2  : Daniel Portillo                                                  //
// User instructions: The program will automatically read in the data file so    //
//                    when comes time for compilation, make sure that the data   //
//                    filess are in the same folder and can also bring then into //
//                    visual studios solution explorer so after all that is done,//
//                    the only thing that the user needs to do is to hit ctrl+f5 //
//                    to compile and the program will run and then display the   //
//                    time it took to sort the data                              //
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
void openFiles(ifstream& InFile);
void selectionSort(int* array, int size);
void swapping(int& a, int& b);
void display(int* array, int);

//#####################################################//
//f(x) name                                            // 
//  void openFiles(ifstream& InFile)                   //
//                                                     //
//what it does?                                        //
// -> purpose is to user input in stream file          //
//                                                     //
//paramters                                            //
// -> utilizes the infile streaming                    //
//                                                     //
// return type                                         //
// -> no return type because  void                     //
//#####################################################//

void openFiles(ifstream& InFile)
{
    // Declare variable for the Files. 
    // open input file
    InFile.open("RandomOrder.txt");
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
void display(int* array, int size)
{
    cout << "The Sorted Array is Disaplyed Below\n\n";
    cout<< "====================================\n\n";
    for (int i = 0; i < size; i++)
        cout << array[i] << " " << endl;
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
    openFiles(InFile);// prompt for input output

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

    cout << "\n\nUsing Selection Sort, it took : " << int_s.count() <<
        " seconds to sort Random InFile" << endl;
    // display the sorted array to show that array has been sorted
    //display(Container, count);
    system("pause");

    //close the file and close out of program
    InFile.close();
    return 0;
}
