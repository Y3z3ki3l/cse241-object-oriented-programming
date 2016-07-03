/*
*	Yasin Acikgoz 131044070
*
*	  BIL 241 Fall2015 HW3
*
*/
/*		START OF MAIN.CPP 	*/
/*Includelar*/
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//PI sayisi
const double PI=3.14159265;
//90 derecelik dik aci degiskeni
const int rightAngle=90;

//Triangle Classi
class Triangle
{
public:
	//default constructor
	Triangle( );
	//1 parametre alan constructor. tum koselere ayni uzunluk degerini atar
	Triangle (double param);
	//2 parametre alan constructor. C kosesine 1 degerini atar.
	Triangle (double paramA, double paramB);
	//3 parametre alan constructor
	Triangle (double paramA, double paramB, double paramC);

	//Getterlar
	double getA() const {return A;}
	double getB() const {return B;}
	double getC() const {return C;}
	//Setterlar
	void setA(double a);
	void setB(double b);
	void setC(double c);
	void setABC (double a, double b, double c);
	//kullanicidan input alan fonksiyon
	void input();
	//ekrana output yazan fonksiyon
	void output() const;
	//ucgenin dik acili olup olmadigini kontrol eden fonksiyon
	bool isRightAngleTriangle() const;
	/*
	*	Cosinus teoremini kullanarak ucgenin her bir acisini bulup return eden fonksiyonlar
	*/
	double calculateAngleA() const;
	double calculateAngleB() const;
	double calculateAngleC() const;
	/*
	*	Sinuslu alan teoremini kullanarak ucgenin iki kenar ve bu iki kenarin arasindaki aciyi alarak ucgenin alanini hesaplayan fonksiyon
	*	sin(a) A kosesindeki acinin sinusu olmak uzere => Alan(ABC)=1/2*(B*C*sin(a))
	*/
	double calculateArea() const{ return (0.5)*(getB()*getC()*sin(calculateAngleA()*PI/180)); }
	/*
	*	Ucgenin kenar uzunluklarini toplayarak cevresini hesaplayan fonksiyon
	*	Cevre(ABC)=A+B+C
	*/
	double calculatePerimeter() const { return getA() + getB() + getC(); }

private:
	//Kenar uzunluklarini tutan degiskenler		
	double A;
	double B;
	double C;
};
//tester fonksiyonlari
void testerCallByValue(Triangle triangle);

