// Technicalities II Drills.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"../../../std_lib_facilities.h"
//#include"Library.h" // E9
//using namespace Lib; // E9



// E2

// A class reading names and ages printing and sorting them
//class Name_pairs {
//
//public: 
//   string read_names();
//    void read_ages();
//   void print();
//   void  Sort();
//
//
//private: 
//    vector<string>name;
//    vector<int>age;
//};
//
//// read names 
//string Name_pairs::read_names() {
//    
//    string s;
//    cout << "Enter name :";
//    cin >> s;
//    if (s == "Noname")return "exit";
//    name.push_back(s); 
//    return "success";
//}
//
//// read age
//void Name_pairs::read_ages() {
//    int a=1;
//    cout << "Enter age: ";
//    cin >> a;
//    if (a < 0) { // check for negative ages
//        cerr << "Invalid age \n"; 
//        read_ages(); 
//    }
//  
//    else age.push_back(a);
//}
//
//// print name,age
//void Name_pairs::print() {
//
//    cout << "name,age pairs are \n";
//    for (int i = 0;i < name.size();++i)
//        cout << name[i] << "," << age[i] << "\n";
//    
//}
//
//// sort name and age(according to name)
//void Name_pairs::Sort() {
//
//     if(name.size()>1){
//         // make a copy of name and age vector
//        vector<string>name_copy = name;
//        vector<int>age_copy = age; 
//        sort(name.begin(), name.end());
//
//        // sort age according to sorted names
//        for (int i = 0;i < name.size();++i)
//            for (int j = 0;j < age.size();++j)
//            {
//                if (name[i] == name_copy[j])age[i] = age_copy[j]; 
//            }
//     }
//}
//void E2() {
//
//    Name_pairs info;
//    string command;
//
//    cout << "Enter Noname to exit \n";
//    while (command != "exit") {
//        command = info.read_names();
//        if (command != "exit") info.read_ages();
//    }
//    info.print();
//    info.Sort();
//    cout << "After sorting \n";
//    info.print();
//}

// E 5-9

