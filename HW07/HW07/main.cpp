/* 
 * File:   main.cpp
 * Author: yasinacikgoz
 * 
 *      CSE 241 HW 07
 * 
 * Created on December 14, 2015, 12:48 PM
 */

#include "ComplexNumber.h"
#include "RealNumber.h"
#include "ImaginaryNumber.h"
#include "RationalNumber.h"
#include "IrrationalNumber.h"
#include "Integer.h"
#include "NaturalNumber.h"

using namespace _YasinAcikgoz;

using namespace std;

int main(){
    /* objects */
    ComplexNumber complex1(-3,1,1,-4),complex2(7,-3),complex3;
    ImaginaryNumber imaginary2(5,2),imaginary1(3,-4), imaginary3(98);
    RealNumber real1(2),real2(5,2),real3;
    IrrationalNumber irrational1(1,3), irrational2(2,9), irrational3(33,-10);
    RationalNumber rational1(99,63), rational2(-25,35), rational3(1,-4);
    Integer integer1, integer2(-5), integer3(1145);
    NaturalNumber natural1, natural2(387), natural3(66);
    /* TEST */
    cout << "_________________________________________\n";
    cout << "TESTING '<' OPERATOR FOR COMPLEX NUMBERS.\n";
    if(complex1<complex2){
        cout << "(" << complex1.getRealUnitNumerator() << "/" << complex1.getRealUnitDenumerator() << ") + (";
        cout << complex1.getImaginaryUnitNumerator() << "/" << complex1.getImaginaryUnitDenumerator() << ")i is smaller than (";
        cout << complex2.getRealUnitNumerator() << "/" << complex2.getRealUnitDenumerator() << ") + (";
        cout << complex2.getImaginaryUnitNumerator() << "/" << complex2.getImaginaryUnitDenumerator() << ")i" << endl;
    }
    else{
        cout << "(" << complex1.getRealUnitNumerator() << "/" << complex1.getRealUnitDenumerator() << ") + (";
        cout << complex1.getImaginaryUnitNumerator() << "/" << complex1.getImaginaryUnitDenumerator() << ")i is greater or equal than (";
        cout << complex2.getRealUnitNumerator() << "/" << complex2.getRealUnitDenumerator() << ") + (";
        cout << complex2.getImaginaryUnitNumerator() << "/" << complex2.getImaginaryUnitDenumerator() << ")i" << endl;
    }
    cout << "\nTESTING '<' OPERATOR FOR IMAGINARY NUMBERS.\n";
    if(imaginary2<imaginary3){
        cout << "(" << imaginary2.getImaginaryUnitNumerator() << "/" << imaginary2.getImaginaryUnitDenumerator() << ")i is smaller than ";
        cout << "(" << imaginary3.getImaginaryUnitNumerator() << "/" << imaginary3.getImaginaryUnitDenumerator() << ")i" << endl;  
    }
    else{
        cout << "(" << imaginary2.getImaginaryUnitNumerator() << "/" << imaginary2.getImaginaryUnitDenumerator() << ")i is greater or equal than ";
        cout << "(" << imaginary3.getImaginaryUnitNumerator() << "/" << imaginary3.getImaginaryUnitDenumerator() << ")i" << endl;  
    }
    cout << "\nTESTING '<' OPERATOR FOR REAL NUMBERS.\n";
    if(real1<real2){
        cout << "(" << real1.getRealUnitNumerator() << "/" << real1.getRealUnitDenumerator() << ") is smaller than (";
        cout << real2.getRealUnitNumerator() << "/" << real2.getRealUnitDenumerator() << ")" << endl;
    }
    else{
        cout << "(" << real1.getRealUnitNumerator() << "/" << real1.getRealUnitDenumerator() << ") is greater or equal than (";
        cout << real2.getRealUnitNumerator() << "/" << real2.getRealUnitDenumerator() << ")" << endl;
    }
    cout << "\nTESTING '<' OPERATOR FOR RATIONAL NUMBERS.\n";
    if(rational1<rational2){
        cout << "(" << rational1.getRealUnitNumerator() << "/" << rational1.getRealUnitDenumerator() << ") is smaller than (";
        cout << rational2.getRealUnitNumerator() << "/" << rational2.getRealUnitDenumerator() << ")" << endl;
    }
    else{
        cout << "(" << rational1.getRealUnitNumerator() << "/" << rational1.getRealUnitDenumerator() << ") is greater or equal than (";
        cout << rational2.getRealUnitNumerator() << "/" << rational2.getRealUnitDenumerator() << ")" << endl;
    }
    cout << "\nTESTING '<' OPERATOR FOR IRRATIONAL NUMBERS.\n";
    if(irrational3<irrational2){
        cout << "(" << irrational3.getRealUnitNumerator() << "/" << irrational3.getRealUnitDenumerator() << ") is smaller than (";
        cout << irrational2.getRealUnitNumerator() << "/" << irrational2.getRealUnitDenumerator() << ")" << endl;
    }
    else{
        cout << "(" << irrational3.getRealUnitNumerator() << "/" << irrational3.getRealUnitDenumerator() << ") is greater or equal than (";
        cout << irrational2.getRealUnitNumerator() << "/" << irrational2.getRealUnitDenumerator() << ")" << endl;
    }
    cout << "\nTESTING '<' OPERATOR FOR INTEGERS.\n";
    if(integer1<integer2){
        cout << integer1.getRealUnitNumerator() << " is smaller than " << integer2.getRealUnitNumerator() << endl;
    }
    else{
        cout << integer1.getRealUnitNumerator() << " is greater or equal than " << integer2.getRealUnitNumerator() << endl;
    }
    cout << "\nTESTING '<' OPERATOR FOR NATURAL NUMBERS.\n";
    if(natural3<natural2){
        cout << natural3.getRealUnitNumerator() << " is smaller than " << natural2.getRealUnitNumerator() << endl;
    }
    else{
        cout << natural3.getRealUnitNumerator() << " is greater or equal than " << natural2.getRealUnitNumerator() << endl;
    }
    cout << "_________________________________________\n";
    cout << "TESTING '+' OPERATOR FOR COMPLEX NUMBERS.\n";
    complex1.printTester(complex2, '+');
    cout << complex1+complex2;
    
    cout << "\nTESTING '+' OPERATOR FOR IMAGINARY NUMBERS.\n";
    imaginary1.printTester(imaginary2, '+');
    cout << imaginary1+imaginary2;
    
    cout << "\nTESTING '+' OPERATOR FOR REAL NUMBERS.\n";
    real3.printTester(real2,'+');
    cout << real3+real2;
    
    cout << "\nTESTING '+' OPERATOR FOR RATIONAL NUMBERS.\n";
    rational1.printTester(rational2,'+');
    cout << rational1+rational2;
    
    cout << "\nTESTING '+' OPERATOR FOR IRRATIONAL NUMBERS.\n";
    irrational1.printTester(irrational2,'+');
    cout << irrational1+irrational2;
    
    cout << "\nTESTING '+' OPERATOR FOR INTEGERS.\n";
    integer1.printTester(integer2, '+');
    cout << integer1+integer2;
    
    cout << "\nTESTING '+' OPERATOR FOR NATURAL NUMBERS.\n";
    natural1.printTester(natural2, '+');
    cout << natural1+natural2;
    
    cout << "_________________________________________\n";
    cout << "TESTING '-' OPERATOR FOR COMPLEX NUMBERS.\n";
    complex2.printTester(complex3, '-');
    cout << complex2-complex3;
    
    cout << "\nTESTING '-' OPERATOR FOR IMAGINARY NUMBERS.\n";
    imaginary2.printTester(imaginary3, '-');
    cout << imaginary2-imaginary3;
    
    cout << "\nTESTING '-' OPERATOR FOR REAL NUMBERS.\n";
    real1.printTester(real2,'-');
    cout << real1-real2;
    
    cout << "\nTESTING '-' OPERATOR FOR RATIONAL NUMBERS.\n";
    rational2.printTester(rational3, '-');
    cout << rational2-rational3;
    
    cout << "\nTESTING '-' OPERATOR FOR IRRATIONAL NUMBERS.\n";
    irrational1.printTester(irrational3,'-');
    cout << irrational1+irrational3;
    
    cout << "\nTESTING '-' OPERATOR FOR INTEGERS.\n";
    integer2.printTester(integer3, '-');
    cout << integer2-integer3;
    
    cout << "\nTESTING '-' OPERATOR FOR NATURAL NUMBERS.\n";
    natural1.printTester(natural3, '-');
    cout << natural1+natural3;
    return 0;
}

