/* 
 *      File:   Reversi.cpp
 *      Author: Yasin Acikgoz
 * 
 *      Created on December 11 2015
 */

#define __CLEAR_THE_BOARDx
#include <fstream>
#include <unistd.h>

#include "Reversi.h"  
using namespace _YasinAcikgoz_Cell;
namespace _YasinAcikgoz {

    /*
     *  no parameter constructor
     */
    Reversi::Reversi() {
        setWidth(defaultSize);
        setHeight(defaultSize);
        int i = 0, j = 0, k = 0;

        gameCells = new Cell[getSizeMax()];

        for (i = 0; i < getHeight(); ++i) {
            for (j = 0; j < getWidth(); ++j) {
                if (i == getHeight() / 2 - 1 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, user);
                else if (i == getHeight() / 2 - 1 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, user);
                else
                    gameCells[k].setCell(i, j, emptyCell);
                ++k;
            }
        }
        ++numberOfGame;
    }

    /*
     *  two parameter constructor
     */

    Reversi::Reversi(int sizeX, int sizeY) {
        setWidth(sizeX);
        setHeight(sizeY);
        int i = 0, j = 0, k = 0;
        gameCells = new Cell[getSizeMax()];

        for (i = 0; i < getHeight(); ++i) {
            for (j = 0; j < getWidth(); ++j) {
                if (i == getHeight() / 2 - 1 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, user);
                else if (i == getHeight() / 2 - 1 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, user);
                else
                    gameCells[k].setCell(i, j, emptyCell);
                ++k;
            }
        }
        ++numberOfGame;
    }

    /*
     *  one parameter constructor
     */
    Reversi::Reversi(int size) {
        setWidth(size);
        setHeight(size);
        int i = 0, j = 0, k = 0;
        gameCells = new Cell[getSizeMax()];

        for (i = 0; i < getHeight(); ++i) {
            for (j = 0; j < getWidth(); ++j) {
                if (i == getHeight() / 2 - 1 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, user);
                else if (i == getHeight() / 2 - 1 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, user);
                else
                    gameCells[k].setCell(i, j, emptyCell);
                ++k;
            }
        }
        ++numberOfGame;
    }
    /*
     *      copy constructor
     */
    Reversi::Reversi(const Reversi& newObject) : width(newObject.getWidth()), height(newObject.getHeight()) {
        gameCells = new Cell[getSizeMax()];
        for (int i = 0; i < getSizeMax(); ++i)
            gameCells[i] = newObject.gameCells[i];
            cout << "Copy constructor used for this test.\n";
    }

    /*
     *      destructor
     */
    Reversi::~Reversi() {
        delete [] gameCells;
        --numberOfGame;
    }
    
    /*
     *      assignment operator
     */
    Reversi& Reversi::operator=(const Reversi& rightSide) {
        if (getWidth() != rightSide.getWidth() || getHeight() != rightSide.getHeight()) {
            delete [] gameCells;
            gameCells = new Cell[rightSide.getSizeMax()];
        }
        width = rightSide.getWidth();
        height = rightSide.getHeight();
        for (int i = 0; i < getSizeMax(); ++i)
            gameCells[i] = rightSide.gameCells[i];
        return *this;
    }

    /*
     *      Board'un yuksekligini set et, negatif deger gelirse hata basip cik
     */
    void Reversi::setHeight(int heightSize) {
        if (heightSize <= 0) {
            cerr << "Error! Negative size value\n";
            exit(1);
        }
        height = heightSize;
    }
    /*
     *      Board'un genisligini set et, negatif deger gelirse hata basip cik
     */
    void Reversi::setWidth(int widthSize) {
        if (widthSize <= 0) {
            cerr << "Error! Negative size value\n";
            exit(1);
        }
        if (widthSize > 26) {
            cerr << "Error! Size overflow\n";
            exit(1);
        }
        width = widthSize;
    }
    /*
     *  Tahtadaki bilgisayar ve kullanici taslarinin sayilarini ekrana bas
     */
    void Reversi::printScoreBoard() const{
        int countUser = 0, countComputer = 0;
        for (int i = 0; i < getSizeMax(); ++i) {
            if (gameCells[i].getCell() == user)
                ++countUser;
            else if (gameCells[i].getCell() == computer)
                ++countComputer;
        }
        cout << "\t    " << countUser << "  \t   " << countComputer;
    }

