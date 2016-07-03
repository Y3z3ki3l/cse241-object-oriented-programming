/* 
 *      File:   Cell.cpp
 *      Author: Yasin Acikgoz
 * 
 *      Created on November 15, 2015, 1:49 PM
 * 
 */ 



#include "Cell.h"

Cell::Cell():cell(emptyCell){
    /*empty*/
}
Cell::Cell(char c) {
    setCell(c);
} 
Cell::Cell(int x, int y, char c){
    setX(x);
    setY(y);
    setCell(c);
}
void Cell::setX(int x){
    coordinateX=x;
}
void Cell::setY(int y){
    coordinateY=y;
} 
void Cell::setCell(char c){
    cell=c;
}
void Cell::setCell(int x, int y, char c){
    coordinateX=x;
    coordinateY=y;
    cell=c;
}