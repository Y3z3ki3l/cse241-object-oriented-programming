/* 
 *      File:   Reversi.cpp
 *      Author: Yasin Acikgoz
 * 
 *      Created on November 15, 2015, 2:20 PM
 */

#define __CLEAR_THE_BOARD
#include <fstream>
#include <unistd.h>
 
#include "Reversi.h"  

/*
 *  no parameter constructor
 */
Reversi::Reversi() {
    vector<Cell> temporaryVector;
    int i = 0, j = 0;
    setWidth(defaultSize);
    setHeight(defaultSize);
    for (i = 0; i < getHeight(); ++i) {
        for (j = 0; j < getWidth(); ++j) {
            temporaryVector.push_back(Cell(i, j, emptyCell));
        }
        gameCells.push_back(temporaryVector);
        temporaryVector.clear();
    }
    fillBoard(getHeight(), getWidth());
    numberOfLivingCell += 4;
}
/*
 *  two parameter constructor
 */
Reversi::Reversi(int sizeX, int sizeY) {
    vector<Cell> temporaryVector;
 
    setWidth(sizeX);
    setHeight(sizeY);
    int i = 0, j = 0;
    for (i = 0; i < getHeight(); ++i) {
        for (j = 0; j < getWidth(); ++j) {
            temporaryVector.push_back(Cell(i, j, emptyCell));
        }
        gameCells.push_back(temporaryVector);
        temporaryVector.clear();
    }
    fillBoard(getHeight(), getWidth());
    numberOfLivingCell += 4;
}
/*
 *  one parameter constructor
 */
Reversi::Reversi(int size) {
    vector<Cell> temporaryVector;
    setWidth(size);
    setHeight(size);
    int i = 0, j = 0;
    for (i = 0; i < getHeight(); ++i) {
        for (j = 0; j < getWidth(); ++j) {
            temporaryVector.push_back(Cell(i, j, emptyCell));
        }
        gameCells.push_back(temporaryVector);
        temporaryVector.clear();
    }
    fillBoard(getHeight(), getWidth());
    numberOfLivingCell += 4;
}
/*
 *      Board'un yuksekligini set et, negatif deger gelirse hata basip cik
 */
void Reversi::setHeight(int height) {
    if (height <= 0) {
        cout << "Error! Negative size value\n";
        exit(1);
    }
    heightSize = height;
}
/*
 *      Board'un genisligini set et, negatif deger gelirse hata basip cik
 */
void Reversi::setWidth(int width) {
    if (width <= 0) {
        cout << "Error! Negative size value\n";
        exit(1);
    }
    if (width > 26) {
        cout << "Error! Size overflow\n";
        exit(1);
    }
    widthSize = width;
}
/*
 *  Tahtadaki bilgisayar ve kullanici taslarinin sayilarini ekrana bas
 */
void Reversi::printScoreBoard(){
    int countUser = 0, countComputer = 0;
    for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            if (gameCells[i][j].getCell() == user)
                ++countUser;
            else if (gameCells[i][j].getCell() == computer)
                ++countComputer;
        }
    }
    cout << "\t    " << countUser << "  \t   " << countComputer;
}
/*
 *  Oyunun bittigini ekrana yaz ve hangi oyuncunun hangi skorla kazandigini goster
 */
void Reversi::printGameOver() {
    int countUser = 0, countComputer = 0;
    for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            if (gameCells[j][i].getCell() == user)
                ++countUser;
            else if (gameCells[j][i].getCell() == computer)
                ++countComputer;
        }
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
    double totalCells = getHeight() * getWidth();
    double otherTotalCells = other.getHeight() * other.getWidth();

    for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            if (gameCells[i][j].getCell() == user)
                ++userCells;
        }
    }
    for (int i = 0; i < other.getHeight(); ++i) {
        for (int j = 0; j < other.getWidth(); ++j) {
            if (other.gameCells[i][j].getCell() == user)
                ++otherUserCells;
        }
    }
    if (userCells / totalCells > otherUserCells / otherTotalCells)
        return true;
    else
        return false;
}
/*
 *      Board'u ekrana bas
 */