//void Lib_menu();
//void books();
//static Library l; // create a new Library
//      
//void books() {
//
//     // Add books to library
//
//    static const Book b{ "12-12-23-i", "PPP", "Bjarne", { 2014,Month::mar,9 }, Genre::nonfiction,false };
//    static const Book b2{ "12-12-23-h","Primer","Ajay",{2020,Month::may,8},Genre::nonfiction,false };
//    static const Book b3{};
//
//    l.add_book(b);
//    l.add_book(b2);
//    l.add_book(b3);
//
//    Lib_menu();
//
//}
//
//void backto_mainmenu() {
//    char ch;
//    cout << "Enter * for main menu\n";
//    cin >> ch;
//    if (ch == '*') Lib_menu();
//    else error("Thanks for visiting");
//
//}
//
//void Lib_menu() {
//
//    
//    system("cls");
//    int choice;
//    cout << "***Welcome to Narrow Library***\n";
//    cout << "1.Books \n2.Be a Patron \n3.Take a book \n4.Return a book \n5.Exit\n 6.Library Details\n";
//    cin >> choice;
//
//    switch (choice) {
//
//    case 1:
//    {
//        // Show all the books in library
//        int i = 0;
//        while (i < l.get_book_total()) {
//            cout << l.get_book(i) << endl;
//            i++;
//
//        }
//        backto_mainmenu();
//        break;
//    }
//    case 2:
//    {
//
//        Patron p;
//        string name;int num = 0, n = l.get_patron_total();
//
//        cout << "Enter your name: ";
//        cin >> name;
//
//        //check if already a Patron
//        for (int i = 0;i < n;++i)
//        {
//            p = l.get_patron(i);
//            if (p.get_user_name() == name) {
//                cerr << "You are already a Patron\n"; Lib_menu();
//            }
//        }
//
//        // add patron to library
//        num = n + 1234;
//        p = { name,num,0.0F };
//        l.add_patron(p);
//
//
//        cout << "Thanks for becoming a part of Narrow \n";
//        backto_mainmenu();
//        break;
//    }
//    case 3:
//    {
//        //Take a book
//
//        
//        string name;
//        int num = 0, flag = 0,
//            np = l.get_patron_total(), nb = l.get_book_total();
//
//        cout << "Enter your name: ";
//        cin >> name;
//        Patron p, p1;
//
//        //check if not a Patron
//        for (int i = 0;i < np;++i)
//        {
//            p = l.get_patron(i);
//            if (p.get_user_name() == name) { ++flag;  p1 = p; };
//        }
//        if (flag != 1)error(name, " not found");
//
//        cout << "Enter the name of book";
//        cin >> name;
//        Book b, b1;
//
//        //check if library has this book
//        for (int i = 0;i < nb;++i)
//        {
//            b = l.get_book(i);
//            if (b.get_title() == name) { ++flag;  b1 = b; }
//        }
//        if (flag != 2)error(name, "not found");
//
//        //check if book is present at the moment(checkedout or not)
//
//        if (b1.is_checked_out() == true)
//        {
//            cout << "Sorry someone else took it";
//            backto_mainmenu();
//        }
//
//        // check whether Patron owes fees
//        if (is_owing_fees(p1))error("You owe fees. Sorry can't take book");
//
//        l.checkout_book(b1, p1);
//
//        // make changes in library
//        for (int i = 0;i < nb;++i)
//        {
//            b = l.get_book(i);
//            if (b == b1) l.get_book(i) = b1;
//        }
//        for (int i = 0;i < np;++i)
//        {
//            p= l.get_patron(i);
//            if (p.get_user_name() == p1.get_user_name()) l.get_patron(i) = p1;
//        }
//
//        cout << "Transaction Complete\n";
//        backto_mainmenu();
//        break;
//    }
//    case 4:
//    {
//        string name;
//        int num = 0, flag = 0,
//            np = l.get_patron_total(), nb = l.get_book_total();
//
//        cout << "Enter your name: ";
//        cin >> name;
//        Patron p, p1;
//
//        //check if not a Patron
//            for (int i = 0;i < np;++i)
//            {
//                p = l.get_patron(i);
//                if (p.get_user_name() == name) { ++flag;  p1 = p; };
//            }
//        if (flag != 1)error(name, " not found");
//
//        cout << "Enter the name of book";
//        cin >> name;
//        Book b, b1;
//
//        //check if library has this book
//        for (int i = 0;i < nb;++i)
//        {
//            b = l.get_book(i);
//            if (b.get_title() == name) { ++flag;  b1 = b; }
//        }
//        if (flag != 2)error(name, "is not a part of Narrow");
//
//        //check if book is present at the moment(checkedout or not)
//
//        if (b1.is_checked_out() == false)
//        {
//            cout << "No one has took this book";
//            backto_mainmenu();
//        }
//
//        b1.checkin();
//        p1.set_fees(0.0F,p1);
//
//        // make changes in library
//        for (int i = 0;i < nb;++i)
//        {
//            b = l.get_book(i);
//            if (b == b1) l.get_book(i) = b1;
//        }
//        for (int i = 0;i < np;++i)
//        {
//            p = l.get_patron(i);
//            if (p.get_user_name() == p1.get_user_name()) l.get_patron(i) = p1;
//        }
//
//        cout << "Thankyou, Come again\n";
//        backto_mainmenu();
//
//        break;
//        
//    }
//    case 5: cout << "Thanks for visiting";break;
//    case 6:
//    {
//        cout << "Total Books: " << l.get_book_total();
//        cout << "Total Patrons: " << l.get_patron_total();
//        break;
//    }
//    default: error("Wrong choice, Thanks for visiting");
//
//    }
//
//}

//E10

