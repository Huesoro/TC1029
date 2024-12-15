#pragma once

// write the Fraction class header here

class Fraction {
    private:
        int numerator;
        int denominator;

        public:
            void setNum(int);
            void setDen(int);
            int getNum();
            int getDen();
            void print();
            Fraction();
            Fraction(int, int);
            Fraction sum(Fraction);
            double calcRealValue();
};