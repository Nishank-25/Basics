#include "Library.h"


namespace Lib {
    
    ////Library

    ///Library member functions

   void Library::add_book(Book b1){

       book.push_back(b1);
    
    }

   void Library::add_patron(Patron p1) {

       patron.push_back(p1);
   }

   void Library::checkout_book(Book& b1,Patron& p1){
       
       p1.set_fees(100.23F,p1); // set fees for patron
       b1.checkout();// checkout the book from Library
       Date d;
       Transaction t{ b1,p1,d }; // make a Transaction
       transaction.push_back(t); // save the Transaction
   }
/////////////////////////////////////////////////////////////////////    
  
   
   ////Transaction 

   Transaction::Transaction(Book b, Patron p, Date d)  // construct a Transaction
       :tb{ b }, tp{ p }, td{ d }
   {}
///////////////////////////////////////////////////////

     //// Book 

    ///Book member functions
    
    //constructor
    Book::Book(string i, string t, string a,Date cr,Genre g,bool c_o)
        :ISBN{ i }, title{ t }, author{ a },copyright{cr},g{ g },checked_out{c_o}
    {
        if (!valid_isbn(i)) throw Invalid{};
    }

    //default constructor
    const Book& default_book() {

        static Book b{"00 - 00 - 00 - 0","Title","Author",{},Genre::def,false };
        return b;
    }

    Book::Book()
         :  ISBN{default_book().get_isbn()}, title{ default_book().get_title()},
            author{ default_book().get_author()}, copyright{ default_book().get_CR()},
            g{ default_book().get_genre()},checked_out{ default_book().is_checked_out()}
    {}

    ////Book helper functions
   
     string print_genre(const Book& b) { // Genre in string form
       
        switch (int(b.get_genre())) {

        case 1: return "fiction";
        case 2:  return "nonfiction";
        case 3: return "periodical";
        case 4: return "biography";
        case 5:  return "children";
        case 6:  return "default";
        default:  return "non identified genre";
        };
    }

    
    string book_status(const Book& b) { //checked_out in string form
        if (b.is_checked_out() == true)return"checked-out";
        if (b.is_checked_out() == false)return"checked-in";
        else return"book_status(): Invalid";
    }

    bool valid_isbn(string isbn) {
        // check whether ISBN has fornmat n-n-n-x 
        // where n is an integer and x is a digit or a letter.

        return true;
    }

    ostream& operator<<(ostream& os, const Book& b)
    {
        return os
            << b.get_title() << endl
            << b.get_author() << endl
            << b.get_isbn() << endl
            /*<< b.get_Cr() << endl*/
            << print_genre(b) << endl
            << book_status(b) << endl;
    }

    bool operator==(const Book& b1, const Book& b2) {

        return b1.get_isbn() == b2.get_isbn();
    }
    bool operator!=(const Book& b1, const Book& b2) {

        return !(b1 == b2);
    }
////////////////////////////////////////////////////////

    ////Patron

    ///Patron member fucntions

    // constructor
    Patron::Patron(string uname, int cnum, float lfees)
        :user_name{ uname }, lib_card_num{ cnum }, lib_fees{ lfees }
    {
    }

    const Patron& default_patron() {
        static Patron pp{ "Noname",000000,0.0F }; // deafault Patron
        return pp;
    }

    // default constructor
    Patron::Patron()
        :user_name{ default_patron().get_user_name() },
        lib_card_num{ default_patron().get_card_num() },
        lib_fees{ default_patron().get_fees() }
    {
    }

    void Patron::set_fees(float lf,Patron p) { // set fees if Patron is owing a book
        
         lib_fees = lf;
          
    }

    ///Patron helper functions

    bool is_owing_fees(Patron p) 
    {
        if (p.get_fees() > 0.0F)return true;
        return false;
    }

}

