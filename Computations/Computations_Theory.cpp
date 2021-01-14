// Computations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
#include <vector>

using namespace std;

int main()
{
    // Notion used for constant expressions
    //constexpr double pi = 3.14159;


    // conversions

    /*int x;
    double x = 5 / 2;
    cout << x;
    x = 5.0 / 2.0;
    cout << x;*/


    // iterations


    /// while

        //int i = 0; // start from 0
    //char c = 'a';
    //while (i < 26) {
    //    cout << c << "\t" << int(c) << "\n";
    //    ++c;
    //    ++i;
    //}
    /*int i = 0;
     while (i < 32) {
        cout << digit;
        ++i;
        ++digit;
     }*/

     /// for

     /*char lower_case = 'a',upper_case='A',digit='0';
     for (int i = 0;i < 26;i++) {
         cout << lower_case << " " << int(lower_case) << " "
             << upper_case << " " << int(upper_case) << " "
             << digit << " " << int(digit)<<"\n";
         ++lower_case;
         ++upper_case;
         ++digit;
     }*/


     // vector

    /*vector<datatype>vector_name(size);
    vector<datatype>vector_name = {data};
    vector<datatype>vector_name; // starts as empty

    */


    /// range for loop

    //vector<int> v = { 5, 7, 9, 4, 6, 8 };
    //for (int x : v) // for each x in v
    //    cout << x << '\n';

    /// push_back

    /*vector<int>v1;
    v1.push_back(22.3434);
    cout << v1[0];*/


    /// temperature example

    //// read some temperatures into a vector
    //
    //    //vector<double> temps; // temperatures
    //    //for (double temp; cin >> temp; ) // read into temp
    //    //    temps.push_back(temp); // put temp into vector
    //    //    // . . . do something . . .
    
        
   /// text example

    // read some text

    //vector<string> words;
    //for (string temp; cin >> temp; ) // read whitespace-separated words
    //    words.push_back(temp); // put into vector
    //cout << "Number of words: " << words.size() << '\n';
    //sort(words); // sort the words
    //for (int i = 0; i < words.size(); ++i)
    //    if (i == 0 || words[i–1] != words[i]) // is this a new word?
    //        cout << words[i] << "\n";
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
