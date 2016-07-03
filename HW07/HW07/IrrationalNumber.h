/* 
 * File:   IrrationalNumber.h
 * Author: yasinacikgoz
 *
 * Created on December 15, 2015, 12:44 AM
 */

#ifndef IRRATIONALNUMBER_H
#define	IRRATIONALNUMBER_H

#include "ComplexNumber.h"

namespace _YasinAcikgoz{
    class IrrationalNumber: public RealNumber{

    public:
        IrrationalNumber(int num, int denum):RealNumber(num, denum){ /*deliberately empty*/ }

    };
}

#endif	/* IRRATIONAL_H */
