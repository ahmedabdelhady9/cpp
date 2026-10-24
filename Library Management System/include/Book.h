#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;
struct Book
{
    string title;
    string author;
    string isbn;
    string genre;
    bool isAvailable;

    Book():title(""),author(""),isbn(""),genre(""),isAvailable(true) {}

    Book(string t,string a,string i,string g,bool avail=true)
        : title(t),author(a),isbn(i),genre(g),isAvailable(avail) {}

    void display()const
    {
        cout<<"Title: "<<title
            <<" | Author: "<<author
            <<" | ISBN: "<<isbn
            <<" | Genre: "<<genre
            <<" | Status: "<<(isAvailable ? "Available" : "Borrowed")<<"\n";
    }
};


#endif // BOOK_H
