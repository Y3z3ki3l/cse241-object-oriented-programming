#include "Executable.h"
#include "TextFile.h"
#include "Directory.h"

#include <iostream>
using std::endl;
using std::cout;
using std::cerr;
//using namespace std;

namespace _YasinAcikgoz{
    Executable::Executable(string _name, string _owner, string _size, string _lastMod, string _compiler){
        setName(_name);
        setOwner(_owner);
        setSize(_size);
        setLastModification(_lastMod);
        setCompiler(_compiler);
        setPermission("rwx");
    }
    /*
     * Executable icin cd fonksiyonu kullanilamayacagindan ekrana hata basar.
     */
    const File& Executable::cd(string fileName){
        cerr << "Wrong 'cd' command: Program doesn't changes directory of an executable file." << endl;
    }
    /*
     * Executable icin cp fonksiyonu kullanilamayacagindan ekrana hata basar.
     */
    bool Executable::cp(const File& object){
        if(dynamic_cast <const Executable*>(&object)!=NULL){
            cerr << "Wrong 'cp' command: Copy an executable file to another executable file." << endl;
            return false;
        }
        else if(dynamic_cast <const TextFile*>(&object)!=NULL){
            cerr << "Wrong 'cp' command: Copy an text file to executable file." << endl;
            return false;
        }
        else if(dynamic_cast <const Directory*> (&object)!=NULL){
            cerr << "Wrong 'cp' command: Copy an directory to executable file." << endl;
            return false;
        }
    }
    /*
     * Executable icin ls fonksiyonu kullanilamayacagindan ekrana hata basar.
     */
    void Executable::ls(string command){
        cerr << "Wrong 'ls' command: Program doesn't list contents of an executable file." << endl;
    }
    string Executable::path(){
        return getPath();
    }
    void Executable::setCompiler(string str){
        _compiler=str;
    }
}