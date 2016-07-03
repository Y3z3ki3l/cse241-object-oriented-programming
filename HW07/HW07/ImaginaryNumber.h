/* 
 * File:   ImaginaryNumber.h
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 1:03 PM
 */

#ifndef IMAGINARYNUMBER_H
#define	IMAGINARYNUMBER_H

#include "ComplexNumber.h"
namespace _YasinAcikgoz{
    class ImaginaryNumber: public ComplexNumber{

    public:
        /* karmasik sayinin imajinel kismina 1, reel kismina 0 initilize eder.*/
        ImaginaryNumber(): ComplexNumber(0,1){ /*deliberately empty*/ }

        /* karmasik sayinin imajinel kismina num, reel kismina 0 initilize eder.*/
        ImaginaryNumber(int num): ComplexNumber(0, num){ /*deliberately empty*/ }

        /* karmasik sayinin imajinel kisminin payina num, paydasina denum, reel kismina 0 initilize eder.*/
        ImaginaryNumber(int num, int denum): ComplexNumber(0, 1, num, denum) { /*deliberately empty*/ }

    };
}
#endif	/* IMAGINARYNUMBER_H */

