// complete the Fraction methods here

#include <iostream>
using namespace std;

#include "Fraction.hpp"

// complete the class fractions methods here


Fraction::Fraction(int _numerator, int _denominator){
    numerator = _numerator;
    denominator = _denominator;
};

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
};

void Fraction::setNum(int _numerator){
    numerator = _numerator;
};

void Fraction::setDen(int _denominator){
    denominator = _denominator;
};  

int Fraction::getNum(){
    return numerator;
};


int Fraction::getDen(){
    return denominator;
};

void Fraction::print(){
    cout << numerator << "/" << denominator << endl;
};

Fraction Fraction::sum(Fraction fraction2){
    Fraction result;
    result.numerator = numerator * fraction2.denominator + fraction2.numerator * denominator;
    result.denominator = denominator * fraction2.denominator;
    return result;
};

double Fraction::calcRealValue(){
    return (double)numerator / (double)denominator;
};

