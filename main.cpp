/*

--FCAI_CU - Programming 1 - 2022 - Assignment 2--

Program Name: Complex Number Calculator
Description: This program takes complex numbers in the form "(a+bi)+(c+di)" and calculates the entered problem.
Purpose: Make operations on complex numbers
Author: Youssef Moataz
Last Modification Date: March 23, 2022.
Version: v1.4.0

*/

#include <iostream>
#include <regex>

using namespace std;

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

//string complexNum = "(-4421142-978883i)*(4421142+978883i)";
//string complexNum2 = "(42+9i)+(-404+971i)";

double real1, real2, imag1, imag2;

int main() {

    cout << "\n*** Welcome to our Complex Numbers Calculator, we hope it helps you. ***\n\n";

    getInput();

    return 0;
}

void getInput() {

    cout << "Please enter the complex numbers in the form \"(a+bi)+(c+di)\"" << endl;
    cout << " -Only digits and signs and letter i (lower case) is allowed" << endl;
    cout << " -Without any spaces" << endl;
    cout << "Type \"Exit\" to exit" << endl;

    string userComplexNumber;

    getline(cin, userComplexNumber);

    if (checkIfPlusMinus(userComplexNumber)) {

        extractNumbersIfPlusMinus(userComplexNumber);

    } else if (checkIfMultiplyDivide(userComplexNumber)) {

        extractNumbersIfMultiplyDivide(userComplexNumber);

    } else if (userComplexNumber == "Exit"){
        exit(0);
    }

    getInput();

}

int indexOf(string arr, char character) {

    for (int i = 0; i < arr.length(); i++) {

        if (character == arr[i]) {
            return i;
        }

    }

    return 0;
}

bool checkIfPlusMinus(string complexNumber) {

    regex complexCheckPlusMinus("[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][+-][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");

    return regex_match(complexNumber, complexCheckPlusMinus);
}

bool checkIfMultiplyDivide(string complexNumber) {

    regex complexCheckMultiplyDivide(
            "[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][*/][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");

    return regex_match(complexNumber, complexCheckMultiplyDivide);
}


void extractNumbersIfPlusMinus(string complexNumber) {

//    char mainSign;
    int mainSignIndex;

    mainSignIndex = complexNumber.find(")+(");

    // not plus
    if (mainSignIndex == -1) {

        mainSignIndex = complexNumber.find(")-(");

        // not minus
        if (mainSignIndex == -1) {

            getInput();

            // minus
        } else {

//            mainSign = complexNumber[mainSignIndex + 1];

            // (a+bi)+(c+di)
            string firstPart = complexNumber.substr(1, mainSignIndex - 1);
            string secondPart = complexNumber.substr(mainSignIndex + 3, complexNumber.length() - mainSignIndex - 4);

//            cout << firstPart << endl;
//            cout << secondPart << endl;

            getFirstPartNumbers(firstPart, real1, imag1);
            getSecondPartNumbers(secondPart, real2, imag2);

            // subtraction function here

            sub(real1, imag1, real2, imag2);

        }

        // plus
    } else {

//        mainSign = complexNumber[mainSignIndex + 1];

        string firstPart = complexNumber.substr(1, mainSignIndex - 1);
        string secondPart = complexNumber.substr(mainSignIndex + 3, complexNumber.length() - mainSignIndex - 4);

//            cout << firstPart << endl;
//            cout << secondPart << endl;

        getFirstPartNumbers(firstPart, real1, imag1);
        getSecondPartNumbers(secondPart, real2, imag2);

        // addition function here

        add(real1, imag1, real2, imag2);

    }

}

void extractNumbersIfMultiplyDivide(string complexNumber) {

//    char mainSign;
    int mainSignIndex;

    mainSignIndex = complexNumber.find(")*(");

    // not multiply
    if (mainSignIndex == -1) {

        mainSignIndex = complexNumber.find(")/(");

        // not divide
        if (mainSignIndex == -1) {

            getInput();

            // divide
        } else {

//            mainSign = complexNumber[mainSignIndex + 1];

            string firstPart = complexNumber.substr(1, mainSignIndex - 1);
            string secondPart = complexNumber.substr(mainSignIndex + 3, complexNumber.length() - mainSignIndex - 4);

//            cout << firstPart << endl;
//            cout << secondPart << endl;

            getFirstPartNumbers(firstPart, real1, imag1);
            getSecondPartNumbers(secondPart, real2, imag2);

            // division function here

        }

        // multiply
    } else {

//        mainSign = complexNumber[mainSignIndex + 1];

        string firstPart = complexNumber.substr(1, mainSignIndex - 1);
        string secondPart = complexNumber.substr(mainSignIndex + 3, complexNumber.length() - mainSignIndex - 4);

//            cout << firstPart << endl;
//            cout << secondPart << endl;

        getFirstPartNumbers(firstPart, real1, imag1);
        getSecondPartNumbers(secondPart, real2, imag2);

        // multiplication function here

    }

}

void getFirstPartNumbers(string firstPart, double &real1, double &imag1) {

    int signIndex;

    signIndex = firstPart.find("-", 1);

    if (signIndex == -1) {

        signIndex = firstPart.find("+");

        string real = firstPart.substr(0, signIndex);
        string imag = firstPart.substr(signIndex + 1, indexOf(firstPart, 'i') - signIndex - 1);

        cout << real << endl;
        cout << imag << endl;

        real1 = stod(real);
        imag1 = stod(imag);

    } else {

        string real = firstPart.substr(0, signIndex);
        string imag = firstPart.substr(signIndex, indexOf(firstPart, 'i') - signIndex);

        cout << real << endl;
        cout << imag << endl;

        real1 = stod(real);
        imag1 = stod(imag);

    }

}

void getSecondPartNumbers(string secondPart, double &real2, double &imag2) {

    int signIndex;

    signIndex = secondPart.find("-", 1);

    if (signIndex == -1) {

        signIndex = secondPart.find("+");

        string real = secondPart.substr(0, signIndex);
        string imag = secondPart.substr(signIndex + 1, indexOf(secondPart, 'i') - signIndex - 1);

        cout << real << endl;
        cout << imag << endl;

        real2 = stod(real);
        imag2 = stod(imag);

    } else {

        string real = secondPart.substr(0, signIndex);
        string imag = secondPart.substr(signIndex, indexOf(secondPart, 'i') - signIndex);

        cout << real << endl;
        cout << imag << endl;

        real2 = stod(real);
        imag2 = stod(imag);

    }

}

void add(double real1, double imag1, double real2, double imag2) {

    double real = (real1 + real2);
    double imag = (imag1 + imag2);

    if (imag < 0){
        cout << real << imag << "i" << endl;
    }else{
        cout << real << "+" << imag << "i" << endl;
    }

}

void sub(double real1, double imag1, double real2, double imag2) {
    double real = (real1 - real2);
    double imag = (imag1 - imag2);

    if (imag < 0){
        cout << real << imag << "i" << endl;
    }else{
        cout << real << "+" << imag << "i" << endl;
    }

}