    /*
     *  Oyunun bittigini ekrana yaz ve hangi oyuncunun hangi skorla kazandigini goster
     */
    void Reversi::printGameOver() const{
        int countUser = 0, countComputer = 0;
        for (int i = 0; i < getSizeMax(); ++i) {
            if (gameCells[i].getCell() == user)
                ++countUser;
            else if (gameCells[i].getCell() == computer)
                ++countComputer;
        }
        cout << "THE GAME IS OVER" << endl;
        if (countUser > countComputer) {
            cout << "User wins by " << countUser << " - " << countComputer << "!" << endl;

        } else if (countComputer > countUser) {
            cout << "Computer wins by " << countComputer << " - " << countUser << "!" << endl;

        } else
            cout << "Draws by " << countComputer << " - " << countUser << "!" << endl;
    }

    /*
     *  
     *      Kullanicinin tas sayisinin board buyuklugune oranini alarak 
     *      iki farkli oyun icin hangi kullanicinin daha iyi oldugunu
     *      tespit eden fonksiyon
     * 
     */
    bool Reversi::compareGames(const Reversi& other)const {
        double userCells = 0, otherUserCells = 0;
        double totalCells = getSizeMax();
        double otherTotalCells = other.getSizeMax();

        for (int i = 0; i < getHeight(); ++i) {
            for (int j = 0; j < getWidth(); ++j) {
                if (findTheCell(i, j) == user)
                    ++userCells;
            }
        }
        for (int i = 0; i < other.getHeight(); ++i) {
            for (int j = 0; j < other.getWidth(); ++j) {
                if (findTheCell(i, j) == user)
                    ++otherUserCells;
            }
        }
        if (userCells / totalCells > otherUserCells / otherTotalCells)
            return true;
        else
            return false;
    }

    /*
     *      Board'u ekrana stream insertion operatoruyle bas 
     */
    ostream& operator<<(ostream& outputStream, const Reversi &currentGame){
        int i = 0, j = 0, k=0, l=0;
        int countUser = 0, countComputer = 0;
        char c;
        outputStream << "   ";
        for (i = 0; i < currentGame.getWidth(); ++i) {
            outputStream << " ";
            c = (char) i + 65;
            outputStream << c;
        }
        i = 0;

        outputStream << endl;
        for (j = 0; j < currentGame.getSizeMax(); ++j) {
            if ((j % currentGame.getWidth()) == 0) {
                if (i < 9)
                    outputStream << " ";
                outputStream << " " << i + 1;
                ++i;
            }
            outputStream << " " << currentGame.gameCells[j].getCell();
            if ((j % currentGame.getWidth()) == currentGame.getWidth() - 1){
                if(k==(currentGame.getHeight()/2-2)){
                     outputStream << "\t    Scoreboard";
                }
                if (k == currentGame.getHeight() / 2 - 1)
                    outputStream << "\t  User  Computer ";
                if (k == currentGame.getHeight() / 2){ //board'un yanina skorbord bas
                    for (int l = 0; l < currentGame.getSizeMax(); ++l) {
                        if (currentGame.gameCells[l].getCell() == user)
                            ++countUser;
                        else if (currentGame.gameCells[l].getCell() == computer)
                            ++countComputer;
                    }
                    outputStream << "\t    " << countUser << "  \t   " << countComputer;
                }
                if (k == currentGame.getHeight() / 2 + 1)   //aktif oyun sayisini bas
                    outputStream << "    Number of Games: " << Reversi::countNumberOfGames();
                outputStream << endl;
            ++k; 
            }
        }
        return outputStream;
    }
    /*
     *      board'u ekrana bas.
     */
    void Reversi::printBoard() const{
        int i = 0, j = 0, k=0;
        char c;
        cout << "   ";
        for (i = 0; i < getWidth(); ++i) {
            cout << " ";
            c = (char) i + 65;
            cout << c;
        }
        i = 0;

        cout << endl;
        for (j = 0; j < getSizeMax(); ++j) {
            if ((j % getWidth()) == 0) {
                if (i < 9)
                    cout << " ";
                cout << " " << i + 1;
                ++i;
            }
            cout << " " << gameCells[j].getCell();
            if ((j % getWidth()) == getWidth() - 1){
                if(k==(getHeight()/2-2)){
                     cout << "\t    Scoreboard";
                }
                if (k == getHeight() / 2 - 1)
                    cout << "\t  User  Computer ";
                if (k == getHeight() / 2) //board'un yanina skorbord bas
                    printScoreBoard();
                if (k == getHeight() / 2 + 1)   //aktif oyun sayisini bas
                    cout << "    Number of Games: " << countNumberOfGames();
                cout << endl;
            ++k; 
            }
        }
    }
    /*
     *      Tek ve 2parametreli resize fonksiyonu oyunu başlangic konumuna
     *      getirip resize eder.
     */
    Reversi& Reversi::resizeTheBoard(int widthSize, int heightSize){
        Cell *temp;
        int i=0, j=0, k=0;
        temp = new Cell[getSizeMax()];
        for(i=0; i<getSizeMax(); ++i)
            temp[i]=gameCells[i];

        setWidth(widthSize);
        setHeight(heightSize);
        
        delete [] gameCells;
        
        gameCells = new Cell[getSizeMax()];
        ++numberOfGame;
        for (i = 0; i < getHeight(); ++i) {
            for (j = 0; j < getWidth(); ++j) {
                 if (i == getHeight() / 2 - 1 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, user);
                else if (i == getHeight() / 2 - 1 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, user);
                else
                    gameCells[k].setCell(i, j, emptyCell);
                ++k;
            }
        }
        delete [] temp;
        return *this;
    }
   
