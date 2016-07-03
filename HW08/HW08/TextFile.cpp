#include "File.h"
#include "TextFile.h"
#include "Executable.h"
#include "Directory.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cerr;
namespace _YasinAcikgoz{
    TextFile::TextFile(string _name, string _owner, string _size, string _lastMod, string _type){
        setName(_name);
        setOwner(_owner);
        setSize(_size);
        setLastModification(_lastMod);
        setType(_type);
        setPermission("rw-");
    }
    /*
     * TextFile icin cd fonksiyonu kullanilamayacagindan ekrana hata basar.
     */
    const File& TextFile::cd(string fileName){
        cerr << "Wrong 'cd' command: Program doesn't changes directory of an text file." << endl;
    }
    /*
     * TextFile icin cp fonksiyonu kullanilamayacagindan ekrana hata basar.
     */
    bool TextFile::cp(const File& object){
        if(dynamic_cast <const TextFile*> (&object)!=NULL){ 
            cerr << "Wrong 'cp' command: Copy an text file to another text file." << endl;
            return false;
        }
        else if(dynamic_cast <const Executable*> (&object)!=NULL){
            cerr << "Wrong 'cp' command: Copy an executable file to text file." << endl;
            return false;
        }
        else if(dynamic_cast <const Directory*> (&object)!=NULL){
            cerr << "Wrong 'cp' command: Copy an directory to text file." << endl;
            return false;
        }
    }
    /*
     * TextFile icin cd fonksiyonu kullanilamayacagindan ekrana hata basar.
     */
    void TextFile::ls(string command){
        cerr << "Wrong 'ls' command: Program doesn't list contents of an text file." << endl;
    }
    string TextFile::path(){
        return getPath();
    }
    void TextFile::setType(string str){
        _type=str;
    }
}