//bool is_leapyear(int y)
//// any year divisible by 4 except centenary years not divisible by 400
//// % is the modulo (remainder) operator
//{
//    if (y % 4) return false;
//    if (y % 100 == 0 && y % 400) return false;
//    return true;
//}
//
//void E10() {
//
//    cout << "please enter a year: ";
//
//    int n;
//    while (cin >> n) {	// read a year
//        cout << n << " is ";
//        if (is_leapyear(n) == false) cout << "not ";
//        cout << "a leapyear\n";
//        cout << "Try again: ";
//    }
//    keep_window_open("~");	// For some Windows(tm) setups
//}

//E13(Some significant changes are still needed)

// Rational Number 
//class Rational {
//
//public: 
//
//    class Invalid{};
//    Rational(int num,int den);
//    
//
//
//
//    int num; // numerator
//    int den; // denominator(can't be 0)
//    const char frac='/'; // '/' divides upper and lower
//
//};
//
//bool is_valid_R(int d) { // denominator shouldnot be a 0
//
//    if (d == 0)return false; // denominator can't be zero
//    //if (n.get_kind() != number) return false; // Invalid numerator
//    //if (d.get_kind() != number) return false; // Invalid denominator
//    return true;
//}
//
//
//Rational::Rational(int n,int d) : num{n},den{d}
//{
//    if (!is_valid_R(d))  error("Not a rational number\n"); //throw Invalid{};
//    else cout << "A rational number\n";
//}
//
//
//
////helper functions
//
//double to_double(Rational r1)	// convert to double (to floating point representation)
//{
//    return double(r1.num) / r1.den;
//}
//
//bool operator==(Rational& r1, Rational& r2)
//{
//    if (to_double(r1) == to_double(r2))return true;
//    return false;
//}
//
//
//
//
////arithmetic functions
//Rational operator+(Rational& r1, Rational& r2)
//{
//    Rational r(r1.num*r2.den + r1.den*r2.num, r1.den*r2.den );
//    return r;
//}
//
//ostream& operator<<(ostream& os, Rational r1)
//{
//    return cout << '(' << r1.num << r1.frac<< r1.den << ')'<<endl;
//}
//
//Rational operator-(Rational& r1, Rational& r2)
//{
//    Rational r(r1.num * r2.den - r1.den * r2.num, r1.den * r2.den);
//    return r;
//}
//
//Rational operator*(Rational& r1, Rational& r2)
//{
//    Rational r(r1.num * r2.num, r1.den * r2.den);
//    return r;
//}
//
//Rational operator/(Rational& r1, Rational& r2) //
//{
//    Rational r(r1.num * r2.den, r1.den * r2.num);
//    return r;
//}
//
//Rational operator-(Rational r1)	// unary minus
//{
//    return Rational(-r1.num, r1.den);
//}
//
//
//
//void E13() {
//
//    while (cin) {
//        int n, d;
//        char f;
//        cout << "Enter the Rational number(n/d) form \n";
//        cin >> n >> f >> d;
//        Rational r{ n,d};
//        Rational r1(4,4);
//        cout << r<<endl;
//        cout << "Sum: " << r1 + r<<endl;
//        cout << "Difference: " << r1 - r << endl;
//        cout << "Product: " << r1 * r << endl;
//        cout << "Division: " << r1 / r << endl;
//        if (r1 == r)cout << "Equal" << endl;
//        else cout << "Not Equal" << endl;
//        
//        /*if (t1.get_kind() != '/') cerr << "'/' expected, ";
//        if (t2.get_kind() != number)cerr << "Not a rational number\n";*/
//        
//
//
//
//    }
//}





int main()
{
    try
    {
        //E2();
       // books(); //E5-E9
       //  E10();
       //E13();
        
        
    }
    catch(exception& e)
    {
        cerr <<"Exception:"<< e.what()<<endl;
        //E13();
       }
    /*catch (Book::Invalid) {
        error("Invalid ISBN");
    }*/
    /*catch (Rational::Invalid) {
        error("Invalid Denominator");
    }*/
    catch (...)
    {
        cerr << "Exception";
    }
    
}


