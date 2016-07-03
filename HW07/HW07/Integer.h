/* 
 * File:   Integer.h
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 1:31 PM
 */

#ifndef INTEGER_H
#define	INTEGER_H

#include "RationalNumber.h"

namespace _YasinAcikgoz{
    class Integer : public RationalNumber{

    public:
        /* integer sayiya 1 initilize eder*/
        Integer():RationalNumber(1){ /*deliberately empty*/ }

        /* integer sayiya num initilize eder*/
        Integer(int num):RationalNumber(num){ /*deliberately empty*/ }
    };
}
#endif	/* INTEGER_H */

