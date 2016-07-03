/* 
 * File:   File.h
 * Author: yasin
 *
 * Created on December 18, 2015, 5:23 PM
 */

#ifndef FILE_H
#define	FILE_H

#include <string>
#include <cctype>
#include <iostream>
#include <vector>

using std::string;
using namespace std;
namespace _YasinAcikgoz{
    class File{
    public:
        File();

        virtual string path() = 0;
        virtual void ls(string command) = 0;
        virtual const File&  cd(string fileName) = 0;
        virtual bool cp(const File& object) = 0;
        void setNumberOfFiles(int nof);
        int getNumberOfFiles();

        //getters
        string getName()const {return name; }
        string getOwner()const {return owner; }
        string getSize()const {return size; }
        string getLastModification()const {return lastModification; }
        string getPermission()const {return permission; }
        string getPath()const {return _path;}
        
        //setters
        void setName(string str);
        void setOwner(string str);
        void setSize(string str);
        void setLastModification(string str);
        void setPermission(string str);
        void setPath(string str);
        
        void toString(const File& object);

    private:
        string name;
        string owner;
        string size;
        string lastModification;
        string permission;
        string _path;
    };
}
#endif	/* FILE_H */

