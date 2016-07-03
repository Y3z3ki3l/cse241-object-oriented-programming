/* 
 * File:   RealNumber.h
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 1:15 PM
 */

#ifndef REALNUMBER_H
#define	REALNUMBER_H

#include "ComplexNumber.h"

namespace _YasinAcikgoz{
    class RealNumber : public ComplexNumber{
    public:
        /*sayinin reel kismina 1, imajinel kismina 0 initilize eder.*/
        RealNumber(): ComplexNumber(1,0){ /*deliberately empty*/ }

        /*sayinin reel kisminin payina num, paydasina denum, imajinel kismina ise 0 initilize eder.*/
        RealNumber(int num, int denum): ComplexNumber(num, denum, 0, 1){ /*deliberately empty*/ }

        /*sayinin reel kismina num, imajinel kismina 0 initilize eder.*/
        RealNumber(int num): ComplexNumber(num, 0){ /*deliberately empty*/ }

        /*  
         *      reel sayilar kumesi icin kucuktur operatoru.
         *      fonksiyon gelen reel sayilarin paydalarini esitler
         *      ardindan ilk sayi ikinci sayidan kucuk ise true
         *      buyuk veya edit ise false return eder.
         * 
         */
        bool operator <(const RealNumber& object)const;
    };
}
#endif	/* REALNUMBER_H */