    /*
     *      Tek ve 2parametreli resize fonksiyonu oyunu başlangic konumuna
     *      getirip resize eder.
     */
    Reversi& Reversi::resizeTheBoard(int size){
        Cell *temp;
        int i=0, j=0, k=0;
        
        temp = new Cell[getSizeMax()];
        for(i=0; i<getSizeMax(); ++i)
            temp[i]=gameCells[i];

        setWidth(size);
        setHeight(size);
        
        delete [] gameCells;
        
        gameCells = new Cell[getSizeMax()];
        ++numberOfGame;
        for (i = 0; i < getHeight(); ++i) {
            for (j = 0; j < getWidth(); ++j) {
                 if (i == getHeight() / 2 - 1 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, computer);
                else if (i == getHeight() / 2 && j == getWidth() / 2 - 1)
                    gameCells[k].setCell(i, j, user);
                else if (i == getHeight() / 2 - 1 && j == getWidth() / 2)
                    gameCells[k].setCell(i, j, user);
                else
                    gameCells[k].setCell(i, j, emptyCell);
                ++k;
            }
        }
        delete [] temp;
        return *this;
    }
    /*
     *  Kullanicidan board'un boyutlarini alan static fonksiyon
     */
    int Reversi::getBoardSize(){
         do{
            cout << "Welcome to the GTU-Reversi game!" << endl;
            cout << "Please enter board sizes. (width < 27 & height)" << endl << endl;
            cin >> x;
            cin >> y;
        }while(x > 26);
        //Kullanici size degerini dogru girene kadar size al
        
    }
    /*
     *  Kullanicidan koordinat alan fonksiyon
     */
    bool Reversi::getCoordinates(int &coorX, int &coorY) {
        char cX;
        int temp;
        //Kullanicidan gecerli hamle girene kadar hamle iste girilen hamle gecersiz ise buffer'i bosalt
        cout << "Enter a move." << endl;
        while (!(cin >> coorY)) {
            cerr << "Please enter a current move." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        } //Kullanicidan Y koordinatini al
        --coorY; //1 azdown
        cin >> cX; //Kullanicidan X koordinatini karakter olarak al

        cX = toupper(cX); //Buyuk harfe cevir
        temp = static_cast<int> (cX); //harfi integera cevir
        coorX = temp - 65; //integeri tekrar koordinata cevir*/
        if (coorX > getWidth() || coorY > getHeight())
            return false;
        else
            return true;
    }
    /*
     *      operator overloading kullanilan play fonksiyonlari
     */
    Reversi Reversi::operator ++(int ignoreMe){
        Reversi tempGame;
        tempGame=*this;
        this -> operator ++();
        return tempGame;
    }
    Reversi Reversi::operator ++(){
        play();
        return (*this);
    }
    /*
     *      Kullanicinin girdigi hamleyi oynayan fonksiyon
     */
    bool Reversi::play(int coorX, int coorY) {
        //8 farkli yondeki yenilecek taslari hesapla ve topla
        int top = checkTop(user, computer, coorX, coorY);
        int down = checkDown(user, computer, coorX, coorY);
        int right = checkRight(user, computer, coorX, coorY);
        int left = checkLeft(user, computer, coorX, coorY);
        int leftTop = checkLeftTop(user, computer, coorX, coorY);
        int rightTop = checkRightTop(user, computer, coorX, coorY);
        int rightDown = checkRightDown(user, computer, coorX, coorY);
        int leftDown = checkLeftDown(user, computer, coorX, coorY);
        int total = top + down + right + left + leftTop + rightTop + rightDown + leftDown;
        //yenilecek tas bulunan yonler icin tas yeme fonksiyonunu cagir
        moveTop(user, top, coorX, coorY);
        moveDown(user, down, coorX, coorY);
        moveRight(user, right, coorX, coorY);
        moveLeft(user, left, coorX, coorY);
        moveLeftTop(user, leftTop, coorX, coorY);
        moveRightTop(user, rightTop, coorX, coorY);
        moveRightDown(user, rightDown, coorX, coorY);
        moveLeftDown(user, leftDown, coorX, coorY);
        //yenilecek tas varsa true return et ve yasayan hucre sayisini 1 arttir
        if (total > 0)
            return true;
        else
            return false;
    }