void Reversi::printBoard() {
    int i = 0, j = 0;
    char c;
    cout << "   ";
    for (i = 0; i < getWidth(); ++i) {
        cout << " ";
        c = (char) i + 65;
        cout << c;
    }
    cout << endl;
    for (i = 0; i < getHeight(); ++i) {
        if (i < 9)
            cout << " ";
        cout << " " << i + 1;
        for (j = 0; j < getWidth(); ++j) {
            cout << " " << gameCells[i][j].getCell();
        }
        if (i == getHeight() / 2 - 2)
            cout << "\t    Scoreboard";
        if (i == getHeight() / 2 - 1)
            cout << "\t  User  Computer ";
        if (i == getHeight() / 2) //board'un yanina skorbord bas
            printScoreBoard();
        if (i == getHeight() / 2 + 1)   //yasayan canli hucre sayisini bas
            cout << "  Number of Living Cell: " << countNumberOfLivingCell();
        cout << endl;
    }
}
/*
 *      Board'u baslangic konumuna getir
 */
void Reversi::fillBoard(int height, int width) {
    gameCells[height / 2 - 1][width / 2 - 1] = computer;
    gameCells[height / 2][width / 2] = computer;
    gameCells[height / 2][width / 2 - 1] = user;
    gameCells[height / 2 - 1][width / 2] = user;
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
        cout << "Please enter a current move." << endl;
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
    if (total > 0) {
        ++numberOfLivingCell;
        return true;
    } else
        return false;
}
/*
 *      Bilgisayarin en iyi hamlesini oynayan fonksiyon
 */
