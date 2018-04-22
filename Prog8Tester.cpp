//
// Created by Daniel on 11/4/2017.
//
#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>

#include "StringPlusPlus.h"

int main(){
    std::cout << "Hello, World!" << std::endl;

    string s = "hello world";
    char a = 'a';
    string b = charToString(a);
    bool c = true;
    string d = boolToString(c);
    string e = "sufFiX";
    string f = "SuffixA";
    bool g = endsWith(e, f);
    bool h = endsWith(e, 'a');
    g = startsWith(e,f);
    g = startsWith(e, 'x');
    g = equalsIgnoreCase(e,f);
    double pi = 3.141592653;
    string i = doubleToString(pi, 4);
    const vector<string> j = {"hello", "world", "my", "name", "is", "Daniel"};
    string l = " goat ";
    string k = stringJoin(j, l);
    vector<string> m = stringSplit(k, l);
    e = toUpperCase(e);
    string n = stringReplace(k, l, " ");
    string o = "                                                       ok                                                    ";
    o = trim(o);
    f = "bbbb";
    f = pigLatinfy(f);
    printf("your code ran all the way through");

    string retest = mystery("retest");



    return 0;
}