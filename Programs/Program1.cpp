//###############################################//
//                                               //
// Author     : Ethan Coyle                      //
// Instructor : Dr.Colmeneras                    //
// Class      : CMPS 3013(Advanced Algorithms)   //
// Assignment : Program 1 STL Link List          //
//                                               //
// The purpose of this program is to show the    //
// Proper implementation of a linked list with   //
// Vector implementation that allows the user to //
// Add or remove students if they so choose to   //
// And show linked list implementation using the //
// STL library in C++                            //
//###############################################//
#include<iostream>
#include<fstream>
#include <list>
using namespace std;
//using the stl library, we utilize the pop-front 
//pop-back, and the list include. WE also utilize the 



//function prototypes
void printPageHeading(ofstream& OutFile);
void PopulatingStudentList();
void DisplayList(ofstream& OutFile);
void RemoveCurHead(ofstream& OutFile);
void RemoveFromTail(ofstream& OutFile);
void AddStudent();
void ShowNames(ofstream& OutFile);
void openFiles(ofstream& OutFile);
void OptionMenu(ofstream& OutFile);



// creating struct to hold database
struct Student
{
    string FName, LName;
    char Gender;
    int age, id;
};

// creating  new linked list using stl
//by utilizing this we create a STL Container of students 
// that utilizes the stl library 
list<Student> NewStudent;

//#####################################################//
//function name                                        // 
//->  PopulatingStudentList()                                 //
//                                                     //
//what it does?                                        //
// -> The purpose of this function is                  //
//    to implement a population of student records     //
//    until the user doesnt want to add any more       //
//paramters                                            //
// -> This accepts no parameters but is accesing       //
//     the stl linked list for the STL Container ofuser//
//     and creating new students held in the student   //
//     STL Container.                                  //
// return type                                         //
// -> no return type because  void                     //
//    This is just populating the student STL Container//  
//#####################################################//
void PopulatingStudentList()
{
    while (1)//bool value that holds true
    {
        string FName, LName;
        char G;
        int Age, IdNum;
        //populating the list with students
        cout << "Enter Students First Name\t\t";
        cin >> FName;
        cout << "Enter Students Last Name\t\t";
        cin >> LName;
        cout << "What is The Gender?\n";
        cout<<" (M for Male|F for Female)\t\t";
        cin >> G;
        cout << "Enter Students Age\t\t";
        cin >> Age;
        cout << "Enter the Students ID Number \t\t";
        cin >> IdNum;
        //student record held inside with all stuct data
        NewStudent.push_back({ FName,LName,G,Age,IdNum });

        //as per guidelines aprompt as many as want
        cout << "Would you Like to add another Record?\n";
        cout<<"(Y for Yes or N for No ? )\t\t";
        char Input;
        cin >> Input;
        //if the input by the user is N. then will go back to main menu
        if (Input != 'y' && Input != 'Y')
            break;
    }
}
//#####################################################//
//function name                                        // 
//->  void DisplayList()                               //
//                                                     //
//what it does?                                        //
// -> the purpose of this function is to display       //
//    the list of names and thier ids                  //
//paramters                                            //
// -> This accepts no parameters but is accesing       //
//     the stl linked list for the STL Containerof user//
//     inputted student values starting from the head  //
//     also utilized by begin()                        //
// return type                                         //
// -> no return type because  void                     //
//    ths just prints out the name and id for STL      //
//    Container of                                     //
//    students inputed by the user                     //  
//#####################################################//
void DisplayList(ofstream& OutFile)
{
    list<Student>::iterator Node;
    Node = NewStudent.begin();

    //just for assurance check if link list is empty
    if (NewStudent.empty())
        OutFile << "The List Container is Currently Empty" << "\n";
    else
    {
        //while is not eaul to the end of the list
        while (Node != NewStudent.end())
        {
            //pointer while traversing the link list to print out the name from
            //head to tail
            OutFile << Node->FName << " " << Node->LName <<
                " - id:" << Node->id << "\n";
            Node++;
        }
        OutFile << "-------------------------------\n\n";
    }

}

