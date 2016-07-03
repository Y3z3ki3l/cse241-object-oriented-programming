/* 
 * File:   ComplexNumber.h
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 12:52 PM
 */
#include <iostream>
#include <cmath>
#include <cstdlib>

#ifndef COMPLEXNUMBER_H
#define	COMPLEXNUMBER_H

using namespace std;
namespace _YasinAcikgoz{
    class ComplexNumber{

    public:
        ComplexNumber();
        ComplexNumber(int rNum, int iNum);
        ComplexNumber(int rNum, int rDenum, int iNum, int iDenum);
        //getters
        int getRealUnitNumerator()const{ return realUnitNumerator;}
        int getRealUnitDenumerator()const{ return realUnitDenumerator;} 
        int getImaginaryUnitNumerator()const{ return imaginaryUnitNumerator;}
        int getImaginaryUnitDenumerator()const{ return imaginaryUnitDenumerator;}
        //setters
        void setRealUnitNumerator(const int rNumerator); 
        void setRealUnitDenumerator(const int rDenumerator);
        void setImaginaryUnitNumerator(const int iNumerator); 
        void setImaginaryUnitDenumerator(const int iDenumerator);
        void setRealUnit(const int rNumerator, const int rDenumerator);
        void setImaginaryUnit(const int iNumerator, const int iDenumerator);
        const ComplexNumber operator +(const ComplexNumber& object)const;
        const ComplexNumber operator -(const ComplexNumber& object)const;
        bool operator <(const ComplexNumber& object) const;
        friend ostream& operator<<(ostream& outputStream, const ComplexNumber& object);
        void printTester(const ComplexNumber& second, const char sign)const;

    protected:
        int simplificateNumbers(int firstNum, int secondNum)const;

    private:
        double realUnitNumerator;
        double realUnitDenumerator;
        double imaginaryUnitNumerator;
        double imaginaryUnitDenumerator;
    };
}

#endif	/* COMPLEXNUMBER_H */

