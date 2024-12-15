#include <iostream>
#include <fstream>
using namespace std;

#include "Fraction.hpp"

//Read fractions from a file
//the function modifies the array and the size parameter

void readFromFileToArray(string fileName, Fraction array[], int &size){
    ifstream file;
    file.open(fileName.c_str());
    int num, den;
    size = 0;
    while (file >> num >> den){
        Fraction f(num, den);
        array[size] = f;
        size++;
    }
    file.close();
}

int main () {

	// write the code to complete the exercise
    Fraction list1[10], list2[10], list3[10];
    int size1, size2, sizeList;

    //Read information from file1 to put it in list1
    readFromFileToArray("file1.txt", list1, size1);
    cout << "Size of list1: " << size1 << endl;
    readFromFileToArray("file2.txt", list2, size2);
    readFromFileToArray("file3.txt", list3, sizeList);



    return 0;
}
