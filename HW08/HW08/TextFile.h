/* 
 * File:   TextFile.h
 * Author: yasin
 *
 * Created on December 18, 2015, 6:42 PM
 */

#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include "File.h"
namespace _YasinAcikgoz{
    class TextFile:public File{
    public:
        TextFile(string _name, string _owner, string _size, string _lastMod, string _type);    
        string path();
        void ls(string command);
        const File& cd(string fileName);
        bool cp(const File& object);
        void setType(string str);
        string getType()const{ return _type;}
    private:
        string _type;
    };
}
#endif	/* TEXTFILE_H */

