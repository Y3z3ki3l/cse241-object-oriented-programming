/* 
 * File:   NaturalNumber.h
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 1:33 PM
 */

#ifndef NATURALNUMBER_H
#define	NATURALNUMBER_H

#include "Integer.h"

namespace _YasinAcikgoz{
    
    class NaturalNumber : public Integer{

    public:
        /* dogal sayiya 1 initilize eder.*/
        NaturalNumber():Integer(1){ /*deliberately empty*/ }

        /* dogal sayiya num initilize eder.*/
        NaturalNumber(int num):Integer(num){ setNaturalNumber(num); }

        /* 
         *      gelen number degerinin 0'dan kucuk (dogal sayi) olup olmadigini kontrol eder.
         *      number sifirdan kucukse hata verip programi kapatir.
         */
        void setNaturalNumber(int number);
    };
}
#endif	/* NATURALNUMBER_H */

