#include "File.h"
#include "Directory.h"
#include "Executable.h"
#include "TextFile.h"

#include <iostream>
#include <iomanip>

using std::endl;
using std::cout;
using std::setw;

using namespace std;

namespace _YasinAcikgoz{
    /*directory icin 4 parametreli constructor*/
    Directory::Directory(string _name, string _owner, string _size, string _lastMod){
        setName(_name);
        setOwner(_owner);
        setSize(_size);
        setLastModification(_lastMod);
        setNumberOfFiles(0);
        setPermission("rw-");
    }
    void Directory::setNumberOfFiles(int nof){
        numberOfFiles=nof;
    }
    /* 
     * change directory fonksiyonu.
     * gelen stringi files vectorunun icinde arar
     * bulursa files referansi dondurur. 
     * bulamazsa this dondurur.
     * 
     */
    File& Directory::cd(string fileName){   
        int index;
        int status=false;
        for(int i=0; i<getNumberOfFiles(); ++i){
            if(files[i]->getName()==fileName){
                index=i;
                status=true;
            }
        }
        if(status==true)
            return *files[index];
        else{
            cerr << "Change directory error.\n";
            return *this;
        }
    }
    /*
     * file referansini kullanarak dynamic cast ile tipleri tespit eder.
     * her tipe gore yeni pointer olusturarak new'le yer alir ve icini doldurur.
     * ardindan push_back ile files vektorunun icine atar 
     * 
     */
    bool Directory::cp(const File& object){
        string a;
        a=("/" + getName());
        if(NULL != dynamic_cast <const Directory*> (&object)){
            Directory * dir = new Directory(object.getName(), object.getOwner(), object.getSize(), object.getLastModification());
            dir->setPath(a);
            files.push_back(dir);
        }
        else if(NULL != dynamic_cast <const TextFile*> (&object)){
            const TextFile *temp = dynamic_cast <const TextFile*> (&object);
            TextFile* text = new TextFile(object.getName(), object.getOwner(), object.getSize(), object.getLastModification(),"temp");
            text->setName(temp->getName() );
            text->setOwner(temp->getOwner());
            text->setSize(temp->getSize());
            text->setLastModification(temp->getLastModification());
            text->setType(temp->getType());
            files.push_back(text);
        }
        else if(NULL != dynamic_cast<const Executable*> (&object)){
            const Executable *temp = dynamic_cast<const Executable*> (&object);
            Executable *exec = new Executable(object.getName(), object.getOwner(), object.getSize(), object.getLastModification(),"temp");           
            exec->setName(temp->getName());
            exec->setOwner(temp->getOwner());
            exec->setSize(temp->getSize());
            exec->setLastModification(temp->getLastModification());
            exec->setCompiler(temp->getCompiler());
            files.push_back(exec);
        }
        ++numberOfFiles;
        return true;
    }
    /*
     * gelen komuta gore dosya iceriklerini
     * files vektorunun kullanarak ekrana basar (l, a ve la)
     * 
     */
    void Directory::ls(string command){
        /* calculate the size for good output formatting*/
        int temp1=0, temp2=0, maxN=0, maxS=0;
        for (unsigned int i=0; i<files.size(); ++i){
           temp1=files[i]->getName().length();
           temp2=files[i]->getSize().length();

            if(temp1>maxN)
                maxN=temp1;
           if(temp2>maxS)
                maxS=temp2;
        }
        if(command=="l"){
            for (unsigned int i=0; i<files.size(); ++i){
                if(files[i]->getName()[0]!='.'){
                    cout << files[i]->getPermission() << setw(maxN+5) << right;
                    cout << files[i]->getOwner() << setw(maxS+2) << right;
                    cout << files[i]->getSize() << "  ";
                    cout << files[i]->getLastModification() << "  ";
                    cout << files[i]->getName() << endl;
                }
            }
        }
        else if(command=="a"){
            for (unsigned int i=0; i<files.size(); ++i){
                 cout <<  files[i]->getName() << "   " ;
                 if(i%4==0 && i!=0)
                     cout << endl;
            }
            cout << endl;
        }
        else if(command=="la" || command=="al"){
            for (unsigned int i=0; i<files.size(); ++i){
                cout << files[i]->getPermission() << setw(maxN+5) << right; 
                cout << files[i]->getOwner() << setw(maxS+2) << right;
                cout << files[i]->getSize() << "  ";
                cout << files[i]->getLastModification() << "  ";
                cout << files[i]->getName() << endl;
            }
        }
        else
            cerr << "Wrong 'ls' command: Parameter of 'ls' is wrong." << endl;
    }
    string Directory::path(){     
        return getPath();
    }
}