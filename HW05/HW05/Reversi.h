/* 
 *      File:   Reversi.h
 *      Author: Yasin Acikgoz
 *
 * 
 */
#ifndef REVERSI_H 
#define	REVERSI_H

#include <iostream>
#include "Cell.h" 

using namespace std;

class Reversi {
public:  
    vector < vector <Cell> > gameCells;
    vector <Reversi> oldMove;
    Reversi();
    Reversi(int size);
    Reversi(int sizeX, int sizeY);
    //getters
    int getWidth()const{return widthSize;}
    int getHeight()const{return heightSize;}
    //setters
    void setWidth(int width);
    void setHeight(int height);
    bool getCoordinates(int &coorX, int &coorY);
    void fillBoard(const int height, const int width);
    void printBoard();
    bool play(const int coorX, const int coorY);
    void play();
    void playGame();
    bool checkComputerMove()const;
    bool checkUserMove()const;
    void writeGame(const char *filename);
    void readGame(const char *filename);
    static int countNumberOfLivingCell(){return numberOfLivingCell;}
    bool compareGames(const Reversi& other)const;
    bool isGameEnd()const;
    void printGameOver();
    void printScoreBoard();
    
    void moveTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    void moveDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    void moveLeft(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    void moveRight(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    void moveLeftTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    void moveRightTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    void moveLeftDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    void moveRightDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
    
    Reversi operator++(int ignoreMe);
    Reversi operator++();
    Reversi operator+=(const Cell &currentMove);
    
    Cell operator[](const char *nameOfCell);
    Cell operator()(int coordinateY, char coordinateX);
    
    friend ostream& operator<<(ostream &outputStream, const Reversi &currentGame);
    
private:
    int widthSize;
    int heightSize;
    static int numberOfLivingCell;
    
    int checkTop(const char player1, const char player2, int coordinateX, int coordinateY)const;
    int checkDown(const char player1, const char player2, int coordinateX, int coordinateY)const;
    int checkLeft(const char player1, const char player2, int coordinateX, int coordinateY)const;
    int checkRight(const char player1, const char player2, int coordinateX, int coordinateY)const;
    int checkLeftTop(const char player1, const char player2, int coordinateX, int coordinateY)const;
    int checkLeftDown(const char player1, const char player2, int coordinateX, int coordinateY)const;
    int checkRightTop(const char player1, const char player2, int coordinateX, int coordinateY)const;
    int checkRightDown(const char player1, const char player2, int coordinateX, int coordinateY)const; 
};
#endif	/* REVERSI_H */
