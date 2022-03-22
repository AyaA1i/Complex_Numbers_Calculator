#include <iostream>
#include <regex>

using namespace std;

// get index of character in char array , string
int indexOf(string arr, char character) {

    for (int i = 0; i < arr.length(); i++) {

        if (character == arr[i]) {
            return i;
        }

    }

    return 0;
}

int main() {

    string complexNum = "(4421142-978883i)+(4421142+978883i)";

    regex complexCheckPlusMinus ("[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][+-][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");
    regex complexCheckMultiplyDivide ("[(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)][*/][(][+-]*[0-9]+(.[0-9]+)*[+-]+[0-9]+i[)]");

    cout << regex_match(complexNum, complexCheckPlusMinus);
    cout << regex_match(complexNum, complexCheckMultiplyDivide);

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


    return 0;
}
