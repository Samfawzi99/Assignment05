// AssignmentWeek05.cpp
// Samoel Fawzi
// ITCS 2530

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cstring>

using namespace std;

//declaring first function
void ShowUsage() {
    cout << "To show program usage press 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
}
//declaring second function
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS) {
    char ch;
    int quantity;
    cout << "Please enter the quantity and type (X=xxxs, S=small, M=medium, L=Large) of surfboard you would like to purchase:";
    cin >> quantity;
    cin >> ch;
    if (ch == 's' || ch == 'S') {
        iTotalSmall = iTotalSmall + quantity;
    }
    else if (ch == 'm' || ch == 'M') {
        iTotalMedium = iTotalMedium + quantity;
    }
    else if (ch == 'l' || ch == 'L') {
        iTotalLarge = iTotalLarge + quantity;
    }
    else if (ch == 'x' || ch == 'X') {
        iTotalXXXS = iTotalXXXS + quantity;
    }
    cout << endl;
}
//declaring third function
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {
    if (iTotalSmall > 0) {
        cout << "The total number of small surfboards is: " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0) {
        cout << "The total number of medium surfboards is: " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0) {
        cout << "The total number of large surfboards is: " << iTotalLarge << endl;
    }
    if (iTotalXXXS > 0) {
        cout << "The total number of xxxs surfboards is: " << iTotalXXXS << endl;
    }
    else if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0) {
        cout << "No purchases made yet." << endl;
    }

}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
    //defining variables
    double smallCost = 0;
    double mediumCost = 0;
    double largeCost = 0;
    double xxxsCost = 0;
    //variable to be used to calculate amount due
    double total;
    //defining these variables again? The program wasn't executing without defining the variables again, even though they are defined in main?
    const double smallBoard = 175;
    const double mediumBoard = 190;
    const double largeBoard = 200;
    const double xxxsBoard = 20;
    //if statement to output number of boards with total
    if (iTotalSmall > 0)
    {
        smallCost = smallCost + (iTotalSmall * smallBoard);
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << setprecision(2) << fixed << smallCost << endl;

    }
    if (iTotalMedium > 0)
    {
        mediumCost = mediumCost + (iTotalMedium * mediumBoard);
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << setprecision(2) << fixed << mediumCost << endl;
    }

    if (iTotalLarge > 0)
    {
        largeCost = largeCost + (iTotalLarge * largeBoard);
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << setprecision(2) << fixed << largeCost << endl;
    }
    if (iTotalXXXS > 0)
    {
        xxxsCost = xxxsCost + (iTotalXXXS * xxxsBoard);
        cout << "The total number of xxxs surfboards is " << iTotalXXXS << " at a total of $" << setprecision(2) << fixed << xxxsCost << endl;
    }
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0)
        cout << "No purchases made yet." << endl;
    else
    {
        //outputting total
        total = smallCost + mediumCost + largeCost + xxxsCost;
        cout << "Amount due: $" << setprecision(2) << fixed << total << endl;
    }
    cout << endl;

}

int main()
{
    //i/o manipulation
    cout << setw(60) << setfill('*') << "*" << endl;
    cout << setw(5) << "*" << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << "*" << endl;
    cout << setw(60) << setfill('*') << "*" << endl << endl << endl;
    //defining variables
    char ch = ' ';  //for some reason char ch; was not working, but char ch = ' '; was working, I thought it's basically both setting the char as an empty value?
    ShowUsage();
    const double smallBoard = 175;
    const double mediumBoard = 190;
    const double largeBoard = 200;
    const double xxxsBoard = 20;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    int iTotalXXXS = 0;

    //int i = 1; Initially I wanted to use while i != 2 to exit the loop and then when case q popped up just initailize i = 2, but then I realized that I needed to use a char in the inputs
    cout << endl;
    //entering while lopp that exits when selection is q
    while (ch != 'q')
    {
        cout << "Please enter selection: ";
        //asking for ch input and entering switch
        cin >> ch;
        switch (ch)
        {
        case 'S':
        case 's':
            //made selection S clear screen, I don't know if you meant to do it like this in your program but I just followed how you did it.
            system("CLS");
            ShowUsage();
            cout << endl;
            break;
        case 'p':
        case 'P':MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
            cout << endl;
            break;
        case 'c':
        case 'C':DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
            cout << endl;
            break;
        case 't':
        case 'T':DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
            break;
        case 'Q':
        case 'q':
            cout << "Thank you" << endl;
        default:
            //when selection is any other case other than s,p,c,t or q then it prompts to enter a selection again
            //for some reason it's displaying it twice so I removed the show selection statement and just added an endl
            //that makes the program look more clean if someone enters a wrong selection
            // this only works if one wrong character is entered, if more than one char is entered then that number of chars is outputted as lines
            cout << endl;
            break;
        }
        //while loop exited
    }


    system("Pause");
    return 0;
}

