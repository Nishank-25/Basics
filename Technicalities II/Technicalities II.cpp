// Technicalities II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"../../../std_lib_facilities.h"

class Year { // year in [min:max) range 

static const int min = 1800;  // we use static to make sure that there is just
static const int max = 2200;  //  one copy of the value in the program, 
                             // rather than one per object of the class.
 

public: 
    class Invalid { };
    Year(int x) : y{x} 
    { if (x<min || max<=x) 
        throw Invalid{}; 
    } 
    int year() { return y; }

private: int y;
};

   


// a simple Date class

//class Date {
//
//    // Interface details which users have access to
//public: class Invalid{};
//        Date(Year yy, Month mm, int dd);   //Constructs Date object,intiliaze members, check for invalid date
//        void add_day(int n){}
//
//        int month() { return Month m; }
//        int day() { return d; }
//        int year() { return Year y; }
//
//        // Implementation details which users can't acccess
//private: int y, m, d;
//       bool is_valid();
//};
//
//Date::Date(int yy, int mm , int dd)  
//     : y{ yy }, m{ mm }, d{ dd } 
//{
//    if (!is_valid()) throw Invalid{};
//}

//void f(int x, int y)
//try
//{
//    Date dxy{ 2004,x,y };
//    cout << dxy << '\n';
//    dxy.add_day(2);
//}
//catch (Date::Invalid)
//{
//    error("INvalid date");
//}

// an enum class Month
enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    
};

// operator overloading

//Month operator++(Month& m) // prefix increment operator
//{
//    m = (m == Month::dec) ? Month::jan : Month(int(m) + 1); // “wrap around” 
//    return m;
//}

// an plain enum Day
enum Day {
    mon=1,tue,wed,thu,fri,sat,sun
};

int main()
{
   // // enum class

   // Month m = Month::feb; // Ok
   // Month m2 = feb; // error: feb is not in scope 
   // m = 7; // error: can’t assign an int to a Month 
   // int n = m; // error: can’t assign a Month to an int 
   // Month mm = Month(7); // convert int to Month (unchecked)

   // // plain enums

   //Day d = tue; // OK: tue in scope 
   //Day d2 =  Day::tue; // also OK 
   //d = 7; // error: can’t assign an int to a Month
   // int n = d; // OK: we can assign a Month to an int
   // Day dd = Day(7); // convert int to Month (unchecked)

    // operator overloading 
    /*Month m = Month::sep;
    ++m;
    ++m;
    ++m;
    ++m;*/
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
