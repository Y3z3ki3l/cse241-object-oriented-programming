/* 
 * File:   ComplexNumber.cpp
 * Author: yasinacikgoz
 *
 * Created on December 14, 2015, 12:52 PM
 */
#include "ComplexNumber.h"

using namespace std;
namespace _YasinAcikgoz{
    /* reel kismin pay, paydasina ve imajinel kismin pay, paydasina 1 initilize eder. */
    ComplexNumber::ComplexNumber(){
        setRealUnit(1,1);
        setImaginaryUnit(1,1);
    }

    /* reel kismin payina rNum, imajinel kismin paydasina iNum, paydalara ise 1 initilize eder. */
    ComplexNumber::ComplexNumber(int rNum, int iNum):realUnitDenumerator(1), imaginaryUnitDenumerator(1){
        setRealUnitNumerator(rNum);
        setImaginaryUnitNumerator(iNum);
    }

    /* reel kismin payina rNum, paydasina rDenum, imajinel kismin paydasina iNum, paydasina ise iDenum initilize eder. */
    ComplexNumber::ComplexNumber(int rNum, int rDenum, int iNum, int iDenum){
        setRealUnit(rNum, rDenum);
        setImaginaryUnit(iNum,iDenum);
    }
    /* 
     *      reel kismin payi ve paydasi negatif ise mutlak degerini alip pozitife cevirir.
     *      reel kismin paydasi negatifse payda esitleme sirasinda sorun olmamasi icin paydayi pozitif payi negatif yapar.
     *      ustteki durumlar olusmadiginda reel kismin payini paydasini set eder.
     */
    void ComplexNumber::setRealUnit(const int rNumerator, const int rDenumerator){
        if(rNumerator<0 && rDenumerator<0){
            setRealUnitNumerator(-1*(rNumerator));
            setRealUnitDenumerator(-1*(rDenumerator));
        }
        else if(rDenumerator<0){ 
            setRealUnitNumerator(-1*(rNumerator));
            setRealUnitDenumerator(-1*(rDenumerator));
        }
        else{
            setRealUnitNumerator(rNumerator);
            setRealUnitDenumerator(rDenumerator);
        }
    }
    /* 
     *      imajinel kismin payi ve paydasi negatif ise mutlak degerini alip pozitife cevirir.
     *      imajinel kismin paydasi negatifse payda esitleme sirasinda sorun olmamasi icin paydayi pozitif payi negatif yapar.
     *      ustteki durumlar olusmadiginda imajinel  kismin payini paydasini set eder.
     */
    void ComplexNumber::setImaginaryUnit(const int iNumerator, const int iDenumerator){
        if(iNumerator<0 && iDenumerator<0){
            setImaginaryUnitNumerator(-1*(iNumerator));
            setImaginaryUnitDenumerator(abs(iDenumerator));
        }
        else if(iDenumerator<0){
            setImaginaryUnitNumerator(-1*(iNumerator));
            setImaginaryUnitDenumerator(-1*(iDenumerator));
        }
        else{
            setImaginaryUnitNumerator(iNumerator);
            setImaginaryUnitDenumerator(iDenumerator);
        }

    }
    /* reel kismin payini set eder. */
    void ComplexNumber::setRealUnitNumerator(const int rNumerator){
        realUnitNumerator=rNumerator;
    }
    /* reel kismin paydasini set eder. gelen deger sifirsa hata verip programi kapatir.*/
    void ComplexNumber::setRealUnitDenumerator(const int rDenumerator){
        if(rDenumerator==0){
            cerr << "Negative denominator error!" << endl;
            exit(1);
        }
        realUnitDenumerator=rDenumerator;
    }
    /* imajinel kismin payini set eder. */
    void ComplexNumber::setImaginaryUnitNumerator(const int iNumerator){
        imaginaryUnitNumerator=iNumerator;
    }
    /* imajinel kismin paydasini set eder. gelen deger sifirsa hata verip programi kapatir.*/
    void ComplexNumber::setImaginaryUnitDenumerator(const int iDenumerator){
        if(iDenumerator==0){
            cerr << "Negative denominator error!" << endl;
            exit(1);
        }
        imaginaryUnitDenumerator=iDenumerator;
    }
    /*
     * 
     *      complex sayilar icin toplama operatoru
     *      2 complex sayinin reel kisimini ve imajinel kisimini payda esitleyerek toplar
     *      eger reel ve imajinel kisimlarda sadelestirme mumkunse yardimci fonksiyonun 
     *      return degerini kullanir ve ComplexNumber objesi return eder.     
     * 
     */
    const ComplexNumber ComplexNumber::operator +(const ComplexNumber& object)const{
        int numA, numB, denumA, denumB, simpA, simpB;

        numA=getRealUnitNumerator()*object.getRealUnitDenumerator()+object.getRealUnitNumerator()*getRealUnitDenumerator();
        numB=getImaginaryUnitNumerator()*object.getImaginaryUnitDenumerator()+object.getImaginaryUnitNumerator()*getImaginaryUnitDenumerator();

        denumA=getRealUnitDenumerator()*object.getRealUnitDenumerator();
        denumB=getImaginaryUnitDenumerator()*object.getImaginaryUnitDenumerator();

        simpA=simplificateNumbers(numA, denumA);
        simpB=simplificateNumbers(numB, denumB);

        return ComplexNumber(numA/simpA, denumA/simpA, numB/simpB, denumB/simpB);
    }
    /*
     * 
     *      complex sayilar icin cikarma operatoru
     *      2 complex sayinin reel kisimini ve imajinel kisimini payda esitleyerek birbirinden cikarir
     *      eger reel ve imajinel kisimlarda sadelestirme mumkunse yardimci fonksiyonun 
     *      return degerini kullanir ve ComplexNumber objesi return eder.     
     * 
     */
    const ComplexNumber ComplexNumber::operator -(const ComplexNumber& object)const{
        int numA, numB, denumA, denumB, simpA, simpB;

        numA=getRealUnitNumerator()*object.getRealUnitDenumerator()-object.getRealUnitNumerator()*getRealUnitDenumerator();
        numB=getImaginaryUnitNumerator()*object.getImaginaryUnitDenumerator()-object.getImaginaryUnitNumerator()*getImaginaryUnitDenumerator();

        denumA=getRealUnitDenumerator()*object.getRealUnitDenumerator();
        denumB=getImaginaryUnitDenumerator()*object.getImaginaryUnitDenumerator();
        
        simpA=simplificateNumbers(numA, denumA);
        simpB=simplificateNumbers(numB, denumB);
        return ComplexNumber(numA/simpA, denumA/simpA, numB/simpB, denumB/simpB);   
    }
    /*
     *      kucuktur operatoru
     *      karmasik sayilarin modullerini hesaplayarak kiyaslayan fonksiyon
     *      1. sayinin modulu 2. sayinin modulunden kucukse true, diger durumda false return eder.
     * 
     */
    bool ComplexNumber::operator <(const ComplexNumber& object)const{
        double modulusA, modulusB;

        modulusA=sqrt(pow(getRealUnitNumerator()/getRealUnitDenumerator(), 2)+pow(getImaginaryUnitNumerator()/getImaginaryUnitDenumerator(),2));
        modulusB=sqrt(pow(object.getRealUnitNumerator()/object.getRealUnitDenumerator(), 2)+pow(object.getImaginaryUnitNumerator()/object.getImaginaryUnitDenumerator(),2));

        if(modulusA<modulusB)
            return true;
        else
            return false;
    }
    /*
     *      stream insertion operator
     *      gelen objenin reel kismini ve imajinel kismini formatlayarak ostream'e yazan fonksiyon
     * 
     */
    ostream& operator<<(ostream& outputStream, const ComplexNumber& object){
        char sign='+';
        if(object.getImaginaryUnitNumerator()<0)
            sign=' ';

        if(object.getRealUnitNumerator()==0 && object.getImaginaryUnitNumerator()==0)
            outputStream << object.getRealUnitNumerator() << endl;

        else if(object.getRealUnitNumerator()==0 && object.getImaginaryUnitDenumerator()==1)
            outputStream << object.getImaginaryUnitNumerator() << "i" << endl;

        else if(object.getRealUnitDenumerator()==1 && object.getImaginaryUnitNumerator()==0)
            outputStream << object.getRealUnitNumerator() << endl;

        else if(object.getRealUnitNumerator()==0)
            outputStream << "(" << object.getImaginaryUnitNumerator() << "/" << object.getImaginaryUnitDenumerator() << ")i" << endl;

        else if(object.getImaginaryUnitNumerator()==0)
            outputStream << object.getRealUnitNumerator() << "/" << object.getRealUnitDenumerator()<< endl;

        else if(object.getImaginaryUnitDenumerator()==1 && object.getRealUnitDenumerator()==1)
            outputStream << object.getRealUnitNumerator() << sign  << object.getImaginaryUnitNumerator() << "i" << endl;

        else if(object.getImaginaryUnitDenumerator()==1)
            outputStream << "(" << object.getRealUnitNumerator() << "/" << object.getRealUnitDenumerator()<< ")" << sign  << object.getImaginaryUnitNumerator() << "i" << endl;

        else if(object.getRealUnitDenumerator()==1)    
            outputStream << object.getRealUnitNumerator() << sign  << "(" << object.getImaginaryUnitNumerator() << "/" << object.getImaginaryUnitDenumerator() << ")i" << endl;

        else 
            outputStream << object.getRealUnitNumerator() << "/" << object.getRealUnitDenumerator()<< sign  << object.getImaginaryUnitNumerator() << "/" << object.getImaginaryUnitDenumerator() << "i" << endl;

        return outputStream;
    }
    /*
     *      iki sayinin en buyuk ortak bolenini bulup return eden fonksiyon
     * 
     */
    int ComplexNumber::simplificateNumbers(int firstNum, int secondNum)const{
        int num=1;

        if(firstNum<0)
            firstNum=firstNum*-1;
        if(secondNum<0)
            secondNum=secondNum*-1;
        if(firstNum>secondNum){
            for(int i=2; i<=secondNum; ++i){
                if(firstNum%i==0 && secondNum%i==0)
                    num=i;
            }
        }
        else if(secondNum>firstNum){
            for(int i=2; i<=firstNum; ++i){
                if(firstNum%i==0 && secondNum%i==0)
                    num=i;
            }
        }
        else
            num=firstNum;
        return num;
    }
    /*
     * 
     *      test fonksiyonunda kolaylik saglamasi icin yazdigim print fonksiyonu
     *      obje olusturulurken girilen degerleri default olarak ekrana basar.
     * 
     */
    void ComplexNumber::printTester(const ComplexNumber& second, const char sign) const{
        cout << "(" << getRealUnitNumerator() << "/" <<getRealUnitDenumerator() << ") + (";
        cout << getImaginaryUnitNumerator() << "/" << getImaginaryUnitDenumerator() << ")i " << sign << " (";
        cout << second.getRealUnitNumerator() << "/" << second.getRealUnitDenumerator() << ") + (";
        cout << second.getImaginaryUnitNumerator() << "/" << second.getImaginaryUnitDenumerator() << ")i" << "  =  "; 
    }
}