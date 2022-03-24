/*

--FCAI_CU - Programming 1 - 2022 - Assignment 2--

Program Name: Complex Number Calculator
Description: This program takes complex numbers in the form "(a+bi)+(c+di)" and calculates the entered problem.
Purpose: Make operations on complex numbers
Author and contributors: Youssef Moataz, Aya Ali, Hend Ahmed
IDs: 20210488, 20210083, 20211111
Group: A
Labs: S4, S4, S9
Teaching Assistant: -
Last Modification Date: March 24, 2022.
Version: v1.5.0

*/

#include <iostream>
#include <regex>

using namespace std;

// functions declaration
void getInput();

int indexOf(string arr, char character);

bool checkIfPlusMinus(string complexNumber);

bool checkIfMultiplyDivide(string complexNumber);

void extractNumbersIfPlusMinus(string complexNumber);

void extractNumbersIfMultiplyDivide(string complexNumber);

void getFirstPartNumbers(string firstPart, double &real1, double &imag1);

void getSecondPartNumbers(string secondPart, double &real2, double &imag2);

void add(double real1, double imag1, double real2, double imag2);

void sub(double real1, double imag1, double real2, double imag2);

void multiplication(double real1, double real2, double imag1, double imag2);

void division(double real1, double real2, double imag1, double imag2);

// two complex numbers for testing
//string complexNum = "(-4421142-978883i)*(4421142+978883i)";
//string complexNum2 = "(42+9i)+(-404+971i)";

// a, c, b, d
double real1, real2, imag1, imag2;

// MAIN
int main() {

    cout << "\n*** Welcome to our Complex Numbers Calculator, we hope it helps you. ***\n\n";

    getInput();

    return 0;
}

// functions definition
void getInput() {

    cout << "Please enter the complex numbers in the form \"(a+bi)+(c+di)\"" << endl;
    cout << " -Only digits and signs and letter i (lower case) is allowed" << endl;
    cout << " -Without any spaces" << endl;
    cout << "Type \"Exit\" to exit" << endl;

    // user input
    string userComplexNumber;

    getline(cin, userComplexNumber);

    // check the sign and call the required function
    if (checkIfPlusMinus(userComplexNumber)) {

        extractNumbersIfPlusMinus(userComplexNumber);

    } else if (checkIfMultiplyDivide(userComplexNumber)) {

        extractNumbersIfMultiplyDivide(userComplexNumber);

    }
        // input the word exit to exit
    else if (userComplexNumber == "Exit" || userComplexNumber == "exit") {
        exit(0);
    }

    // get input again after all the functions are called and done the calculations
    getInput();

}

// function to get index of character from a string
int indexOf(string str, char character) {

    for (int i = 0; i < str.length(); i++) {

        if (character == str[i]) {
            return i;
        }

    }

    return 0;
}

// return true if the complex number is in the form (a+bi)+or-(c+di)
bool checkIfPlusMinus(string complexNumber) {

    regex complexCheckPlusMinus("[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][+-][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");

    return regex_match(complexNumber, complexCheckPlusMinus);
}

// return true if the complex number is in the form (a+bi)*or/(c+di)
bool checkIfMultiplyDivide(string complexNumber) {

    regex complexCheckMultiplyDivide(
            "[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][*/][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");

    return regex_match(complexNumber, complexCheckMultiplyDivide);
}

// this function splits the two brackets if the sign between them is +or-
// and make the sign-based operation
void extractNumbersIfPlusMinus(string complexNumber) {

//    char mainSign;
    int mainSignIndex;

    // search for the sign
    mainSignIndex = complexNumber.find(")+(");

    // not plus
    if (mainSignIndex == -1) {

        // search for the sign
        mainSignIndex = complexNumber.find(")-(");

        // not minus
        if (mainSignIndex == -1) {

            getInput();

            // minus
        } else {

//            mainSign = complexNumber[mainSignIndex + 1];

            // (a+bi)+(c+di)
            string firstPart = complexNumber.substr(1, mainSignIndex - 1); // a+bi
            string secondPart = complexNumber.substr(mainSignIndex + 3,
                                                     complexNumber.length() - mainSignIndex - 4); // c+di

//            cout << firstPart << endl;
//            cout << secondPart << endl;

            getFirstPartNumbers(firstPart, real1, imag1);
            getSecondPartNumbers(secondPart, real2, imag2);

            // apply the subtraction on the inputs
            sub(real1, imag1, real2, imag2);

        }

        // plus
    } else {

//        mainSign = complexNumber[mainSignIndex + 1];

        string firstPart = complexNumber.substr(1, mainSignIndex - 1); // a+bi
        string secondPart = complexNumber.substr(mainSignIndex + 3, complexNumber.length() - mainSignIndex - 4); // c+di

//            cout << firstPart << endl;
//            cout << secondPart << endl;

        getFirstPartNumbers(firstPart, real1, imag1);
        getSecondPartNumbers(secondPart, real2, imag2);

        // apply the addition on the inputs
        add(real1, imag1, real2, imag2);

    }

}