    /*
     *      Bilgisayarin en iyi hamlesini oynayan fonksiyon
     */
    void Reversi::play() {
        int coordinateX = 0, coordinateY = 0;
        int max = 0, total = 0, top = 0, down = 0, right = 0, left = 0, leftTop = 0, rightTop = 0, rightDown = 0, leftDown = 0;
        int maxTop = 0, maxDown = 0, maxRight = 0, maxLeft = 0, maxLeftTop = 0, maxRightTop = 0, maxRightDown = 0, maxLeftDown = 0;
        int maxCoorX = 0, maxCoorY = 0;
        for (int i = 0; i < getSizeMax(); ++i) {
            if (gameCells[i].getCell() == emptyCell) {
                int temp = i;
                coordinateX = temp % getWidth();
                coordinateY = temp / getHeight();

                //8 farkli yondeki yenilecek taslari hesapla ve topla
                top = checkTop(computer, user, coordinateX, coordinateY);
                down = checkDown(computer, user, coordinateX, coordinateY);
                right = checkRight(computer, user, coordinateX, coordinateY);
                left = checkLeft(computer, user, coordinateX, coordinateY);
                leftTop = checkLeftTop(computer, user, coordinateX, coordinateY);
                rightTop = checkRightTop(computer, user, coordinateX, coordinateY);
                rightDown = checkRightDown(computer, user, coordinateX, coordinateY);
                leftDown = checkLeftDown(computer, user, coordinateX, coordinateY);
                total = top + down + right + left + leftTop + rightTop + rightDown + leftDown;
                if (total > max) { //en fazla tas yenilen koordinati bul
                    max = total;
                    total = 0;
                    maxTop = top;
                    maxDown = down;
                    maxLeft = left;
                    maxRight = right;
                    maxLeftTop = leftTop;
                    maxRightTop = rightTop;
                    maxRightDown = rightDown;
                    maxLeftDown = leftDown;
                    maxCoorX = coordinateX;
                    maxCoorY = coordinateY;
                }
            }
        }
        //yenilecek tas bulunan yonler icin tas yeme fonksiyonunu cagir
        moveTop(computer, maxTop, maxCoorX, maxCoorY);
        moveDown(computer, maxDown, maxCoorX, maxCoorY);
        moveLeft(computer, maxLeft, maxCoorX, maxCoorY);
        moveRight(computer, maxRight, maxCoorX, maxCoorY);
        moveLeftDown(computer, maxLeftDown, maxCoorX, maxCoorY);
        moveRightDown(computer, maxRightDown, maxCoorX, maxCoorY);
        moveRightTop(computer, maxRightTop, maxCoorX, maxCoorY);
        moveLeftTop(computer, maxLeftTop, maxCoorX, maxCoorY);
        #ifdef __CLEAR_THE_BOARD
                sleep(2);
                system("clear");
        #endif
    }

