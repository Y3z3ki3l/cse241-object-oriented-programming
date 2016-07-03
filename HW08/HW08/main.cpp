/* 
 * File:   main.cpp
 * Author: yasin
 *
 * Created on December 17, 2015, 6:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "File.h"
#include "Directory.h"
#include "Executable.h"
#include "TextFile.h"

using namespace _YasinAcikgoz;

using namespace std;

vector<string> subfiles;
/*
 * 
 */
int main(){
    
    Directory dir("dosya1", "yasin", "10", "23:55 19 Dec");
    Executable exec("exe.out", "yasin", "25", "14:11 23 Jan", "g++");
    TextFile text("abc.txt", "yasin", "12", "07:23 05 May", "ASCII");
    TextFile text2("def.txt", "yasin", "1278", "14:23 31 Jun", "ASCII");
    Directory dir2("dosya2", "mustafa", "125", "00:23 04 Sep");
    Executable exec1("yasin.out", "yasin", "25", "19:45 27 Nov", "gcc");
    TextFile text1("ghi.txt", "ysa", "598", "04:43 07 Nov", "UNICODE");
    Directory dir3(".dosya3", "ahmet", "98",  "20:30 14 Aug");
    
    cout << "FILLING DIR1...\n";
    dir.cp(exec);
    dir.cp(text);
    dir.cp(text1);
    
    cout << "FILLING DIR2...\n";
    dir2.cp(dir3);
    dir2.cp(text2);
    dir2.cp(exec1);
    cout << "'ls' call with command 'l'\n";
    cout << "____________________________\n";
    dir.ls("l");
    
    cout << "\n'ls' call with command 'a'\n";
    cout << "____________________________\n";
    dir2.ls("a");
    
    
    cout << "\n'ls' call for executable file.\n";
    cout << "____________________________\n";
    exec.ls("R");
    cout << "\n'ls' call for text file.\n";
    cout << "____________________________\n";
    text.ls("Rl");
    
    
    cout << "\n'cd' call for executable file.\n";
    cout << "____________________________\n";
    exec1.cd("R");
    cout << "\n'cd' call for text file.\n";
    cout << "____________________________\n";
    text2.cd("Rl");
    
    
    cout << "\n'cd' call for directory.(dosya1 not include dosya2)\n";
    cout << "____________________________\n";
    dir.cd("dosya2");
    
    cout << "\n'cd' and 'cp' call for directory.\n";
    cout << "____________________________\n";
    
    dir.cp(dir2.cd(".dosya3"));
    cout << "\n'ls' call with command 'la'\n";
    cout << "____________________________\n";
    dir.ls("la");
    
    
    return 0;
}