//#####################################################//
//function name                                        // 
//->  RemoveCurHead()                                  //
//                                                     //
//what it does?                                        //
// -> the purpose of this program is to  remove the    //
//     current head node and have it point to the next //
//     value which takes up the place of the head      //
//                                                     //
//paramters                                            //
// -> This accepts no parameters but is accesing       //
//     the stl linked list for the STL Container o user//
//     to find the head and remove it                  //
// return type                                         //
// -> no return type because  void                     //
//    the visual we get from this is if we display list//
//    of students again by option 2                    //  
//#####################################################//
void RemoveCurHead(ofstream& OutFile)
{
    //removing the node at the head
    if (NewStudent.empty())
        OutFile << "The List Container is Currently Empty" << "\n";
    else
    {
        NewStudent.pop_front();// (pop head) pointing to next value
        OutFile << "After Removing from the Head \n";
    }

}

//#####################################################//
//function name                                        // 
//->  void RemoveFromTail()                            //
//                                                     //
//what it does?                                        //
// -> the purpose of this program is to  remove the    //
//     current tail node and have it point to the next //
//     value which takes up the place of the tail      //
//                                                     //
//paramters                                            //
// -> This accepts no parameters but is accesing       //
//     the stl linked list for the STL Container ofuser//
//     to find the head and remove it                  //
// return type                                         //
// -> no return type because  void                     //
//    the visual we get from this is if we display list//
//    of students again by option 2                    //  
//#####################################################//
void RemoveFromTail(ofstream& OutFile)
{
    //removing the tail most student record
    // and then tail will be the option before that one
    if (NewStudent.empty())
        OutFile << "The List Container is Currently Empty" << "\n";
    else
    {
        NewStudent.pop_back(); // stl link list operator pop_back(tail)
       //test if removed
        OutFile << "After Removing From Tail \n";
    }

}
//#####################################################//
//function name                                        // 
//->  void AddStudent()                                //
//                                                     //
//what it does?                                        //
// -> the purpose of this function is adding another   //
//    student record to the end of the list and that   //
//    student now become the new tail of our link list //
//                                                     //
//paramters                                            //
// -> This accepts no parameters but it  creates new   //
//    student record and accesses the stucture format  //
//    and adds this on to the end of the list          //
// return type                                         //
// -> no return type because  void                     //
//    the visual we get from this is if we display list//
//    of students again by option 2 or 5               //  
//#####################################################//
void AddStudent()
{
    int NumRecords;
    cout << "How Many Records Would You Like T add to the End?\n";
    cin >> NumRecords;
    while (NumRecords--)//while counting down to end of adding students
    {
        //initializing the entry for student record
        string FName, LName;
        char G;
        int Age, IdNum;

        //prompting for the user input for the student
        cout << "Enter Students First Name\n";
        cin >> FName;
        cout << "Enter Students Last Name\n";
        cin >> LName;
        cout << "Enter Student Gender\n";
        cin >> G;
        cout << "Enter student  Age\n";
        cin >> Age;
        cout << "Enter Student  ID Number \n";
        cin >> IdNum;
        //pass this new student to the  list with all the info
        NewStudent.push_back({ FName,LName, G,Age,IdNum });
    }
}
//#####################################################//
//function name                                        // 
//->  void  ShowNames()                                //
//                                                     //
//what it does?                                        //
// -> the purpose of this function is to peruse through//
//    the STL list STL Container and print out the curr//
//    students and their id numbers  starting at the   //
//    head node and working all the way to the end tail//
//                                                     //
//paramters                                            //
// -> This accepts no parameters but it accesses the   //
//    Given list STL Container and finds the students  //
//    and id                                           //
// return type                                         //
// -> no return type  just displays the current list   //
//    starting at the head node                        //  
//#####################################################//
void ShowNames(ofstream& OutFile)
{
    //utilizing the std template for STL Container link list we 
    //peruse and start at beggining and go to the end(tail)
    list<Student>::iterator it;
    it = NewStudent.begin();
    OutFile << "\n Showing Student Names in List \n";
    OutFile << " ------------------------------\n";
    while (it != NewStudent.end())//while not the end
    {
        //pointer pointing to the First name
        //show the list agin just the name not last name ot
        //other information(program guidelines)
        OutFile << it->FName << "\n";
        it++;//link list iterator
    }
    OutFile << " ------------------------------\n";
}


/////////////////////////////////////////////////////
// function name                                   //
// -void printPageHeading()                        //
//                                                 //
// parameters-                                     //
// - Accepts No parameters but displays nice header//
//   For easy to view user usage                   //
//                                                 //
// what it does-                                   //
// -the purpose of this function is to print       //
// -the header for output                          //
//                                                 //
// return type-null(doesnt return value just prints//
/////////////////////////////////////////////////////

