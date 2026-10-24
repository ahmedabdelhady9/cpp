#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <LibraryManager.h>
using namespace std;

int main()
{
    LibraryManager library;
    int choice;
    while(true)
    {
        cout<<"\n=========================================\n";
        cout<<"      LIBRARY MANAGEMENT SYSTEM          \n";
        cout<<"=========================================\n";
        cout<<"1. Add New Book\n";
        cout<<"2. Remove Book (by ISBN)\n";
        cout<<"3. Search Books (Title / Author / ISBN / Genre)\n";
        cout<<"4. Borrow Book\n";
        cout<<"5. Return Book\n";
        cout<<"6. Sort Books\n";
        cout<<"7. Display All Books\n";
        cout<<"8. Display Book Statistics\n";
        cout<<"9. Exit\n";
        cout<<"-----------------------------------------\n";
        cout<<"Enter your choice (1-9): ";

        if(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\n[Error] Invalid input! Please enter a number.\n";
            continue;
        }
        system("cls");
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if(choice==1)
        {
            string title,author,isbn,genre;
            cout<<"\nEnter Book Title: ";
            getline(cin,title);
            cout<<"Enter Author Name: ";
            getline(cin,author);
            cout<<"Enter ISBN: ";
            getline(cin,isbn);
            cout<<"Enter Genre: ";
            getline(cin,genre);

            library.addBook(Book(title,author,isbn,genre));
        }
        else if(choice==2)
        {
            string isbn;
            cout<<"\nEnter ISBN of the book to remove: ";
            getline(cin,isbn);
            library.removeBookByISBN(isbn);
        }
        else if(choice==3)
        {
            string query;
            cout<<"\nEnter Title, Author, ISBN, or Genre to search: ";
            getline(cin,query);
            library.searchBooks(query);
        }
        else if(choice==4)
        {
            string isbn;
            cout<<"\nEnter ISBN of the book to borrow: ";
            getline(cin,isbn);
            library.borrowBook(isbn);
        }
        else if(choice==5)
        {
            string isbn;
            cout<<"\nEnter ISBN of the book to return: ";
            getline(cin,isbn);
            library.returnBook(isbn);
        }
        else if(choice==6)
        {
            cout<<"\n--- Sort Options ---\n";
            cout<<"1. Sort by Title\n";
            cout<<"2. Sort by Author\n";
            cout<<"3. Sort by Genre\n";
            cout<<"Select sorting criteria (1-3): ";
            int sortChoice;
            cin>>sortChoice;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            if(sortChoice==1)library.sortByTitle();
            else if(sortChoice==2)library.sortByAuthor();
            else if(sortChoice==3)library.sortByGenre();
            else cout<<"\n[Error] Invalid sorting option.\n";
        }
        else if(choice==7)
        {
            library.displayAllBooks();
        }
        else if(choice==8)
        {
            library.displayStatistics();
        }
        else if(choice==9)
        {
            cout<<"\nExiting System. Goodbye!\n";
            break;
        }
        else
        {
            cout<<"\n[Error] Invalid choice! Please select between 1 and 9.\n";
        }
    }
    return 0;
}
