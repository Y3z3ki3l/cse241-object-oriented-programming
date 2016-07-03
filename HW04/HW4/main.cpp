
/* 
 *      File:   main.cpp
 *      Author: Yasin Acikgoz
 *      Created on November 15, 2015, 1:47 PM
 *
 *                 CSE 241 HW 04
 *         Object Oriented Reversi Game
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

/*      yasayan hucre sayisini tutan statik degisken*/
int Reversi::numberOfLivingCell=0;
/*     START OF MAIN.CPP        */
int main(){
    /*
     * 
     *      10x10, 4x4, 10x10, 8x6 ve 15x20'lik 5 tane oyun olusturulur.
     *      10x10'luk ilk oyunda user hamlesi yapilip oyun dosyaya yazilir.
     *      4x4'luk oyuna gecilir. Oyun tamamlaninca user hamlesi yapilan
     *      10x10'luk oyun dosyadan okunarak ayni boyutlu baska bir objenin 
     *      uzerine yazilir ve bilgisayara bir hamle yaptirilir.
     *      8x6'lik oyuna kullanici ve bilgisayara 2'ser hamle yaptirilir.
     *      15x20'lik oyuna kullanici ve bilgisayara 2'ser hamle yaptirilir.
     *      Ardindan bu oyunların hangisinde kullanicinin daha basarili oldugu 
     *      compareGames fonksiyonu ile ekrana basilir ve program sonlanir.
     * 
     */
    int coorX, coorY;
    Reversi game1(10,10), game2, game3(10), game4(6,6), game5(15,20);
    cout << "8x8 GAME\n";
    game1.printBoard();
    game1.getCoordinates(coorX, coorY);
    cout << "Please enter valid moves for testing.\n";
    game1.play(coorX, coorY);
    game1.printBoard();
    cout << "GAME1 IS SAVING TO THE 'save.reversi' FILE.\n";
    game1.writeGame(filename);
    cout << "4x4 GAME\n";
    game2.playGame();
    cout << "GAME1 IS LOADING FROM THE 'save.reversi' FILE TO GAME3 OBJECT.\n";
    cout << "Please enter valid moves for testing.\n";
    game3.readGame(filename);
    game3.printBoard();
    game3.play();
    game3.printBoard();
    
    cout << "6x6 GAME\n";
    game4.printBoard();
    game4.getCoordinates(coorX, coorY);
    cout << "Please enter valid moves for testing.\n";
    game4.play(coorX, coorY);
    game4.printBoard();
    game4.play();
    game4.printBoard();
    game4.getCoordinates(coorX, coorY);
    cout << "Please enter valid moves for testing.\n";
    game4.play(coorX, coorY);
    game4.printBoard();
    game4.play();
    game4.printBoard();
    
    cout << "15X20 GAME\n";
    game5.printBoard();
    game5.getCoordinates(coorX, coorY);
    cout << "Please enter valid moves for testing.\n";
    game5.play(coorX, coorY);
    game5.printBoard();
    game5.play();
    game5.printBoard();
    game5.getCoordinates(coorX, coorY);
    cout << "Please enter valid moves for testing.\n";
    game5.play(coorX, coorY);
    game5.printBoard();
    game5.play();
    game5.printBoard();
    
    if(game4.compareGames(game5))
        cout << "GAME 5 IS BETTER THAN GAME 4\n";
    else
        cout << "GAME 4 IS BETTER THAN GAME 5\n";   
    return 0;
}
/*     END OF MAIN.CPP        */