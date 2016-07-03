/* 
 *      File:   Reversi.h
 *      Author: Yasin Acikgoz
 *
 *      Created on December 11 2015
 * 
 */
#ifndef REVERSI_H 
#define	REVERSI_H

#include <iostream>
#include "Cell.h" 

using namespace std;
namespace _YasinAcikgoz {

    class Reversi {
    public:
        static int x;
        static int y;
        static int numberOfGame;
        
        Reversi();
        Reversi(int size);
        Reversi(int sizeX, int sizeY);
        Reversi(const Reversi& newObject);
        Reversi& operator=(const Reversi& rightSide);
        ~Reversi();
        
        //getters
        int getWidth()const {return width;}
        int getHeight()const {return height; }
        int getSizeMax()const {return width * height;}
        //setters
        void setWidth(int widthSize);
        void setHeight(int heightSize);
        
        bool getCoordinates(int &coorX, int &coorY);
        void printBoard()const;
        bool play(const int coorX, const int coorY);
        void play();
        void playGame();
        bool checkComputerMove()const;
        bool checkUserMove()const;
        bool compareGames(const Reversi& other)const;
        bool isGameEnd()const;
        void printGameOver()const;
        void printScoreBoard()const;

        static int getBoardSize();
        static int countNumberOfGames(){return numberOfGame;}
        
        Reversi& resizeTheBoard(int size);
        Reversi& resizeTheBoard(int widthSize, int heightSize);
        Reversi& resizeTheBoardFromCurrentPosition(int widthSize, int heightSize);
        char findTheCell(int y, int x)const;
        Reversi operator++();
        Reversi operator++(int ignoreMe);
        friend ostream& operator<<(ostream& outputStream, const Reversi& board);

        void moveTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
        void moveDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
        void moveLeft(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
        void moveRight(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
        void moveLeftTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
        void moveRightTop(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
        void moveLeftDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);
        void moveRightDown(const char currentPlayer, const int numberOfEarnedCell, int coordinateX, int coordinateY);

    private:
        _YasinAcikgoz_Cell::Cell *gameCells;
        int width;
        int height;

        int checkTop(const char player1, const char player2, int coordinateX, int coordinateY)const;
        int checkDown(const char player1, const char player2, int coordinateX, int coordinateY)const;
        int checkLeft(const char player1, const char player2, int coordinateX, int coordinateY)const;
        int checkRight(const char player1, const char player2, int coordinateX, int coordinateY)const;
        int checkLeftTop(const char player1, const char player2, int coordinateX, int coordinateY)const;
        int checkLeftDown(const char player1, const char player2, int coordinateX, int coordinateY)const;
        int checkRightTop(const char player1, const char player2, int coordinateX, int coordinateY)const;
        int checkRightDown(const char player1, const char player2, int coordinateX, int coordinateY)const;
    };
}
#endif	/* REVERSI_H */