void testerCallByReference(Triangle &triangle);
/*		START OF MAIN 		*/
int main(){
	//objeleri olustur
	Triangle triangle, triangle1(1.2), triangle2(2,2), triangle3(4, 5, 3);
	//ekrani temizle
	system("clear");
	//TESTER FONKSİYON CAGRILARI
	cout << "----------------------------\n";
	cout << "First terster for 'triangle' object. (CALL BY REFERENCE)\n";
	triangle.input(); //input alan fonksiyonu cagir
	testerCallByReference(triangle);

	cout << "----------------------------\n";
	cout << "Second terster for 'triangle3' object. (CALL BY REFERENCE)\n";
	testerCallByReference(triangle3);

	cout << "----------------------------\n";
	cout << "First terster for 'triangle1' object. (CALL BY VALUE)\n";
	testerCallByValue(triangle1);

	cout << "----------------------------\n";
	cout << "Second terster for 'triangle2' object. (CALL BY VALUE)\n";
	testerCallByValue(triangle2);

	return (0);
}
//TESTER FONKSİYONLAR
void testerCallByReference(Triangle &triangle){
	triangle.calculateAngleA(); 
	triangle.calculateAngleB();
	triangle.calculateAngleC();
	triangle.calculateArea();
	triangle.calculatePerimeter();
	triangle.output();
}
void testerCallByValue(Triangle triangle){
	triangle.calculateAngleA(); 
	triangle.calculateAngleB();
	triangle.calculateAngleC();
	triangle.calculateArea();
	triangle.calculatePerimeter();
	triangle.output();
}
Triangle::Triangle( ): A(1.0), B(1.0), C(1.0)
{/*empty*/}
Triangle::Triangle(double param){
	setA(param);
	setB(param);
	setC(param);
}
Triangle::Triangle(double paramA, double paramB): C(1.0){
	setABC(paramA, paramB, C);
}
Triangle::Triangle(double paramA, double paramB, double paramC){
	setABC(paramA, paramB, paramC);
}
/*
*	Tek parametre alan setter fonksiyonlari
*	Kulanicinin girdigi deger negatifse hata verip programi sonlandirir.
*/
void Triangle::setA(double a){
	if(a>0)
		A=a;
	else{
		cerr << "Inconsistent account data...\nEXITING..." << endl;
		exit(1);
	}
}
void Triangle::setB(double b){
	if(b>0)
		B=b;
	else{
		cerr << "Inconsistent account data...\nEXITING..." << endl;
		exit(1);
	}
}
void Triangle::setC(double c){
	if(c>0)
		C=c;
	else{
		cerr << "Inconsistent account data...\nEXITING..." << endl;
		exit(1);
	}
}
/*
*	3 parametreli setter fonksiyonu
*	Constructor cagirilirken girilen objeler ucgen olusturma kurallanirina uymuyorsa
*	veya negatifse programi sonlandirir
*/
void Triangle::setABC(double a, double b, double c){
	/*
	*	Ucgen olma kurali: 
	*	girilen inputlar 0'dan buyuk olmali
	*	|a-b|<c<|a+b| 
	*	|a-c|<b<|a+c| 
	*	|b-c|<a<|b+c| 
	*	sartlari ayni anda saglanmali.
	*	aksi durumda hata verip programi kapat
	*/
	if(a>0 && b>0 && c>0){
		if(((abs(a-c) < b) && (b < abs(b+c)) && (abs(b-c) < a) && (a < abs(b+c)) && (abs(b-a) < c) &&  (c < abs(b+a)))){
			A=a;
			B=b;
			C=c;
		}
		else{
			cerr << "Invalid Input...\nTriangle existence rule error...\nEXITING..." << endl;
			exit(1);
		}
	}
	else{
		cerr << "Inconsistent account data...\nEXITING..." << endl;
		exit(1);
	}

}
void Triangle::input(){
	double a, b, c;	
	cout << "Enter sides of triangle (cm) > ";
	cin >> a;
	cin >> b;
	cin >> c;
	/*
	*	Ucgen olma kurali: 
	*	|a-b|<c<|a+b| 
	*	|a-c|<b<|a+c| 
	*	|b-c|<a<|b+c| 
	*	sartlari ayni anda saglanmali.
	*	aksi durumda hata verip programi kapat
	*/
	if((abs(a-c) < b) && (b < abs(b+c)) && (abs(b-c) < a) && (a < abs(b+c)) && (abs(b-a) < c) &&  (c < abs(b+a))) {
		setA(a);
		setB(b);
		setC(c);
	}
	//Girilen input ücgen olma kuralina uymuyorsa ekrana hata mesaji yazip programi kapat
	else{
		cerr << "Invalid Input...\nTriangle existence rule error...\nEXITING..." << endl;
		exit(1);
	}
}
/*
*	Cosinus teoremini uygulayarak iki kenar arasindaki aciyi bulan fonksiyonlar
*	a kosesinin cosinus degeri cos(x) olmak uzere = > cos(x)=(b^2+c^2-a^2)/(2*b*c)
*	Bulunan aciyi return eder.
*/
double Triangle::calculateAngleA() const{
	double cosx;
	cosx=(pow(getB(),2)+pow(getC(),2)-pow(getA(),2))/(2*getB()*getC());
	return acos(cosx)*180/PI;
}
double Triangle::calculateAngleB() const{
	double cosx;
	cosx=(pow(getA(),2)+pow(getC(),2)-pow(getB(),2))/(2*getA()*getC());
	return acos(cosx)*180/PI;
}
double Triangle::calculateAngleC() const{
	double cosx;
	cosx=(pow(getB(),2)+pow(getA(),2)-pow(getC(),2))/(2*getB()*getA());
	return acos(cosx)*180/PI;
}
bool Triangle::isRightAngleTriangle() const{	
	/*
	*	A, B ve C kenarlarinin her birine  pisagor bagintisini uygulayip,
	*	a,b,c degiskenlerine atadim.
	*/
	double a = pow(B,2)+pow(C,2);
	double b = pow(C,2)+pow(A,2);
	double c = pow(A,2)+pow(B,2); 

	//ucgen kenarlarindan bir tanesi pisagor bagintisini sagliyorsa true return et

	if(a==pow(A,2) || b==pow(B,2) || c==pow(C,2)) 
		return true;
	else
		return false;
}
/*
*	ucgenin kenar uzunluklarini, acilarini, dik acili ucgen olup olmadigini
*	cevre uzunlugunu ve alan buyuklugunu ekrana basan fonksiyon.
*/
void Triangle::output() const{
	cout << "\nSide A: "<< getA() << " Side B: " << getB() << " Side C: " << getC() << endl << endl;
	cout << "Angle(BAC): " << calculateAngleA() << " Angle (ABC): " << calculateAngleB() << " Angle (ACB): " << calculateAngleC() << endl << endl;
	if(isRightAngleTriangle())	
		cout << "RIGHT ANGLE TRIANGLE FOUND!" << endl << endl; 
	cout << "Perimeter: " << calculatePerimeter() << " cm" << endl <<  endl;
	cout << "Area: " << calculateArea() << " cm^2" << endl << endl;
}
/*			END OF MAIN.CPP		*/