//print page and column headings
void printPageHeading(ofstream& OutFile)
{
    OutFile << " ---------------------------------------------\n";
    OutFile << "| Author    :  Ethan Coyle                   |" << '\n';
    OutFile << "| Class     :  Advanced Algorithms CMPS 3013 |\n";
    OutFile << "| Instructor:  Dr. Colmenares                |\n";
    OutFile << "| Assignment:  Program 1                     |" << '\n';
    OutFile << "|              Linked List using STL List    |" << '\n';
    OutFile << "----------------------------------------------\n\n\n";
    cout << "********************************************\n";
    cout << "**         WELCOME TO OUR LINK LIST       **\n";
    cout << "**          TO DISPLAY AN UTILIZE         **\n";
    cout << "**          Our List Of Students          **\n";
    //nice formatting for easy reading  
}
/////////////////////////////////////////////////////
// function name                                   //
// -void DisplayMenu()                             //
//                                                 //
// parameters-                                     //
// -This accepts no parameters but displays the    //
//   Menu for the user to see what options to choos//
//                                                 //
// what it does-                                   //
// - The only purpose this serves is to help user  //
//   better maneauver through our program efficient//
//   I also added it as an option as a choice just //
//   in case the user would like to see menu optons//
//   again after typing in all the other informatio//
//                                                 //
// return type                                     //
//   -null(doesnt return value just prints         //
/////////////////////////////////////////////////////
void DisplayMenu()
{
    cout << "********************************************\n";
    cout << "**   To Populate Our List       Press 1   **\n";
    cout << "**   To Display  Our List       Press 2   **\n";
    cout << "**   To remove node from head   Press 3   **\n";
    cout << "**   To remove node from tail   Press 4   **\n";
    cout << "**   To add Records to   tail   Press 5   **\n";
    cout << "**   To Show Names in List      Press 6   **\n";
    cout << "**   For The Menu Option Again  Press 7   **\n";
    cout << "**   To Exit                    Press 8   **\n";
    cout << "********************************************\n";
}
void OptionMenu(ofstream& OutFile)//utilizing the outfile streaming
{
    while (1)//while option is true this is in tune with link list stl
    {
        //user enters the specified option they want to do
        cout << "What Would You Like To Do? (Enter 1-8) ";

        int choice;
        cin >> choice;
        while (choice < 1 || choice>8)//if the entry is out of bounds
        {
            cout << "That Is Not a Valid Option Please Enter a\n" <<
                "Number Between 1 and 8";
            cin >> choice;
        }
        switch (choice)//switch statement to go to functions
        {
        case 1:
            PopulatingStudentList();//populating the STL Container or students
            break;
        case 2:

            OutFile << "We Are Now Displaying Our List\n";
            OutFile << " ------------------------------\n";
            DisplayList(OutFile);//display student info
            break;
        case 3:
            RemoveCurHead(OutFile);// function choice to remove surrent head
            break;
        case 4:
            RemoveFromTail(OutFile);//function to remove the current tail
            break;
        case 5:
            AddStudent();// user will be able to add another student to the tail
            break;
        case 6:


            ShowNames(OutFile);//show names of students in link list
            break;
        case 7:
            DisplayMenu();//This adds user easement if they forget the menu
                          //displays the menu down the terminal to refresh
                          //option choices
            break;
        case 8:
            return;// closeing out of program
        }
    }
}

//#####################################################//
//f(x) name                                            // 
//  void openFiles( ofstream& OutFile)                 //
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
void openFiles(ofstream& OutFile)
{
    // Declare variable for the Files. 
    char outFileName[40];


    // Prompt the user for OutFile name
    cout << "Enter the output file name: ";
    cin >> outFileName;

    // Open outfile.
    OutFile.open(outFileName);
}

//Begin our main driver for our program
int main()
{
    //minimizing the ammount of data in main
    
    ofstream OutFile;
    openFiles(OutFile);// prompt for input output
    //printing out the header for program
    printPageHeading(OutFile);

    DisplayMenu(); //display options menu
    OptionMenu(OutFile);//go to the display menu
    return 0; // end of program exitting now
}
