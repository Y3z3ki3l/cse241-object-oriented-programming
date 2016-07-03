/* 
 *      File:   Cell.h
 *      Author: Yasin Acikgoz
 *
 *      Created on December 11 2015
 * 
 */
#include <cstdlib>
#include <iostream>
#include <vector>


#ifndef CELL_H
#define	CELL_H

using namespace std;
const char user = 'O';
const char computer = 'X';
const char emptyCell = '.';
const int defaultSize = 6;
namespace _YasinAcikgoz_Cell {

    class Cell {
    public:
        //constructors
        Cell();
        Cell(char c);
        Cell(int x, int y, char c);

        //getters

        int getX() const {
            return coordinateX;
        }

        int getY() const {
            return coordinateY;
        }

        char getCell()const {
            return cell;
        }

        //setters
        void setX(int x);
        void setY(int y);
        void setCell(char c);
        void setCell(int x, int y, char c);

    private:
        int coordinateX;
        int coordinateY;
        char cell;
    };
}

#endif	/* CELL_H */