    void Reversi::playGame() {
        int coorX, coorY;
        printBoard();
        do {
            //Kullanicinin gecerli hamlesi olup olmadigini kontrol et
            if (checkUserMove()) {
                while (!(getCoordinates(coorX, coorY))) { //kullanicidan koordinat al
                    cerr << "Error: Invalid move attempt." << endl;
                }
                //Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
                while (play(coorX, coorY) != true) {
                    cerr << "Error: Invalid move attempt for user." << endl;
                    while (!(getCoordinates(coorX, coorY))) {
                        cerr << "Error: Invalid move attempt." << endl;
                    }
                }
                #ifdef __CLEAR_THE_BOARD
                                system("clear");
                #endif
                printBoard();
            } else {
                cerr << "There is no move for User." << endl; //prompt
            }
            if (checkComputerMove()) { //Bilgisayarin gecerli hamlesi olup olmadigini kontrol et
                play(); //Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
                printBoard();
            } else {
                cerr << "There is no move for Computer." << endl;
            }
            //Eger bilgisayar ve kullanicinin ayni anda hamlesi yoksa oyunu bitir
        } while ((isGameEnd()));
        printGameOver();
    }

    /*
     *      Tum bos hucreler icin bilgisayarin hamlesi olup olmadigini kontrol et hamle varsa true return et
     */
    bool Reversi::checkComputerMove()const{
        int top = 0, down = 0, right = 0, left = 0, leftTop = 0, rightTop = 0, rightDown = 0, leftDown = 0, total = 0, max = 0;
        int coordinateX, coordinateY;
        for (int i = 0; i < getSizeMax(); ++i) {
            if (gameCells[i].getCell() == emptyCell) {
                int temp = i;
                coordinateX = temp % getWidth();
                coordinateY = temp / getHeight();

                top = checkTop(computer, user, coordinateX, coordinateY);
                down = checkDown(computer, user, coordinateX, coordinateY);
                right = checkRight(computer, user, coordinateX, coordinateY);
                left = checkLeft(computer, user, coordinateX, coordinateY);
                leftTop = checkLeftTop(computer, user, coordinateX, coordinateY);
                rightTop = checkRightTop(computer, user, coordinateX, coordinateY);
                rightDown = checkRightDown(computer, user, coordinateX, coordinateY);
                leftDown = checkLeftDown(computer, user, coordinateX, coordinateY);
                total = top + down + right + left + leftTop + rightTop + rightDown + leftDown;
                if (total > max) {
                    max = total;
                }
            }
        }
        
        if (max > 0)
            return true;
        else
            return false;
    }

