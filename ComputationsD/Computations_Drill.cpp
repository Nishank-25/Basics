// ComputationsD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
//double conversion(double val, string unit);


/// conversion function

//double conversion(double val1, string unit1) {
//    if (unit1 == "cm") {
//        return val1 / 100;
//    }
//    if (unit1 == "in") {
//        return val1 / 39.37;
//    }
//    if (unit1 == "ft") {
//        return val1 / 3.28;
//    }
//    if (unit1 == "m") {
//        return val1 / 1.0;
//    }
//
//}


//8. 
double power(int square_pos) {
    double grain = 1.0;

    for (int i = 1;i < square_pos;++i)
    {
        grain *= 2;
    }
    return grain;
}
int main()
{
    /// Computations Drill

    // 
    //double a=0.0, b=0.0;
    /*while (cin >> a >> b)
    {
        if (a == b)cout << "Numbers are equal";
        else if(a<b){
            cout << "Smaller value is :" << a;
            cout << "larger value is :" << b;
            if (b - a <= (1.0/100))cout << "They are almost equal";
        }
        
        else {
            cout << "Smaller value is :" << b;
            cout << "larger value is :" << a;
            if (a- b <= 0.01)cout << "They are almost equal";

        } 
    }*/
    
    /*bool once = true;
    double a = 0.0, s = 0.0,l = 0.0;
    while (cin >> a) {

        if (once) {
            l = a;
            s = a;
           ;once = false;
        }
          if (a < s) {
            s = a;
            cout << a << " is smallest number so far";
        }
          else if (a > l) {
            l = a;
            cout << a << " is largest number so far";
        }
        

    }*/

    
    /*double val{ 0.0 }, cval = {0.0},large = 0.0, small = 0.0, sum = 0.0;
    int n = 0;
    vector<double> length;
    bool once = true;
    string unit = " ";
    while (cin >> val >> unit) {
       
        if (unit == "cm" || unit== "m" || unit== "in" || unit=="ft") {
            ++n;

           cval=conversion(val, unit);
           length.push_back(cval);
           sum += cval;
           if (once) {
               large = cval;
               small = cval;
               once = false;
           }
           if (cval < small) {
               small = cval;
           }
           else if (cval > large) {
               large = cval;
               
           }
        }
        else cout << "Invalid units";


    }
    
   cout << "program was terminated \n ";
   cout << "Number of values" << n << "\n";
   sort(length.begin(), length.end());
   cout << "All the values are: ";
       for (double x : length)
           cout << x<<"m"<<" " ;
   cout << "\n Sum of all the values are: " << sum<<"\n";
   cout << "Largest value: " << large<<"\n";
   cout << "Smallest value : " << small;*/


    /// Exercises

      // 6.  
  /*  vector<string>number = { "zero","one","two","three","four",
                             "five","six", "seven", "eight", "nine" };
    int digit;

    cout << "Enter the digit ";
    cin >> digit;

    cout << number[digit];

    string word;
    cout << "\n Enter the spelled word ";
    cin >> word;
    
    for (int i = 0;i < number.size();++i) {
        if (number[i] == word) {
            cout << i;
        }
    }*/



   // 7.

   //vector<string>game[9];
   //cout << "Lets play Rock Paper Scissors";
   //
   //cout << "Enter the rock paper scissors randomly";
   //
   //for (string value;cin >> value;) {
   //    game->push_back(value);
   //}

  // 8 & 9.  

     /*double square_pos,grain_sum=0.0,n_grain=1.0,n;
     bool x = true;
     cout << "Enter the number of grains";
     cin >> n;
     cout<<sizeof(double);
     for (int i = 1; i<x i++)
     {
         square_pos = i;
         cout << square_pos << "is the square position \n";
         n_grain = power(square_pos);
         cout << n_grain << " grains on the current square\n";
         grain_sum += n_grain;
         cout << grain_sum << ": sum \n\n";

         if (grain_sum >= n) { 
             cout << "You will need atleast " << square_pos << " squares for" << n << " grains";
             x = false;
         }
     }
     
     int can handle upto 31 squares double can handle upto 1023 squares
     
     */

     //16.

          /*bool once = true;
          int count = 1,mode=1,pos=1,nc=0;
          vector<int>n;
          int a = 0, s = 0, l = 0;
          while (cin >> a) {
              ++nc;
              n.push_back(a);
              if (once) {
                  l = a;
                  s = a;
                  once = false;
              }
              if (a < s) {
                  s = a;
                  cout << a << " is smallest number so far\n";
              }
              else if (a > l) {
                  l = a;
                  cout << a << " is largest number so far\n";
              }
          }

          cout << "Program is terminated\n";
          
            sort(n.begin(), n.end());
            for (int i = 0;i < nc-1;i++) {

              if (n[i + 1] == n[i]) {
                  ++count;

              }
              else {
                  if (count > mode) {
                      mode = count;
                      count = 1;
                      pos = i;
                  }

              }
            }

            printf("The mode of the series is %d repeated %d times", n[pos], mode);
  */
       return 0;
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
