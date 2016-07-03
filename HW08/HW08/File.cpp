#include "File.h"

using std::cout;
using std::endl;
namespace _YasinAcikgoz{
    //no parameter constructor
    File::File(){
        setName("unknown");
        setOwner("unknown");
        setSize("0");
        setLastModification("unknown");
    }
    //setters
    void File::setName(string str){
        name=str;
    }
    void File::setOwner(string str){
        owner=str;
    }
    void File::setSize(string str){
        size=str;
    }
    void File::setLastModification(string str){
        lastModification=str;
    }
    void File::setPermission(string str){
        permission=str;
    }
    void File::setPath(string str){
        _path=str;
    }
    //toString
    void File::toString(const File& object){ 
        cout << "Name: " << object.getName() << endl << "Owner: " << object.getOwner() 
            << endl  << "Size: " << object.getSize() << endl << "Last modification: " 
            << object.getLastModification() << endl;
    }
}