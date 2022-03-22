#include <iostream>
#include <regex>

using namespace std;

int indexOf(string arr, char character);

bool checkIfPlusMinus(string complexNumber);

bool checkIfMultiplyDivide(string complexNumber);

void extractNumbersIfPlusMinus(string complexNumber);

void extractNumbersIfMultiplyDivide(string complexNumber);

void getFirstPartNumbers(string firstPart, double &real1, double &imag1);

void getSecondPartNumbers(string secondPart, double &real2, double &imag2);

string complexNum = "(-4421142-978883i)*(4421142+978883i)";
string complexNum2 = "(42+9i)+(-404+971i)";

double real1, real2, imag1, imag2;

int main() {

    if (checkIfPlusMinus(complexNum2)) {

        extractNumbersIfPlusMinus(complexNum2);

    } else if (checkIfMultiplyDivide(complexNum2)) {

        extractNumbersIfMultiplyDivide(complexNum2);

    }

    return 0;
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

            // take input again

            cout << "Invalid";

            // minus
        } else {

//            mainSign = complexNumber[mainSignIndex + 1];

            string firstPart = complexNumber.substr(1, mainSignIndex - 1);
            string secondPart = complexNumber.substr(mainSignIndex + 3, complexNumber.length() - mainSignIndex - 4);

//            cout << firstPart << endl;
//            cout << secondPart << endl;

            getFirstPartNumbers(firstPart, real1, imag1);
            getSecondPartNumbers(secondPart, real2, imag2);

            // subtraction function here

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

            // take input again

            cout << "Invalid";

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