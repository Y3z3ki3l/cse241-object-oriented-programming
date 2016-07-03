/* 
 * File:   Rational.h
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 1:28 PM
 */

#ifndef RATIONAL_H
#define	RATIONAL_H

#include "RealNumber.h"

namespace _YasinAcikgoz{
    class RationalNumber : public RealNumber{
    public:
        /* rasyonel sayiya 1/1 initilize eder.*/
        RationalNumber(): RealNumber(){ /*deliberately empty*/ }

        /* rasyonel sayiya 1 initilize eder.*/
        RationalNumber(int num): RealNumber(num){ /*deliberately empty*/ }

        /* rasyonel sayinin payina num, paydasina denum initilize eder.*/
        RationalNumber(int num, int denum): RealNumber(num,denum){ /*deliberately empty*/ }
    }; 
}

#endif	/* RATIONAL_H */

