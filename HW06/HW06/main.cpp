
/* 
 *      File:   main.cpp
 *      Author: Yasin Acikgoz
 *      Created on December 11 2015
 *
 *                 CSE 241 HW 06
 *              Dynamic Reversi Game
 *      
 *      Oyun maksimum 26 hucre genisliginde oynanabilir.
 *      Yukseklikte sinir yoktur.
 *      Oyun default olarak sayfayi temizleyerek calismaktadir.
 *      Tum hamleleri gorerek oynamak icin Reversi.cpp dosyasindaki
 *      __CLEAR_THE_BOARD preprocessor direktifini devre disi birakmak gereklidir.
 * 
 * 
 */
/*      INCLUDES      */
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Reversi.h"

const char *filename = "save.reversi";
using namespace std;
using namespace _YasinAcikgoz;
using namespace _YasinAcikgoz_Cell;
/*      yasayan hucre sayisini tutan statik degisken*/
int Reversi::numberOfGame = 0;
int Reversi::x=0;
int Reversi::y=0;

void testCallByValue1(Reversi reversi);

void testCallByValue2(Reversi reversi1, Reversi reversi2);

void testCallByReference1(Reversi &reversi1, Reversi &reversi2);

void testCallByReference2(Reversi &reversi);
/*     START OF MAIN.CPP        */
int main() {
    Reversi game1(4), game4(6,10), game3;
    testCallByReference2(game1);
    //Kullanicidan board'un boyutlarini alan fonksiyon
    Reversi::getBoardSize();
    Reversi game2(Reversi::x,Reversi::y);
    testCallByValue1(game2);
    testCallByValue2(game3, game4);
    testCallByReference1(game3, game4);
    return 0;
}
void testCallByValue1(Reversi reversi){
    cout << "__________CALL BY VALUE TEST FUNCTION____________\n";
    reversi.playGame();
}
void testCallByReference1(Reversi &reversi1, Reversi &reversi2){
    cout << "__________CALL BY REFERENCE TEST FUNCTION____________\n";
    cout << "__________TEST FOR ASSIGNMENT OPERATOR____________\n";
    cout << "-----GAME1------" << endl << reversi1 << endl;
    cout << "-----GAME2------" << endl << reversi2 << endl;
    reversi1=reversi2;  
    cout << "GAME 1 OBJECT AFTER ASSIGNMENT OPERATION\n";
    cout << "-----GAME1------" << endl << reversi1 << endl;
}
void testCallByValue2(Reversi reversi1, Reversi reversi2){
    cout << "__________CALL BY VALUE TEST FUNCTION____________\n";
    cout << "-----GAME1------" << endl << reversi1 << endl;
    cout << "-----GAME2------" << endl << reversi2 << endl;
    if(reversi1.compareGames(reversi2))
        cout << "GAME 2 IS BETTER THAN GAME 1\n";
    else
        cout << "GAME 1 IS BETTER THAN GAME 2\n";   
} 
void testCallByReference2(Reversi &reversi){
    int coorX, coorY;
    int size=6;
    cout << "__________CALL BY REFERENCE TEST FUNCTION____________\n";
    cout << "-----GAME1------" << endl << reversi << endl;
    reversi.resizeTheBoard(size);
    cout << "The board resizing to " << size << "x" << size << " board." << endl;
    cout << reversi << endl;
    cout << "Please enter correct moves for good testing.\n";
    reversi.getCoordinates(coorX, coorY);
    reversi.play(coorX, coorY);
    cout << reversi << endl;
    ++reversi;
    cout << reversi << endl;
    reversi.resizeTheBoard(4, 4);
    cout << "The board resizing to 4x4 board." << endl;
    reversi.printBoard();
    reversi.getCoordinates(coorX, coorY);
    reversi.play(coorX, coorY);
    cout << reversi << endl;
    reversi++;
    cout << reversi << endl;
}
/*     END OF MAIN.CPP        */