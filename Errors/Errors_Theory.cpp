// Errors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>


using namespace std;
int area(int length, int width);

class Bad_area { }; // a type specifically for reporting errors from area()


// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument

int area(int length, int width)
{
    if (length <= 0 || width <= 0) throw Bad_area{};
    return length * width;
}


int framed_area(int x, int y) // calculate area within frame
{
    return area(x-2, y-2);
}

int main()
{
    
    /// Compile-time errors

     // Syntax Errors

    //int s1 = area(7; // error: ) missing
    //int s2 = area(7) // error: ; missing
    //Int s3 = area(7); // error: Int is not a type
    //int s4 = area('7);  // error: non-terminated character ( ' missing)

    // Type Errors
    
    //char c{ 'y' };
    //int x0 = arena(7); // error: undeclared function
    //int x1 = area(7); // error: wrong number of arguments
    //int x2 = area("seven", 2); // error: 1st argument has a wrong type
    //int x3 = area(c, 2); // though logically wrong compiler accepts 

    // Non errors

    //int x4 = area(10,-7); // OK: but what is a rectangle with a width of minus 7?
    //int x5 = area(10.7, 9.3); // OK: but calls area(10,9)
    //char x6 = area(100, 9999); // OK: but truncates the result

    /// Link Time errors


    /// Run Timer Errors

    /// Exceptions
      
    // Bad arguments
   
    //try {
    //    int x = -1;
    //    int y = 2;
    //    int z = 4;
    //    // . . .
    //    int area1 = area(x, y);
    //    int area2 = framed_area(1, z);
    //    int area3 = framed_area(y, z);
    //    double ratio = area1 / area3;
    //}
    //catch (Bad_area) {
    //    cerr << "Oops! bad arguments to area()\n";
    //   
    //}

    

    // Range Error or off-by-one or bounds error

    //try {
    //    vector<int>v; // a vector of ints
    //    for (int x; cin >> x; )
    //        v.push_back(x); // set values
    //    for (int i = 0; i <= v.size(); ++i) // print values
    //        cout << "v[" << i << "] == " << v[i] << '\n';
    //}
    //catch (out_of_range) {
    //    cerr << "Oops! Range error\n";
    //    return 1;
    //}
    //catch (...) { // catch all other exceptions
    //    cerr << "Exception: something went wrong\n";
    //    return 2;
    //}

    // Bad input


    //double some_function()
    //{
    //    double d = 0;
    //    cin >> d;
    //    if (!cin) error("couldn't read a double in 'some_function()'");
    //    // do something useful
    //}
    //try {
    //    // . . . our program . . .
    //    return 0; // 0 indicates success
    //}
    //catch (runtime_error& e) {
    //    cerr << "runtime error: " << e.what() << '\n';
    //    keep_window_open();
    //    return 1; // 1 indicates failure
    //}
    //void error(string s)
    //{
    //    throw runtime_error(s);
    //}
    //void error(string s1, string s2)
    //{
    //    throw runtime_error(s1 + s2);  /// if want 2 pieces of info to describe the error
    //}

    // Narrowing Error


    //int x1 = narrow_cast<int>(2.9); // throws
    //int x2 = narrow_cast<int>(2.0); // OK
    //char c1 = narrow_cast<char>(1066); // throws
    //char c2 = narrow_cast<char>(85); // OK



    /*The < . . . > brackets are the same as are used for vector<int>.They are used
        when we need to specify a type, rather than a value, to express an idea.They are
        called template arguments.We can use narrow_cast when we need to convert a value
        and we are not sure “if it will fit”; it is defined in std_lib_facilities.hand implemented
        using error().*/



    /// Logical Errors
      //vector<double> temps; // temperatures
        //for (double temp; cin >> temp; ) // read and put into temps
        //    temps.push_back(temp);
        //double sum = 0;
        //double high_temp = 0;
        //double low_temp = 0;
        //for (int x : temps)
        //{
        //    if (x > high_temp) high_temp = x; // find high
        //    if (x < low_temp) low_temp = x; // find low
        //    sum += x; // compute sum
        //}
        //cout << "High temperature: " << high_temp << '\n';
        //cout << "Low temperature: " << low_temp << '\n';
        //cout << "Average temperature: " << sum / temps.size() << '\n';

       /*Instead of this we can use the highest and lowest alogorithm used is 
            computation exercise*/

 

   
        
    /// Pre Conditions

    //   int my_complicated_function(int a, int b, int c)
    //  // the arguments are positive and a < b < c
    // {
    //if (!(0 < a && a < b && b < c)) // ! means “not” and && means “and”
    //    error("bad arguments for mcf");
    //// . . .
    // } 












   
         /// Post conditions     
         //int area(int length, int width)
//// calculate area of a rectangle;
//// pre-conditions: length and width are positive
//// post-condition: returns a positive value that is the area
//{
//    if (length <= 0 || width <= 0) error("area() pre-condition");
//    int a = length * width;
//    if (a <= 0) error("area() post-condition");
//    return a;
//}



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
