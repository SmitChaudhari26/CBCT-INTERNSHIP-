#include <iostream>
#include <limits>

using namespace std;

void showMenu()
{
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Modulo" << endl;
    cout << "6. Exit" << endl;
}

int getValidInput()
{
    int input;
    while (true)
    {
        cin >> input;
        if (cin.fail() || input < 1 || input > 6)
        {
            cout << "Invalid input. Please enter a number between 1 and 6: ";
        }
        else
        {
            break;
        }
    }
    return input;
}

double getValidNumber()
{
    double num;
    while (true)
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }
        else
        {
            break;
        }
    }
    return num;
}

int main()
{
    while (true)
    {
        cout << endl
             << endl
             << endl;
        cout << "\t\t\t\t\tDIGITAL CALCULATOR\t\t\t\t";
        cout << endl;
        showMenu();
        cout << "Choose an option: ";
        int choice = getValidInput();

        if (choice == 6)
            break;

        cout << "Enter first number: ";
        int num1 = getValidNumber();
        cout << "Enter second number: ";
        int num2 = getValidNumber();

        switch (choice)
        {
        case 1:
            cout << "Result: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Result: " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Result: " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero" << endl;
            break;
        case 5:
            cout << "Result: " << (num1) % (num2) << endl;
            break;
        }
    }
    return 0;
}
