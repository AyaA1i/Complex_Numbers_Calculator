#include <iostream>
#include <regex>

using namespace std;

int indexOf(string arr, char character);
bool checkIfPlusMinus(string complexNumber);
bool checkIfMultiplyDivide(string complexNumber);

int main() {

    string complexNum = "(4421142-978883i)/(4421142+978883i)";

//    int x = complexNum.find("-");
//
//
//    string real = complexNum.substr(0, x);
//
//    cout << real << endl;
//
//    string imag = complexNum.substr(x, indexOf(complexNum, 'i') - x);
//
//    cout << imag << endl;

    if (checkIfPlusMinus(complexNum)){
        cout << "Plus Minus";
    }else if(checkIfMultiplyDivide(complexNum)){
        cout << "Multiply divide";
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

bool checkIfPlusMinus(string complexNumber){

    regex complexCheckPlusMinus ("[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][+-][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");

    return regex_match(complexNumber, complexCheckPlusMinus);
}

bool checkIfMultiplyDivide(string complexNumber){

    regex complexCheckMultiplyDivide ("[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][*/][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");

    return regex_match(complexNumber, complexCheckMultiplyDivide);
}
