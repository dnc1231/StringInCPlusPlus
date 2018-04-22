#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>

#include "StringPlusPlus.h"

// StringPlusPlus.cpp -- EE 312 Project 8

/* Student information for project:
 *
 *
 * On my honor, Daniel Canterino, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Daniel Canterino
 * email address: dnc1231@verizon.net
 * UTEID: djc3323
 * Section 5 digit ID: 16115
 * Number of slip days used on this assignment: 0
 */

using namespace std;

/* Converts a char value to the string containing the char. */
string charToString(char c) {
    stringstream ss; string s;
    ss << c;//puts the char into the stringstream
    ss >> s;//takes the care from the stringstream and puts it into a string type
    return s;
}

/* Converts bool b to the corresponding string, "true" or "false". */
string boolToString(bool b) {
    if (b){
        string s = "true";
        return s;
    }
    string s = "false";
    return s;
}

/* Returns true if s ends with suf, false otherwise. */
bool endsWith(string s, string suf) {
    if (s.length() >= suf.length()) {//if the suffix is longer than the word, then it auto returns false
        for (int i = s.length() - suf.length(), j = 0; i < s.length(); i++, j++) {//compares each char in suffix to that of the string ending to see if its false
            if (s[i] != suf[j]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

/* Returns true if s ends with ch, false otherwise. */
bool endsWith(string s, char ch) {
    if (s[s.length() - 1] == ch){
        return true;
    }
    return false;
}

/* Returns true if s starts with pref, false otherwise. */
bool startsWith(string s, string pref) {
    if (s.length() >= pref.length()) {//if the prefix is longer than the word, then it auto returns false
        for (int i = 0; i < pref.length(); i++) {//checks the first chars of the string to that of the prefix and returns true if all match
            if (s[i] != pref[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

/* Returns true if s starts with ch, false otherwise. */
bool startsWith(string s, char ch) {
    if (s[0] == ch){
        return true;
    }
    return false;
}

/* Returns true if s1 and s2 are equal if case is ignored, false otherwise. */
bool equalsIgnoreCase(string s1, string s2) {
    string lowerS1 = toLowerCase(s1);//ensures everything is lowercase to make comparing easier
    string lowerS2 = toLowerCase(s2);
    if (lowerS1 == lowerS2){
        return true;
    }
    return false;
}

/* Converts a floating-point number into the corresponding string form with dig digits after the decimal point. */
string doubleToString(double d, int dig) {
    stringstream ss; string s;
    ss << fixed << setprecision(dig) << d;
    ss >> s;
    return s;
}

/* Converts a string into its corresponding double value. */
// pre: s contains a fixed point representation of a double 
double stringToDouble(string s) {
    return stod(s);
}

/* Concatenates the strings in vector (maintaining their order) into a single string. In the returned string,
   any two string elements from the vector are separated by the given delimiter. */
string stringJoin(const vector<string> & v, string delimiter) {
    string s;
    for (int i = 0; i < v.size(); i++){
        s.append(v[i]);//appends each string in the vector to the new string to make one string
        if (i != v.size() - 1){
            s.append(delimiter);//does not append the delimiter after the last string is appended
        }
    }
    return s;
}

/* Break apart string str into a list of strings separated by the specified delimiter, and place each of
   those strings in a vector. The order of the strings should not change. */
vector<string> stringSplit(string str, string delim){
    vector<string> v; string copy = str; int next; stringstream ss; int i = 0; int j = 0; string cur;
    while (copy.find(delim) != -1){
        next = copy.find(delim);
        while (next != 0){
            ss << copy[0];
            copy.erase(0, 1);//erases the first element to effectively shift over the string
            next--;
        }
        ss >> cur;
        v.push_back(cur);//puts the string into a new vector position
        ss.clear();//clears stringstream for next word
        while (j < delim.length()){//gets rid of the deliminator from the string
            copy.erase(0, 1);
            j++;
        }
        j= 0;
    }
    v.push_back(copy);//puts the last string into the vector
    return v;
}


/* Return a lower case version of string s. */
string toLowerCase(string s) {
    string lower; char offset = 32; stringstream ss;//to convert from upper to lower
    for(int i = 0; i < s.length(); i++){
        if (s[i] < 'a'){
            char a = s[i] + offset;//makes a new char offset to ensure it's lowercase
            ss << a;
        }
        else if (s[i] >= 'a'){//puts the char into the stringstream if it's already lowercase
            ss << s[i];
        }
    }
    ss >> lower;
    return lower;
}

/* Return an upper case version of string s. */
string toUpperCase(string s) {
    string upper; char offset = 32; stringstream ss;//to convert from upper to lower
    for(int i = 0; i < s.length(); i++){
        if (s[i] >= 'a'){//if it's not an upper case letter already, we offset it to be capitalized
            char a = s[i] - offset;
            ss << a;
        }
        else if (s[i] < 'a'){//if it's already capital, puts the char into the stringstream
            ss << s[i];
        }
    }
    ss >> upper;
    return upper;
}

/* Return a new string which is orig with all occurrences of old replaced with repl. */
string stringReplace(string orig, string old, string repl) {
    while (orig.find(old) != -1){//continues searching for the old string string to replace until there are none left
        orig.replace(orig.find(old), old.length(), repl);
    }
    return orig;
}

/* Returns a new string which is s with all leading and trailing whitespace removed. */
string trim(string s) {
    stringstream ss; string n;
    for(int i = 0; i < s.length(); i++){//removes any whitespace in the string until the end of the string is reached
        if (s[i] != ' '){
            ss << s[i];
        }
    }
    ss >> n;
    return n;
}

/* Return a new string that contains s translated into pig latin. The string may contain blank spaces and 
   (possibly one) punctuation symbol at the end of words. There will not be punctuation embedded in words, and there will not be digits.  */
string pigLatinfy(string s) {
    stringstream ss; string n; int j = 0;

    while ((s[j] != 'A') && (s[j] != 'a') && (s[j] != 'E') && (s[j] != 'e') && (s[j] != 'I') && (s[j] != 'i')
           && (s[j] != 'O') && (s[j] != 'o') && (s[j] != 'U') && (s[j] != 'u') && (s[j] != 'Y') && (s[j] != 'y')
           && j < s.length()){
        j++;//finds index of first letter that is not a vowel or the end of the string, whichever comes first
    }
    for (int i = j; i < s.length(); i++){//puts the letters starting at the first vowel into the stream
        ss << s[i];
    }
    for (int i = 0; i < j; i++){//puts the letters before the vowel into the stream
        ss << s[i];
    }
    if ((s[0] == 'A') || (s[0] == 'a') || (s[0] == 'E') || (s[0] == 'e') || (s[0] == 'I') || (s[0] == 'i')//adds 'yay' to words that begin with vowels
        || (s[0] == 'O') || (s[0] == 'o') || (s[0] == 'U') || (s[0] == 'u') || (s[0] == 'Y') || (s[0] == 'y')){
        ss << "yay";
    }
    else{
        ss << "ay";
    }
    ss >> n;
    return n;

}

string mystery(string str){
    string result = "";
    int n = str.length();
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            result = str[i] + result;
        }
        else result += str[i];
    }
    return result;
}