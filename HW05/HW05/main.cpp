
/* 
 *          File:   main.cpp
 *          Author: Yasin Acikgoz
 *
 *                      CSE 241 HW 05
 *         Object Oriented Reversi Game with Operator Overloading.
 *      
 *      Oyun maksimum 26 hucre genisliginde oynanabilir.
 *              Yukseklikte sinir yoktur.
 *      Oyunu geri alan -- operatoru implement edilmemistir.
 * 
 */
/*      INCLUDES      */
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Reversi.h"

const char *filename = "save.reversi";
using namespace std;

/*      yasayan hucre sayisini tutan statik degisken*/
int Reversi::numberOfLivingCell=0;
/*     START OF MAIN.CPP        */
int main(){
    cout << "* * * * * START OF OPERATOR OVERLOADING TESTS FOR CELL CLASS * * * * *\n";
    
    /*
     *      Degisik tip ve koordinatlarda hucreler olusturulur ve ekrana basilir.
     * 
     */
    Cell cell1(1,7,computer);
    Cell cell2(3,5,user);
    Cell cell3(4,4,computer);
    Cell cell4(6,3, user);
    
    cout << "Cell1: " << cell1 << endl
         << "Cell2: " << cell2 << endl
         << "Cell3: " << cell3 << endl
         << "Cell4: " << cell4 << endl;
    
    /*
     *      olusturulan hucreler kullanilarak >, <, ==, !=, <=, >= 
     *      operatorleri test edilir.
     */
    if(cell1>cell2)
        cout << "Cell1, Cell2'den buyuktur.\n";
    if(cell1<cell2)
        cout << "Cell2, Cell1'den buyuktur.\n";
    if(cell1==cell2)
        cout << "Cell1, Cell2'ye esittir.\n";
    if(cell1!=cell2)
        cout << "Cell1, Cell2'ye esit degildir.\n";
    
    if(cell3>=cell4)
        cout << "Cell3, Cell4'ten buyuk esittir.\n";
        
    if(cell3<=cell4)
        cout << "Cell3, Cell4'ten kucuk esittir.\n";
    
    cout << "Stream extraction operatorunu test etmek icin sirasiyla 2 adet integer ve 1 adet karakter giriniz.\n";
    Cell cell;
    cin >> cell;
    //      kullanici tarafindan girilen hucreyi ekrana bas.
    cout << "Cell: \n" << cell;
    
    /*
     *      olusturulan hucreler kullanilarak post increment, pre increment, 
     *      post decrement ve pre decrement operatorleri test edilir.
     *      sonuclar ekrana basilir. 
     */
    cout << endl << endl << "Cell1: " << cell1;
    cout << "post increment(cell1++): " << cell1++;
    cout << "Cell1: " << cell1 << endl << endl;
    
    
    cout << "Cell2: " << cell2;
    cout << "post increment(++cell2): " << ++cell2;
    cout << "Cell2: " << cell2 << endl << endl;
    
    cout << "Cell3: " << cell3;
    cout << "post decrement(cell3--): " << cell3--;
    cout << "Cell3: " << cell3 << endl << endl;
    
    
    cout << "Cell4: " << cell4;
    cout << "post decrement(--cell4): " << --cell4;
    cout << "Cell4: " << cell4 << endl << endl;
    
    cout << "* * * * * END OF OPERATOR OVERLOADING TESTS FOR CELL CLASS * * * * *\n";

    cout << "* * * * * START OF OPERATOR OVERLOADING TESTS FOR REVERSI CLASS * * * * *\n";
    /*
     * 
     *      4x4'luk bir reversi objesi olusturulur. Oyun bitene kadar kullanicidan hamle girmesi istenir.
     *      Kullanici hamle girince += operatoru test edilir ve oyun stream insertion operatoruyle ekrana basilir.
     *      post increment operatoruyle bilgisayara hamle yaptirilir. ardindan oyun tekrar ekrana basilir.
     *  
     */
    Reversi game(4);
    cout << game;
     do {
        //Kullanicinin gecerli hamlesi olup olmadigini kontrol et
        if (game.checkUserMove()) {
            string input;
            cout << "Please enter move a valid move for testing.\n";
            cin >> input;
            //Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
            game+=game[input.c_str()];
            cout << game;
        } else {
            cout << "There is no move for User." << endl; //prompt
        }
        if (game.checkComputerMove()) { //Bilgisayarin gecerli hamlesi olup olmadigini kontrol et
            ++game; //Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
            cout << game;
        } else {
            cout << "There is no move for Computer." << endl;
        }
        //Eger bilgisayar ve kullanicinin ayni anda hamlesi yoksa oyunu bitir
    } while ((game.isGameEnd()));
    game.printGameOver(); 
    
    cout << "\nTest for parenthesis operator.\n";
    cout << game(3, 'd');
    cout << game(2, 'a');
    cout << "* * * * * END OF OPERATOR OVERLOADING TESTS FOR REVERSI CLASS * * * * *\n";
    return 0;
}
/*     END OF MAIN.CPP        */