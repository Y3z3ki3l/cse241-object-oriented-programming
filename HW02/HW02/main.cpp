#include <iostream>

using namespace std;

class DayOfYear
{
public:
	//Constructor: Class icindeki degiskenlerin degerlerini 1 yapar.
	DayOfYear();
	//Setter: Class icindeki degiskenlere deger atar.
	void setDayOfYear(int dayValue, int monthValue);
	//Ay ve gun degiskenleri
	int month;
	int day;
};
struct Person
{
	//Struct elemanlari
	int weight;
	int height;
};
/*
*	const void * tipinde array alir.
*	bu array'in size'ini ve tipinin sizeof operatorunden donen num degerini kullanarak 
*	array'in maksimum buyuklugunu bulur. dongu yardimiyle array'in son elemanina kadar
*	giderek en cok tekrar eden elemani bulur ve bu elemanin dizideki ilk indexini return eder.
*/
int return_mode(const void *base, size_t num, size_t size, bool (* equals) (void *, void *));

/*
*	integer arrayler icin array'in elemanlarini kiyaslar.
*	elemanlar birbirinden farkli ise false return eder.
*/
bool compare_int(void *a, void *b){
	int* p1 = (int*) a;
	int* p2 = (int*) b;
	if(*p1!=*p2)
		return false;
	else 
		return true;
}
/*
*	double arrayler icin array'in elemanlarini kiyaslar.
*	elemanlar birbirinden farkli ise false return eder.
*/
bool compare_double(void *a, void *b){
	double* p1 = (double*) a;
	double* p2 = (double*) b;
	if(*p1!=*p2)
		return false;
	else 
		return true;
}
/*
*	char arrayler icin array'in elemanlarini kiyaslar.
*	elemanlar birbirinden farkli ise false return eder.
*/
bool compare_char(void *a, void *b){
	char *p1 = (char *) a;
	char *p2 = (char *) b;
	if(*p1!=*p2)
		return false;
	else 
		return true;
}
/*
*	DayOfYear classinden olusturulan arrayler icin array'in elemanlarini kiyaslar.
*	elemanlar birbirinden farkli ise false return eder.
*/
bool compare_DayOfYear(void *a, void *b){
	DayOfYear *p1 = (DayOfYear*) a;
	DayOfYear  *p2 = (DayOfYear*) b;
	if (p1->day != p2->day || p1->month != p2->month)
		return false;
	else 
		return true;
}
/*
*	person structindan olusturulan arrayler icin array'in elemanlarini kiyaslar.
*	elemanlar birbirinden farkli ise false return eder.
*/
bool compare_PersonInfo(void *a, void *b){
	Person *p1 = (Person *) a;
	Person *p2 = (Person *) b;
	if(p1->height != p2->height || p1->weight != p2->weight)
		return false;
	else 
		return true;
}
int main(){
	//size ve result degiskenleri
	size_t size=10;
	int result=0;
	{
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 8}; //arrayi initialize et
		result = return_mode(arr, sizeof(int), size, compare_int); //fonksiyonu cagir ve result degiskenine ata
		cout << "result for Integer array: " << result << endl; //sonucu ekrana bas
	}
	{
		double arr[] = {91.78, 54.5, 91.78, 85.17, 1.11, 87,56, 19.7, 66.6, 66.6, 91.78}; //arrayi initialize et
		result = return_mode(arr, sizeof(double), size, compare_double); //fonksiyonu cagir ve result degiskenine ata
		cout << "result for Double array: " << result << endl; //sonucu ekrana bas
	}
	{
		char arr[] = {'G', 'E', 'B', 'Z', 'E', ' ', 'T', 'K', 'N', 'K'}; //arrayi initialize et
		result = return_mode(arr, sizeof(char), size, compare_char); //fonksiyonu cagir ve result degiskenine ata
		cout << "result for Char array: " << result << endl; //sonucu ekrana bas
	}
	{	
		//struct'in her bir elemanina deger ata
		Person personInfo[] = {{78,180}, {19,80}, {66,166}, {87,192}, {80,200}, {84,175}, {39,150}, {11,52}, {51,172}, {19,80}};
		result = return_mode(personInfo, sizeof(Person), size, compare_PersonInfo); //fonksiyonu cagir ve result degiskenine ata
		cout << "result for Person struct: " << result << endl; //sonucu ekrana bas
	}
	{	
		DayOfYear days[size]; //arrayi initialize et
		//Setter fonksiyonunu kullanarak class arrayine deger ata
		days[0].setDayOfYear(13,1); 
		days[1].setDayOfYear(10,12);
		days[2].setDayOfYear(12,8);
		days[3].setDayOfYear(30,11);
		days[4].setDayOfYear(13,10);
		days[5].setDayOfYear(1,4);
		days[6].setDayOfYear(8,8);
		days[7].setDayOfYear(8,8);	
		days[8].setDayOfYear(8,8);
		days[9].setDayOfYear(31,7);
		result = return_mode(days, sizeof(DayOfYear), size, compare_DayOfYear); //fonksiyonu cagir ve result degiskenine ata
		cout << "result for DayOfYear class: " << result << endl; //sonucu ekrana bas
	}
}
DayOfYear::DayOfYear(){
	//month ve day degiskenlerine ilk deger olarak 1 ata
	month=1;
	day=1;
}
void DayOfYear::setDayOfYear(int dayValue, int monthValue){
	//degiskenleri set et
	month=monthValue;
	day=dayValue;
}
int return_mode (const void *base, size_t num, size_t size, bool (* equals) (void *, void *)){
	/*Degiskenler*/
	int count=0, max=0, index=0;
	int sizemax=num*size;	//arrayin buyuklugu
	//arrayin ilk ve son adreslerini olustur
	unsigned char* head = (unsigned char*) base; 
	unsigned char* last = (unsigned char*) base + sizemax;
	//kiyaslanacak adresleri olustur
	unsigned char* first;
	unsigned char* second;
	//ilk adresten son adrese kadar her adres degiskenini arrayin bir elemanin boyutu kadar arttirarak
	//array uzerinde dolas ve first ve second degiskenlerini equals fonksiyonuna yolla
	for(first=head; first<last; first+=num){
		for(second=head; second<last; second+=num)
			if(equals(first, second))
				++count; //equals fonksiyonu false dondurmuyorsa count'u 1 arttir
		if(count>max){	
			max=count; //maksimum count'u bul ve count'un maksimum oldugu array elemaninin adresinden 
			index=(first-head)/num; //arrayin ilk adresini cikartip arrayin bir elemaninin boyutuna bolerek index'i bul
		}
		count=0; //count'u sifirla
	}
	return index; //index'i return et
}