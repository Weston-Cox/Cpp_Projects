/******************************************************************************
Name: Weston Cox
UAID: 011002376
Section: 002

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <ios>
#include <limits>
using namespace std;


double SeatType() { //* This function prints out the menu and receives the input for the seat type
    //* From the user
    bool valid = false;
    char seatNum;
    double amtOwed;

    cout << "Please choose which seat you would like \nby typing the corresponding number." << endl;
    sleep(2); // Pauses the program for 2 seconds.
    do {
        // This is the menu
        cout << endl    << "(1) Nosebleed --------- $5 " << endl
             << "(2) Box Seats --------- $100 " << endl
             << "(3) 50 Yard Line ------ $50 " << endl
             << "(4) Student Section --- $10 " << endl;
        cin >> seatNum;

        switch (seatNum) { // This switch-case statement reiterates what the customer will buy, and sends a value back
            // to the cash/credit function that called it.
            case '1':
                cout << "Nosebleed seats. You owe $5.00. " << endl;
                valid = true;
                amtOwed = 5.00; //Returned to the function that called this one.
                break;
            case '2':
                cout << "Box seats. You owe $100.00. " << endl;
                valid = true;
                amtOwed = 100.00; //Returned to the function that called this one.
                break;
            case '3':
                cout << "50 Yard Line seats. You owe $50.00. " << endl;
                valid = true;
                amtOwed = 50.00; //Returned to the function that called this one.
                break;
            case '4':
                cout << "Student Section seats. You owe $10.00. " << endl;
                valid = true;
                amtOwed = 10.00; //Returned to the function that called this one.
                break;
            default:
                cout << "That is not a valid input. Please try again. " << endl;
                cin.clear();                //This and the next line are used as error prevention.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;

        }
    } while (!valid);

    return amtOwed;
}


// This function converts the numeric change value into its respective legal tender.
void ChangeCalculation(double change) {
    int intChange = change * 100; //Converts the double into an integer value, which can be used with the modulus operator.

    int tempVal; // Used to store the intermediate value of the legal tinder calculation.
    int dollars;
    int quarters;
    int dimes;
    int nickels;
    int pennies;

    //This section converts the change into its respective legal tender.
    dollars = intChange / 100;
    cout << dollars << " Dollar(s), ";

    tempVal = intChange % 100;

    quarters = tempVal / 25;
    cout << quarters << " Quarter(s), ";

    tempVal = tempVal % 25;

    dimes = tempVal / 10;
    cout << dimes << " Dime(s), ";

    tempVal = tempVal % 10;

    nickels = tempVal / 5;
    cout << nickels << " Nickel(s), and ";

    tempVal = tempVal % 5;

    pennies = tempVal / 1;
    cout << pennies << " Pennies. " << endl;


}


// This function is used to handle a cash payment. It is called from main().
double CashPayment() {
    double amtOwed;
    double amtPaid;
    double change ;
    bool valid = false;

    cout << "You have chosen to pay with cash.\n " << endl;
    sleep(2);

    amtOwed = SeatType();

    do {
        cout << "How much cash are you paying with? " << endl;
        cin >> amtPaid;

        if (!cin) {
            cout << "That is an invalid input, please try again." << endl;

            cin.clear();        //This and the next line are used as error prevention.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } else if (amtPaid < amtOwed)
            cout << "Sorry, that is not enough. Please try again. " << endl;
        else {
            change = amtPaid - amtOwed;
            valid = true;
        }

    } while (!valid);

    cout << "Your change is: $" << setprecision(2) << fixed << change << endl;
    cout << "Which is ";
    ChangeCalculation(change);

    return 0.0;
}


// This function is used to handle credit payment. It is called from main().
double CreditPayment() {
    double amtOwed;

    cout << "You have chosen to pay with credit.\n " << endl;
    sleep(2);

    amtOwed = SeatType();
    cout << "Your card will be charged the owed amount within 3 business days. ";
    return 0.0;
}



//Main function.
int main()
{
    char choice;
    bool valid = false;

    cout << "Name: Weston Cox " << endl
         << "UAID: 011002376 " << endl;

    do {

        cout << "Choose '1' for Cash and '2' for Credit Card. " << endl;

        cin >> choice;

        if (choice == '1') {
            CashPayment();
            valid = true;

        } else if (choice == '2') {
            CreditPayment();
            valid = true;

        } else {
            cout << "That is an invalid input, please try again." << endl;
            cin.clear();        //This and the next line are used as error prevention.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!valid); // Error Checking for the tinder type.

    return 0;
}

//Easter Egg!
