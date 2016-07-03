/* 
 *      File:   Cell.cpp
 *      Author: Yasin Acikgoz
 * 
 *      Created on December 11 2015
 * 
 */



#include "Cell.h"
namespace _YasinAcikgoz_Cell {

    Cell::Cell() : cell(emptyCell) {
        /*empty*/
    }

    Cell::Cell(char c) {
        setCell(c);
    }

    Cell::Cell(int x, int y, char c) {
        setCell(x, y, c);
    }

    void Cell::setX(int x) {
        coordinateX = x;
    }

    void Cell::setY(int y) {
        coordinateY = y;
    }

    void Cell::setCell(char c) {
        cell = c;
    }

    void Cell::setCell(int x, int y, char c) {
        coordinateX = x;
        coordinateY = y;
        cell = c;

    }
}
