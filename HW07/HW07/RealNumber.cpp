/* 
 * File:   RealNumber.cpp
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 12:52 PM
 */
#include "RealNumber.h"

namespace _YasinAcikgoz{
    bool RealNumber:: operator <(const RealNumber& object)const{
        int first=getRealUnitNumerator()*object.getRealUnitDenumerator();
        int second=object.getRealUnitNumerator()*getRealUnitDenumerator();

        if(first<second)
            return true;
        else
            return false;
    }
}