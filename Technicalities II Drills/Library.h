#pragma once
#include "../../../std_lib_facilities.h"
#include"Chrono.h"
using namespace Chrono;

namespace Lib{

    
    
    // Genre of a book
    enum class Genre {
        fiction = 1, nonfiction, periodical, biography, children, def
    };

    // a book in a library
    class Book {
	
        // Interface
    public:
        class Invalid {}; // to throw exception
        
        Book(string ISBN,string title,string author,
            Date copyright,Genre g,bool checked_out); // construct a book and validate it
        Book(); // construct a default book

        // non-modyfying functions
        string get_isbn() const { return ISBN; }
        string get_title() const { return title; }
        string get_author() const { return author; }
        Genre get_genre()const { return g; } 
        Date get_CR() const { return copyright; }
        bool is_checked_out()const { return checked_out; }
        //bool is_checked_in() { return !(checked_out); }

        //modyfying functions
        void checkout() { checked_out = true; }
        void checkin() { checked_out = false; };
        //Implementation details
    private:
        string ISBN, title, author;  // Basic book identitfication
        Date copyright;
        bool checked_out; // book present or not at the moment 
        Genre g;

      };

    // Book helper functions
    bool valid_isbn(string isbn);
    string print_genre(const Book& b) ; // Genre in string form
    string book_status(const Book& b) ; // checked out in string form
    ostream& operator<<(ostream& os, const Book& b);
    bool operator==(const Book& b1, const Book& b2);
    bool operator!=(const Book& b1, const Book& b2);

    //////////////////////////////////////////////////////////////    

    // a regular user of library
    class Patron {
    
        // Interface
    public:
        Patron(string user_name, int lib_card_num, float lib_fees); // make a Patron identity
        Patron(); // make a deafult patron

        // non-modyfying functions
        string get_user_name() const { return user_name; }
        int get_card_num() const { return lib_card_num; }
        float get_fees() const { return lib_fees; }

        //modyfying functions
        void set_fees(float lf,Patron p);
    
        //Implementation Details
    private:
        string user_name;
        int lib_card_num{ 000000 };
        float lib_fees{ 0.0F };

    };

    // Patron helper functions
    bool is_owing_fees(Patron p);
    
///////////////////////////////////////////////////////////////////////

    struct Transaction {

        Transaction(Book tb, Patron tp, Date td);
        Book tb;
        Patron tp;
        Date td;

    };


    class Library {

    public:

        //Library(vector<Book>book, vector<Patron>patron, vector<Transaction>transaction); // construct a library

        //non-modifying functions
        int get_book_total()const { return book.size(); }
        int get_patron_total() const { return patron.size(); }
        int get_tarsaction_total() const { return transaction.size(); }
        Book& get_book(int i)  { return book[i]; }
        Patron& get_patron(int i) { return patron[i]; }

        //modyfying functions
        void add_book(Book b1);
        void add_patron(Patron p1);
        void checkout_book(Book& b1,Patron& p1);


    private:
        vector<Book>book;
        vector<Patron>patron;
        vector<Transaction>transaction;


    };

    //helper functions
   

////////////////////////////////////////////////////////////////
    
}



    