// this function splits the two brackets if the sign between them is *or/
// and make the sign-based operation
void extractNumbersIfMultiplyDivide(string complexNumber) {

//    char mainSign;
    int mainSignIndex;

    // search for the sign
    mainSignIndex = complexNumber.find(")*(");

    // not multiply
    if (mainSignIndex == -1) {

        // search for the sign
        mainSignIndex = complexNumber.find(")/(");

        // not divide
        if (mainSignIndex == -1) {

            getInput();

            //divide
        } else {

//            mainSign = complexNumber[mainSignIndex + 1];

            string firstPart = complexNumber.substr(1, mainSignIndex - 1); // a+bi
            string secondPart = complexNumber.substr(mainSignIndex + 3,
                                                     complexNumber.length() - mainSignIndex - 4); // c+di

//            cout << firstPart << endl;
//            cout << secondPart << endl;

            getFirstPartNumbers(firstPart, real1, imag1);
            getSecondPartNumbers(secondPart, real2, imag2);

            // apply the division on the inputs
            division(real1, real2, imag1, imag2);

        }

        // multiply
    } else {

//        mainSign = complexNumber[mainSignIndex + 1];

        string firstPart = complexNumber.substr(1, mainSignIndex - 1); // a+bi
        string secondPart = complexNumber.substr(mainSignIndex + 3, complexNumber.length() - mainSignIndex - 4); // c+di

//            cout << firstPart << endl;
//            cout << secondPart << endl;

        getFirstPartNumbers(firstPart, real1, imag1);
        getSecondPartNumbers(secondPart, real2, imag2);

        // apply the multiplication on the inputs
        multiplication(real1, real2, imag1, imag2);

    }

}

// this function splits the complex number from the first bracket
// and assign its components to the real1, imag1 variables to be known over the program
void getFirstPartNumbers(string firstPart, double &real1, double &imag1) {

    int signIndex;

    // search for the sign
    signIndex = firstPart.find("-", 1);

    // not minus
    if (signIndex == -1) {

        // search for the sign
        signIndex = firstPart.find("+");

        // get the real part
        string real = firstPart.substr(0, signIndex);
        // get the imaginary part
        string imag = firstPart.substr(signIndex + 1, indexOf(firstPart, 'i') - signIndex - 1);

//        cout << real << endl;
//        cout << imag << endl;

        // assign the double values
        real1 = stod(real);
        imag1 = stod(imag);

    }
        // minus
    else {

        // get the real part
        string real = firstPart.substr(0, signIndex);
        // get the imaginary part
        string imag = firstPart.substr(signIndex, indexOf(firstPart, 'i') - signIndex);

//        cout << real << endl;
//        cout << imag << endl;

        // assign the double values
        real1 = stod(real);
        imag1 = stod(imag);

    }

}

// this function splits the complex number from the second bracket
// and assign its components to the real2, imag2 variables to be known over the program
void getSecondPartNumbers(string secondPart, double &real2, double &imag2) {

    int signIndex;

    // search for the sign
    signIndex = secondPart.find("-", 1);

    // not minus
    if (signIndex == -1) {

        // search for the sign
        signIndex = secondPart.find("+");

        // get the real part
        string real = secondPart.substr(0, signIndex);
        // get the imaginary part
        string imag = secondPart.substr(signIndex + 1, indexOf(secondPart, 'i') - signIndex - 1);

//        cout << real << endl;
//        cout << imag << endl;

        // assign the double values
        real2 = stod(real);
        imag2 = stod(imag);

    }
        // minus
    else {

        // get the real part
        string real = secondPart.substr(0, signIndex);
        // get the imaginary part
        string imag = secondPart.substr(signIndex, indexOf(secondPart, 'i') - signIndex);

//        cout << real << endl;
//        cout << imag << endl;

        // assign the double values
        real2 = stod(real);
        imag2 = stod(imag);

    }

}

// addition function and prints the result
void add(double real1, double imag1, double real2, double imag2) {

    double real = (real1 + real2);
    double imag = (imag1 + imag2);

    if (imag < 0) {
        cout << " = (" << real << imag << "i" << ")" << endl;
    } else {
        cout << " = (" << real << "+" << imag << "i" << ")" << endl;
    }

}

// subtraction function and prints the result
void sub(double real1, double imag1, double real2, double imag2) {

    double real = (real1 - real2);
    double imag = (imag1 - imag2);

    if (imag < 0) {
        cout << " = (" << real << imag << "i" << ")" << endl;
    } else {
        cout << " = (" << real << "+" << imag << "i" << ")" << endl;
    }

}

// multiplication function and prints the result
void multiplication(double real1, double real2, double imag1, double imag2) {

    double real = (real1 * real2) - (imag1 * imag2);
    double imag = (real1 * imag2) + (real2 * imag1);

    if (imag > 0) {
        cout << " = (" << real << "+" << imag << "i" << ")" << endl;
    } else {
        cout << " = (" << real << imag << "i" << ")" << endl;
    }

}

// division function and prints the result
void division(double real1, double real2, double imag1, double imag2) {

    double real = ((real1 * real2) + (imag1 * imag2)) / ((real2 * real2) + (imag2 * imag2));
    double imag = (((real1 * (-imag2)) + (imag1 * real2)) / (((real2 * real2)) + (imag2 * imag2)));

    if (imag > 0) {
        cout << " = (" << real << "+" << imag << "i" << ")" << endl;
    } else {
        cout << " = (" << real << imag << "i" << ")" << endl;
    }

}

// End of the file