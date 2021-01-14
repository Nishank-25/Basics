// Hello World.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream> 
using namespace std;

int main()
{
    // double age;
    //std::string name;

    //std::cout << "Enter your name and age";
    //std::cin >> name;
    //
    //name += name;

    //cout << name;

    //cout << "Your name is" << name << "Your age is " << age << "and " << age * 12 << "months";



     /// Unsafe conversions\\\
    
         //int a = 200000;
         //char c = a; // try to squeeze a large int into a small char
       
         //int b = c;
         //if (a != b) // != means “not equal”
         //    cout << "oo!: " << a << "!=" <<c<<b
         //    << '\n';
         //
         //else
         //    cout << "Wow! We have large characters\n";
        



             //double d = 0;
             //while (cin >> d) { // repeat the statements below
             //// as long as we type in numbers
             //    int i = d; // try to squeeze a double into an int
             //    char c = i; // try to squeeze an int into a char
             //    int i2 = c; // get the integer value of the character
             //    cout << "d==" << d // the original double
             //        << " i==" << i // converted to int
             //        << " i2==" << i2 // int value of char
             //        << " char(" << c << ")\n"; // the char
             //}

             /// new notation//
    double d=3.2 ;
    int y{ d };

    cout << y;
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