    /*
     *      Tum bos hucreler icin kullanicinin hamlesi olup olmadigini kontrol et hamle varsa true return et
     */
    bool Reversi::checkUserMove()const{
        int top = 0, down = 0, right = 0, left = 0, leftTop = 0, rightTop = 0, rightDown = 0, leftDown = 0, total = 0, max = 0;
        int coordinateX, coordinateY;
        for (int i = 0; i < getSizeMax(); ++i) {
            if (gameCells[i].getCell() == emptyCell) {
                int temp = i;
                coordinateX = temp % getWidth();
                coordinateY = temp / getHeight();

                top = checkTop(user, computer, coordinateX, coordinateY);
                down = checkDown(user, computer, coordinateX, coordinateY);
                right = checkRight(user, computer, coordinateX, coordinateY);
                left = checkLeft(user, computer, coordinateX, coordinateY);
                leftTop = checkLeftTop(user, computer, coordinateX, coordinateY);
                rightTop = checkRightTop(user, computer, coordinateX, coordinateY);
                rightDown = checkRightDown(user, computer, coordinateX, coordinateY);
                leftDown = checkLeftDown(user, computer, coordinateX, coordinateY);
                total = top + down + right + left + leftTop + rightTop + rightDown + leftDown;
                if (total > max)
                    max = total;
            }

        }
        if (max > 0)
            return true;
        else
            return false;
    }

    /*
     *      Oyunun bitip bitmedigin kontrol et oyun bittiyse true return et
     */
    bool Reversi::isGameEnd()const{
        if (checkComputerMove() || checkUserMove())
            return true;
        else
            return false;
    }

