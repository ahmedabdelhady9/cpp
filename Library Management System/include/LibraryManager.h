#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H
#include <iostream>
#include <string>
#include <Book.h>
#include <Container.h>

bool operator==(const Book&b1,const Book&b2)
{
    return b1.isbn==b2.isbn;
}

class LibraryManager
{
private:
    Container<Book>catalog;
public:
    void addBook(const Book&book)
    {
        catalog.insertAtEnd(book);
        cout<<"Book added successfully!\n";
    }

    void removeBookByISBN(const string&isbn)
    {
        int index=0;
        bool found=false;
        for(auto it=catalog.begin(); it!=catalog.end(); it.next())
        {
            if((*it).isbn==isbn)
            {
                catalog.removeAtPosition(index);
                cout<<"Book removed successfully!\n";
                found=true;
                break;
            }
            index++;
        }
        if(!found)cout<<"Book with ISBN "<<isbn<<" not found!\n";
    }

    void searchBooks(const string&query)const
    {
        bool found=false;
        cout<<"\n--- Search Results ---\n";
        for(auto it=catalog.begin(); it!=catalog.end(); it.next())
        {
            Book b=*it;
            if(b.title==query || b.author==query || b.isbn==query || b.genre==query)
            {
                b.display();
                found=true;
            }
        }
        if(!found)cout<<"No matching books found.\n";
    }

    void borrowBook(const string&isbn)
    {
        for(auto it=catalog.begin(); it!=catalog.end(); it.next())
        {
            if((*it).isbn==isbn)
            {
                if((*it).isAvailable)
                {
                    (*it).isAvailable=false;
                    cout<<"Book borrowed successfully!\n";
                }
                else
                {
                    cout<<"Book is already borrowed.\n";
                }
                return;
            }
        }
        cout<<"Book not found!\n";
    }
    void returnBook(const string&isbn)
    {
        for(auto it=catalog.begin(); it!=catalog.end(); it.next())
        {
            if((*it).isbn==isbn)
            {
                if(!(*it).isAvailable)
                {
                    (*it).isAvailable=true;
                    cout<<"Book returned successfully!\n";
                }
                else
                {
                    cout<<"Book was not borrowed.\n";
                }
                return;
            }
        }
        cout<<"Book not found!\n";
    }

    void sortByTitle()
    {
        catalog.sort([](const Book&a, const Book&b)
        {
            return a.title<b.title;
        });
        cout<<"Catalog sorted by Title.\n";
    }

    void sortByAuthor()
    {
        catalog.sort([](const Book&a,const Book&b)
        {
            return a.author<b.author;
        });
        cout<<"Catalog sorted by Author.\n";
    }

    void sortByGenre()
    {
        catalog.sort([](const Book&a,const Book&b)
        {
            return a.genre<b.genre;
        });
        cout<<"Catalog sorted by Genre.\n";
    }

    void displayStatistics()const
    {
        int total=catalog.getSize();
        int available=0;
        int borrowed=0;

        for(auto it=catalog.begin(); it!=catalog.end(); it.next())
        {
            if((*it).isAvailable) available++;
            else borrowed++;
        }

        cout<<"\n--- Library Statistics ---\n";
        cout<<"Total Books     : "<<total<<"\n";
        cout<<"Available Books : "<<available<<"\n";
        cout<<"Borrowed Books  : "<<borrowed<<"\n";
    }

    void displayAllBooks()const
    {
        if(catalog.isEmpty())
        {
            cout<<"Catalog is empty.\n";
            return;
        }
        cout<<"\n--- Book Catalog ---\n";
        for(auto it=catalog.begin(); it!=catalog.end(); it.next())
        {
            (*it).display();
        }
    }
};


#endif // LIBRARYMANAGER_H
