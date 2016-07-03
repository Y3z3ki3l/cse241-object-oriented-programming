/* 
 * File:   NaturalNumber.cpp
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 12:52 PM
 */
#include "NaturalNumber.h"

namespace _YasinAcikgoz{
    void NaturalNumber::setNaturalNumber(int number){
        if(number<0){
            cerr << "Natural number error. Negative value!\n";
            exit(1);
        }
        setRealUnit(number,1); 
    }
}