/* 
 * File:   Director.h
 * Author: yasin
 *
 * Created on December 18, 2015, 6:31 PM
 */

#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include "File.h"
#include <vector>

using namespace std;

namespace _YasinAcikgoz{
    class Directory: public File{
    public:
        Directory();
        Directory(string _name, string _owner, string _size, string _lastMod);
        string path();
        void ls(string command);
        File& cd(string fileName);
        bool cp(const File& object);
        
        void setNumberOfFiles(int nof);
        int getNumberOfFiles()const{ return numberOfFiles;};
        void push();
        
    private:
        vector<File*> files;
        int numberOfFiles;
    };
}

#endif	/* DIRECTOR_H */

