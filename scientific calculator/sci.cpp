#include <iostream>
#include <cmath>

using namespace std;

void display_menu()
{
    cout << "Scientific Calculator Menu:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Sine" << endl;
    cout << "6. Cosine" << endl;
    cout << "7. Tangent" << endl;
    cout << "8. Logarithm" << endl;
    cout << "9. Exponential" << endl;
    cout << "10. Exit" << endl;
}

double add()
{
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    return num1 + num2;
}

double subtract()
{
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    return num1 - num2;
}

double multi()
{
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    return num1 * num2;
}

double division()
{
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    if (num2 == 0)
    {
        cout << "Error: cannot divide it by zero." << endl;
        return NAN;
    }

    return num1 / num2;
}

double sine()
{
    double angle;
    cout << "Enter angle in degrees: ";
    cin >> angle;
    return sin(angle * M_PI / 180.0);
}

double cosine()
{
    double angle;
    cout << "Enter angle in degrees: ";
    cin >> angle;
    return cos(angle * M_PI / 180.0);
}

double tangent()
{
    double angle;
    cout << "Enter angle in degrees: ";
    cin >> angle;
    return tan(angle * M_PI / 180.0);
}

double logarithm()
{
    double number;
    cout << "Enter a positive number: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Error: Logarithm is undefined for non-positive numbers." << endl;
        return NAN;
    }

    return log(number);
}

double exponential()
{
    double number;
    cout << "Enter a number: ";
    cin >> number;
    return exp(number);
}

int main()
{

    cout << "Welcome to the Scientific Calculator!" << endl;
    cout << "------------------------------------" << endl;
    display_menu();
    int choice;
    double result;
    cout << "Enter your choice (1-10): ";
    cin >> choice;
    switch (choice)
    {

    case 1:
        result = add();
        cout << "Result: " << result << endl;
        break;

    case 2:
        result = subtract();
        cout << "Result: " << result << endl;
        break;

    case 3:
        result = multi();
        cout << "Result: " << result << endl;
        break;

    case 4:
        result = division();
        if (!isnan(result))
            cout << "Result: " << result << endl;
        break;

    case 5:
        result = sine();
        cout << "Result: " << result << endl;
        break;

    case 6:
        result = cosine();
        cout << "Result: " << result << endl;
        break;

    case 7:
        result = tangent();
        cout << "Result: " << result << endl;
        break;

    case 8:
        result = logarithm();
        if (!isnan(result))
            cout << "Result: " << result << endl;
        break;

    case 9:
        result = exponential();
        cout << "Result: " << result << endl;
        break;

    case 10:
        cout << "Exiting the calculator. Goodbye!" << endl;
        break;

    default:
        cout << "Invalid choice. Please select a valid option." << endl;
        break;
    }

    return 0;
}