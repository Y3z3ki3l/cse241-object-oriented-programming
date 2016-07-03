/* 
 * File:   Executable.h
 * Author: yasin
 *
 * Created on December 18, 2015, 6:41 PM
 */

#ifndef EXECUTABLE_H
#define	EXECUTABLE_H

#include "File.h"
namespace _YasinAcikgoz{
    class Executable:public File{
    public:
        Executable(string _name, string _owner, string _size, string _lastMod, string _compiler);    
        string path();
        void ls(string command);
        const File&  cd(string fileName);
        bool cp(const File& object);
        void setCompiler(string str);
        string getCompiler()const{ return _compiler; }
    private:
        string _compiler;
    };
}
#endif	/* EXECUTABLE_H */