void Reversi::play(){
    int coordinateX = 0, coordinateY = 0;
    int max = 0, total = 0, top = 0, down = 0, right = 0, left = 0, leftTop = 0, rightTop = 0, rightDown = 0, leftDown = 0;
    int maxTop = 0, maxDown = 0, maxRight = 0, maxLeft = 0, maxLeftTop = 0, maxRightTop = 0, maxRightDown = 0, maxLeftDown = 0;
    int maxCoorX = 0, maxCoorY = 0;
    for (coordinateY = 0; coordinateY < getHeight(); ++coordinateY) {
        for (coordinateX = 0; coordinateX < getWidth(); ++coordinateX) {
            if (gameCells[coordinateY][coordinateX].getCell() == emptyCell) {
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
                if (total > max) {  //en fazla tas yenilen koordinati bul
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
    }
    if (max > 0)    //tas yemek mumkunse yasayan hucre sayisini 1 arttir
        ++numberOfLivingCell;
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
  //      cout << "son\n";
}
void Reversi::playGame() {
    int coorX, coorY;
    printBoard();
    do {
        //Kullanicinin gecerli hamlesi olup olmadigini kontrol et
        if (checkUserMove()) {
            while (!(getCoordinates(coorX, coorY))) {   //kullanicidan koordinat al
                cout << "Error: Invalid move attempt." << endl;
            }
            //Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
            while (play(coorX, coorY) != true) {
                cout << "Error: Invalid move attempt for user." << endl;
                while (!(getCoordinates(coorX, coorY))) {
                    cout << "Error: Invalid move attempt." << endl;
                }
            }
            #ifdef __CLEAR_THE_BOARD
                system("clear");
            #endif
            printBoard();
        } else {
            cout << "There is no move for User." << endl; //prompt
        }
        if (checkComputerMove()) { //Bilgisayarin gecerli hamlesi olup olmadigini kontrol et
            play(); //Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
            printBoard();
        } else {
            cout << "There is no move for Computer." << endl;
        }
        //Eger bilgisayar ve kullanicinin ayni anda hamlesi yoksa oyunu bitir
    } while ((isGameEnd()));
    printGameOver();
}
/*
 *      Tum bos hucreler icin bilgisayarin hamlesi olup olmadigini kontrol et hamle varsa true return et
 */
bool Reversi::checkComputerMove()const {
    int top = 0, down = 0, right = 0, left = 0, leftTop = 0, rightTop = 0, rightDown = 0, leftDown = 0, total = 0, max = 0;
    int coordinateX, coordinateY;
    for (coordinateY = 0; coordinateY < getHeight(); ++coordinateY) {
        for (coordinateX = 0; coordinateX < getWidth(); ++coordinateX) {
            if (gameCells[coordinateY][coordinateX].getCell() == emptyCell) {
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
    }
    if (max > 0)
        return true;
    else
        return false;
}
/*
 *      Tum bos hucreler icin kullanicinin hamlesi olup olmadigini kontrol et hamle varsa true return et
 */
bool Reversi::checkUserMove()const {
    int top = 0, down = 0, right = 0, left = 0, leftTop = 0, rightTop = 0, rightDown = 0, leftDown = 0, total = 0, max = 0;
    int coordinateX, coordinateY;
    for (coordinateY = 0; coordinateY < getHeight(); ++coordinateY) {
        for (coordinateX = 0; coordinateX < getWidth(); ++coordinateX) {
            if (gameCells[coordinateY][coordinateX].getCell() == emptyCell) {
                top = checkTop(user, computer, coordinateX, coordinateY);
                down = checkDown(user, computer, coordinateX, coordinateY);
                right = checkRight(user, computer, coordinateX, coordinateY);
                left = checkLeft(user, computer, coordinateX, coordinateY);
                leftTop = checkLeftTop(user, computer, coordinateX, coordinateY);
                rightTop = checkRightTop(user, computer, coordinateX, coordinateY);
                rightDown = checkRightDown(user, computer, coordinateX, coordinateY);
                leftDown = checkLeftDown(user, computer, coordinateX, coordinateY);
                total = top + down + right + left + leftTop + rightTop + rightDown + leftDown;
                if (total > max) {
                    max = total;
                }
            }
        }
    }
    if (max > 0)
        return true;
    else
        return false;
}
/*
 *      Oyunu dosyaya yaz.
 */
void Reversi::writeGame(const char *filename) {
    ofstream reversi;
    reversi.open(filename);
    if (!(reversi.is_open())) {
        cout << "Error file open.\n";
        exit(1);
    }
    for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            reversi << gameCells[i][j].getCell();
        }
        reversi << endl;
    }
    reversi.close();
}
/*
 *      Dosyaya yazilan oyunu temp vector araciligiyla satir satir okuyarak 
 *      board'u tekrar olustur
 */
void Reversi::readGame(const char *filename) {
    int i = 0, j = 0;
    string row;
    ifstream reversi;
    vector<Cell> temp;
    reversi.open(filename);
    if (!(reversi.is_open())) {
        cout << "Error file open.\n";
        exit(1);
    }
    for (i = 0; i < getHeight(); ++i) {
        getline(reversi, row);
        for (j = 0; j < getWidth(); ++j) {
            //temp.push_back(Cell(i, j, row[j]));
            gameCells [i][j].setCell(i,j,row[j]);
        }
    }
    reversi.close();
}
/*
 *      Oyunun bitip bitmedigin kontrol et oyun bittiyse true return et
 */
bool Reversi::isGameEnd()const {
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
    int top = 0, count = 0, i = 0;
    if (coordinateY - 1 >= 0 && gameCells[coordinateY - 1][coordinateX].getCell() == player2) {//UST
        while (gameCells[coordinateY - i][coordinateX].getCell() != player1) {
            ++i;
            if (coordinateY - i < 0) {
                top = 0;
                break;
            } else {
                if (gameCells[coordinateY - i][coordinateX].getCell() == player2) {
                    ++count;
                    top = count;
                } else if (gameCells[coordinateY - i][coordinateX].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY - i][coordinateX].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}

int Reversi::checkDown(const char player1, const char player2, int coordinateX, int coordinateY)const {
    int down = 0, count = 0, i = 0;
    if (coordinateY + 1 < getHeight() && gameCells[coordinateY + 1][coordinateX].getCell() == player2) {//ALT
        while (gameCells[coordinateY + i][coordinateX].getCell() != player1) {
            ++i;
            if (coordinateY + i > getHeight() - 1) {
                down = 0;
                break;
            } else {
                if (gameCells[coordinateY + i][coordinateX].getCell() == player2) {
                    ++count;
                    down = count;
                } else if (gameCells[coordinateY + i][coordinateX].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY + i][coordinateX].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}

int Reversi::checkLeft(const char player1, const char player2, int coordinateX, int coordinateY)const {
    int left = 0, count = 0, i = 0;
    if (coordinateX - 1 >= 0 && gameCells[coordinateY][coordinateX - 1].getCell() == player2) {//SOL
        while (gameCells[coordinateY][coordinateX - i].getCell() != player1) {
            ++i;
            if (coordinateX - i < 0) {
                left = 0;
                break;
            } else {
                if (gameCells[coordinateY][coordinateX - i].getCell() == player2) {
                    ++count;
                    left = count;
                } else if (gameCells[coordinateY][coordinateX - i].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY][coordinateX - i].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}

int Reversi::checkRight(const char player1, const char player2, int coordinateX, int coordinateY)const{
    int right = 0, count = 0, i = 0;
    if (coordinateX + 1 < getWidth() && gameCells[coordinateY][coordinateX + 1].getCell() == player2) {//SAG
        while (gameCells[coordinateY][coordinateX + i].getCell() != player1) {
            ++i;
            if (coordinateX + i > getWidth() - 1) {
                right = 0;
                break;
            } else {
                if (gameCells[coordinateY][coordinateX + i].getCell() == player2) {
                    ++count;
                    right = count;
                } else if (gameCells[coordinateY][coordinateX + i].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY][coordinateX + i].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}

int Reversi::checkLeftTop(const char player1, const char player2, int coordinateX, int coordinateY)const {
    int leftTop = 0, count = 0, i = 0;
    if (coordinateY - 1 >= 0 && coordinateX - 1 >= 0 && gameCells[coordinateY - 1][coordinateX - 1].getCell() == player2) {//SOLUST
        while (gameCells[coordinateY - i][coordinateX - i].getCell() != player1) {
            ++i;
            if (coordinateY - i < 0 || coordinateX - i < 0) {
                leftTop = 0;
                break;
            } else {
                if (gameCells[coordinateY - i][coordinateX - i].getCell() == player2) {
                    ++count;
                    leftTop = count;
                }
                else if (gameCells[coordinateY - i][coordinateX - i].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY - i][coordinateX - i].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}

int Reversi::checkLeftDown(const char player1, const char player2, int coordinateX, int coordinateY)const {
    int leftDown = 0, count = 0, i = 0;
    if (coordinateY + 1 < getHeight() && coordinateX - 1 >= 0 && gameCells[coordinateY + 1][coordinateX - 1].getCell() == player2) {//SOLALT
        while (gameCells[coordinateY + i][coordinateX - i].getCell() != player1) {
            ++i;
            if (coordinateY + i > getHeight() - 1 || coordinateX - i < 0) {
                leftDown = 0;
                break;
            } else {
                if (gameCells[coordinateY + i][coordinateX - i].getCell() == player2) {
                    ++count;
                    leftDown = count;
                } else if (gameCells[coordinateY + i][coordinateX - i].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY + i][coordinateX - i].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}

int Reversi::checkRightDown(const char player1, const char player2, int coordinateX, int coordinateY)const {
    int rightDown = 0, count = 0, i = 0;
    if (coordinateY + 1 < getHeight() && coordinateX + 1 < getWidth() && gameCells[coordinateY + 1][coordinateX + 1].getCell() == player2) {//SAGALT
        while (gameCells[coordinateY + i][coordinateX + i].getCell() != player1) {
            ++i;
            if (coordinateY + i > getHeight() - 1 || coordinateX + i > getWidth() - 1) {
                rightDown = 0;
                break;
            } else {
                if (gameCells[coordinateY + i][coordinateX + i].getCell() == player2) {
                    ++count;
                    rightDown = count;
                } else if (gameCells[coordinateY + i][coordinateX + i].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY + i][coordinateX + i].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}

int Reversi::checkRightTop(const char player1, const char player2, int coordinateX, int coordinateY)const {
    int rightTop = 0, count = 0, i = 0;
    if (coordinateY - 1 >= 0 && coordinateX + 1 < getWidth() && gameCells[coordinateY - 1][coordinateX + 1].getCell() == player2) {//SAGUST
        while (gameCells[coordinateY - i][coordinateX + i].getCell() != player1) {
            ++i;
            if (coordinateY - i < 0 || coordinateX + i > getWidth() - 1) {
                rightTop = 0;
                break;
            } else {
                if (gameCells[coordinateY - i][coordinateX + i].getCell() == player2) {
                    ++count;
                    rightTop = count;
                } else if (gameCells[coordinateY - i][coordinateX + i].getCell() == emptyCell) {
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
    if (numberOfEarnedCell > 0) {
        gameCells[coordinateY][coordinateX].setCell(currentPlayer);
        while (i <= numberOfEarnedCell) {
            gameCells[coordinateY - i][coordinateX + i].setCell(currentPlayer);
            ++i;
        }
    }
    return;
}