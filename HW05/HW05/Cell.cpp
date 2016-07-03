/* 
 *      File:   Cell.cpp
 *      Author: Yasin Acikgoz
 * 
 * 
 */ 

#include "Cell.h"
bool Cell::operator <(const Cell &otherCell)const{
    if(getY()<otherCell.getY()){
        return true;
    }
    else if(getY()>otherCell.getY()){
        return false;
    }
    else if(getY()==otherCell.getY()){
        if(getX()<otherCell.getX()){
            return true;
        }
        else{
            return false;
        }     
    }
}
bool Cell::operator >(const Cell &otherCell)const{
    if(getY()>otherCell.getY()){
        return true;
    }
    else if(getY()<otherCell.getY()){
        return false;
    }
    else if(getY()==otherCell.getY()){
        if(getX()>otherCell.getX()){
            return true;
        }
        else{
            return false;
        }
    }
}
bool Cell::operator ==(const Cell &otherCell)const{
    if(getX()==otherCell.getX() && getY()==otherCell.getY()){
        return true;
    }
    else{
        return false;
    }
}
bool Cell::operator !=(const Cell& otherCell)const{
    if(getX()==otherCell.getX() && getY()==otherCell.getY()){
        return false;
    }
    else{
        return true;
    }
}
bool Cell::operator >=(const Cell& otherCell)const{
    if(getY()>=otherCell.getY()){
        return true;
    }
    else if(getY()<otherCell.getY()){
        return false;
    }
    else if(getY()==otherCell.getY()){
        if(getX()>=otherCell.getX()){
            return true;
        }
        else{
            return false;
        }
    }
}
bool Cell::operator <=(const Cell& otherCell)const{
    if(getY()<=otherCell.getY()){
        return true;
    }
    else if(getY()>otherCell.getY()){
        return false;
    }
    else if(getY()==otherCell.getY()){
        if(getX()<=otherCell.getX()){
            return true;
        }
        else{
            return false;
        }
    }
}
Cell Cell::operator++(int ignoreMe){
    int tempX=0, tempY=0;
    
    tempX=getX();
    tempY=getY();
    
    setX(tempX+1);
    setY(tempY+1);
    return Cell(tempX, tempY, getCell());
}
Cell Cell::operator ++(){
    
    setX(getX()+1);
    setY(getY()+1);
    
    return *this;
}
istream& operator >>(istream& inputStream, Cell &currentCell){
    int coordinateX, coordinateY;
    char cell;
    
    inputStream>>coordinateX;
    inputStream>>coordinateY;
    inputStream>>cell;
    
    currentCell.setX(coordinateX);
    currentCell.setY(coordinateY);
    currentCell.setCell(cell);
     
    return inputStream;
}
ostream& operator <<(ostream& outputStream, const Cell &currentCell){
    outputStream << "\nX coordinate: " << currentCell.getX() << endl;
    outputStream << "Y coordinate: " << currentCell.getY() << endl;
    outputStream << "Cell Type: " << currentCell.getCell() << endl;
    return outputStream;
}
Cell Cell::operator --(int ignoreMe){
    int tempX=0, tempY=0;
    
    tempX=getX();
    tempY=getY();
    
    setX(tempX-1);
    setY(tempY-1);
    
    return Cell(tempX, tempY, getCell());
}
Cell Cell::operator --(){
    
    setX(getX()-1);
    setY(getY()-1);
    
    return *this;
}
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
    if(x>26){
        cout << "Error! Size overflow\n";
        exit(1);
    }
    coordinateX=x; 
    return;
}
void Cell::setY(int y){
    coordinateY=y;
    return;
} 
void Cell::setCell(char c){
    cell=c;
    return;
}
void Cell::setCell(int x, int y, char c){
    coordinateX=x;
    coordinateY=y;
    cell=c;
    return;
}