    /*
     *      8 farkli yone gore fonksiyonlara yollanan koordinatlarin kontrol eden fonksiyonlar 
     *      Kontrol fonksiyonlarindan gelen yenilecek tas sayisi bilgisini ve gecerli koordinatlari alarak 
     *      tas yeme islemini gerceklestiren fonksiyonlar
     */
    int Reversi::checkTop(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int top = 0, i = 0;
        if (coordinateY - 1 >= 0 && findTheCell(coordinateX, coordinateY - 1) == player2) {//UST
            while (findTheCell(coordinateX, coordinateY - i) != player1) {
                ++i;
                if (coordinateY - i < 0) {
                    top = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX, coordinateY - i) == player2) {
                        ++top;
                    } else if (findTheCell(coordinateX, coordinateY - i) == emptyCell) {
                        top = 0;
                        break;
                    }
                }
            }
        }
        return top;
    }

    void Reversi::moveTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index - (getWidth() * i)].setCell(currentPlayer);
                ++i;
            }
        }
        return;
    }

    int Reversi::checkDown(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int down = 0, i = 0;
        if (coordinateY + 1 < getHeight() && findTheCell(coordinateX, coordinateY + 1) == player2) {//ALT
            while (findTheCell(coordinateX, coordinateY + i) != player1) {
                ++i;
                if (coordinateY + i > getHeight() - 1) {
                    down = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX, coordinateY + i) == player2) {
                        ++down;
                    } else if (findTheCell(coordinateX, coordinateY + i) == emptyCell) {
                        down = 0;
                        break;
                    }
                }
            }
        }
        return down;
    }

    void Reversi::moveDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index + (getWidth() * i)].setCell(currentPlayer);
                ++i;
            }
        }
    }

    int Reversi::checkLeft(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int left = 0, i = 0;
        if (coordinateX - 1 >= 0 && findTheCell(coordinateX - 1, coordinateY) == player2) {//SOL
            while (findTheCell(coordinateX - i, coordinateY) != player1) {
                ++i;
                if (coordinateX - i < 0) {
                    left = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX - i, coordinateY) == player2) {
                        ++left;
                    } else if (findTheCell(coordinateX - i, coordinateY) == emptyCell) {
                        left = 0;
                        break;
                    }
                }

            }
        }
        return left;
    }

    void Reversi::moveLeft(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index - i].setCell(currentPlayer);
                ++i;
            }
        }
        return;
    }

    int Reversi::checkRight(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int right = 0, i = 0;
        if (coordinateX + 1 < getWidth() && findTheCell(coordinateX + 1, coordinateY) == player2) {//SAG
            while (findTheCell(coordinateX + i, coordinateY) != player1) {
                ++i;
                if (coordinateX + i > getWidth() - 1) {
                    right = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX + i, coordinateY) == player2) {
                        ++right;
                    } else if (findTheCell(coordinateX + i, coordinateY) == emptyCell) {
                        right = 0;
                        break;
                    }
                }
            }
        }
        return right;
    }

    void Reversi::moveRight(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index + i].setCell(currentPlayer);
                ++i;
            }
        }
        return;
    }

    int Reversi::checkLeftTop(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int leftTop = 0, i = 0;
        if (coordinateY - 1 >= 0 && coordinateX - 1 >= 0 && findTheCell(coordinateX - 1, coordinateY - 1) == player2) {//SOLUST
            while (findTheCell(coordinateX - i, coordinateY - i) != player1) {
                ++i;
                if (coordinateY - i < 0 || coordinateX - i < 0) {
                    leftTop = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX - i, coordinateY - i) == player2) {
                        ++leftTop;
                    } else if (findTheCell(coordinateX - i, coordinateY - i) == emptyCell) {
                        leftTop = 0;
                        break;
                    }
                }
            }
        }
        return leftTop;
    }

    void Reversi::moveLeftTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index - i - (getWidth() * i)].setCell(currentPlayer);
                ++i;
            }
        }
        return;
    }

    int Reversi::checkLeftDown(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int leftDown = 0, i = 0;
        if (coordinateY + 1 < getHeight() && coordinateX - 1 >= 0 && findTheCell(coordinateX - 1, coordinateY + 1) == player2) {//SOLALT
            while (findTheCell(coordinateX - i, coordinateY + i) != player1) {
                ++i;
                if (coordinateY + i > getHeight() - 1 || coordinateX - i < 0) {
                    leftDown = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX - i, coordinateY + i) == player2) {
                        ++leftDown;
                    } else if (findTheCell(coordinateX - i, coordinateY + i) == emptyCell) {
                        leftDown = 0;
                        break;
                    }
                }
            }
        }
        return leftDown;
    }

    void Reversi::moveLeftDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index - i + (getWidth() * i)].setCell(currentPlayer);
                ++i;
            }
        }
        return;
    }

    int Reversi::checkRightDown(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int rightDown = 0, i = 0;
        if (coordinateY + 1 < getHeight() && coordinateX + 1 < getWidth() && findTheCell(coordinateX + 1, coordinateY + 1) == player2) {//SAGALT
            while (findTheCell(coordinateX + i, coordinateY + i) != player1) {
                ++i;
                if (coordinateY + i > getHeight() - 1 || coordinateX + i > getWidth() - 1) {
                    rightDown = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX + i, coordinateY + i) == player2) {
                        ++rightDown;
                    } else if (findTheCell(coordinateX + i, coordinateY + i) == emptyCell) {
                        rightDown = 0;
                        break;
                    }
                }
            }
        }
        return rightDown;
    }

    void Reversi::moveRightDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index + i + (getWidth() * i)].setCell(currentPlayer);
                ++i;
            }
        }
        return;
    }

    int Reversi::checkRightTop(const char player1, const char player2, int coordinateX, int coordinateY)const {
        int rightTop = 0, i = 0;
        if (coordinateY - 1 >= 0 && coordinateX + 1 < getWidth() && findTheCell(coordinateX + 1, coordinateY - 1) == player2) {//SAGUST
            while (findTheCell(coordinateX + i, coordinateY - i) != player1) {
                ++i;
                if (coordinateY - i < 0 || coordinateX + i > getWidth() - 1) {
                    rightTop = 0;
                    break;
                } else {
                    if (findTheCell(coordinateX + i, coordinateY - i) == player2) {
                        ++rightTop;
                    } else if (findTheCell(coordinateX + i, coordinateY - i) == emptyCell) {
                        rightTop = 0;
                        break;
                    }
                }
            }
        }
        return rightTop;
    }

    void Reversi::moveRightTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY) {
        int i = 1;
        int index = (getWidth() * coordinateY) + coordinateX;
        if (numberOfEarnedCell > 0) {
            gameCells[index].setCell(currentPlayer);
            while (i <= numberOfEarnedCell) {
                gameCells[index + i - (getWidth() * i)].setCell(currentPlayer);
                ++i;
            }
        }
        return;
    }

    char Reversi::findTheCell(int y, int x)const {
        for (int i = 0; i < getSizeMax(); ++i) {
            if (gameCells[i].getX() == x & gameCells[i].getY() == y)
                return gameCells[i].getCell();
        }
        return emptyCell;
    }
}
