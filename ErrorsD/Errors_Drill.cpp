#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;


 

	 /// Drills

	// try {
	 //Cout << "Success!\n";                   
	//	 //cout << "Success!\n";

	//	 //cout << "Success!\n;                   
	//	 //cout << "Success!\n";
   //	 //cout << "Success" << !\n"               
	//	 //cout << "Success" << "!\n";
	//	 //cout << success << '\n';
	//	 //cout << "success" << "\n";
	//	 //string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
	//	 //string res = "7";vector<string> v(10);v[5] = res; cout << "Success!\n";
	 	//vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Success!\n";
	//	 //vector<int>v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
	//	 //if (cond) cout << "Success!\n"; else cout << "Fail!\n";
	//	 //bool cond = true;
	//	 //if (cond) cout << "Success!\n"; else cout << "Fail!\n";
	//	//bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
	//	//bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
	//	//string s = "ape"; boo c = "fool" < s; if (c) cout << "Success!\n";
	//	// string s = "ape"; bool c = "fool" > s; if (c)cout << "Success!\n";
	//	//string s = "ape"; if (s == "fool") cout << "Success!\n";
	//	//string s = "ape";if (s != "fool") cout << "Success!\n";
	//	//string s = "ape"; if (s == "fool") cout < "Success!\n";
	//	//string s = "ape"; if (s != "fool") cout << "Success!\n";
	//	//string s = "ape"; if (s + "fool") cout < "Success!\n";
	//	//string s = "ape"; if (s != "fool") cout << "Success!\n";
	//	//vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n";
	//	// vector<char> v(5); for (int i = 0;i <= v.size();++i) cout << "Success!\n";
	//	//vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
	//	//vector<char> v(5); for (int i = 0; i <= v.size(); ++i) cout << "Success!\n";
	//	//string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];
	//	//string s = "Success!\n"; for (int i = 0; i <= 7; ++i) cout << s[i];
	//	//if (true) then cout << "Success!\n"; else cout << "Fail!\n";
	//	//if (true) cout << "Success!\n"; else cout << "Fail!\n";
	//	//int x = 2000; char c = x; if (c == 2000) cout << "Success!\n";
	//	 //int x = 2000;int c = x;if (c == 2000) cout << "Success!\n";
	//	// string s = "Success!\n"; for (int i = 0; i < 7; ++i) cout << s[i];
	//	//vector v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
	//	//vector<int> v(5); for (int i = 0; i <= v.size(); ++i) cout << "Success!\n";
	//	//int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";
	//	//int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";
	//	//int x = 2; double d = 5 / (x-2); if (d == 2 * x + 0.5) cout << "Success!\n";
	//	//int x = 2; double d = 2 * x + 0.5; if (d == 2 * x + 0.5) cout << "Success!\n";
	//	//string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i];
	//	 //string s = "Success!\n";for (int i = 0;i < 10;++i) cout << s[i]; since size of string is 9
	//	//int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n";
	//	//int x = 4; double d = 5 / (x–2); if (d = 2 * x + 0.5) cout << "Success!\n";
	//cin << "Success!\n";

	//	return 0;
	//}
	//catch (exception& e) {
	//	cerr << "error: " << e.what() << "\n";

	//	return 1;
	//}
	//catch (...) {
	//	cerr << "Oops: unknown exception!\n";

	//	return 2;
	//}


	 /// Exercises 

	 // Q2. to Q5. 
      
       constexpr double C = -273.15;
     double ctok(double c) // converts Celsius to Kelvin
	 {
		 if (c < C) {
			 cerr << "Wrong input... Enter again \n";
			 cin >> c;
			 ctok(c);
		 }
		 else{
			 double k = { c + 273.15 };

			 return k;
			 
		 }
		 
	 }
	
		 int main() {
			 
			 double c = 0; // declare input variable
		   cin >> c;
		   //Q3.
		   /*while (true) {
			   if (c < C) {
				   cerr << "Not possible... Enter again \n";
				   cin >> c;
			   }
			   else break;
		   }*/  
		   double k = ctok(c); // convert temperature
		   cout << k; // print out temperature
	     }

     // Q7

   //     void root_finder(float a,float b, float c){
			//
			//float x1, x2;
			//
			//// Checking for not real roots
			//if ((b*b)-(4*a*c)<0)
			//{
			//	cout << "No real roots possible... Enter the values again \n";
			//	cin >> a >> b >> c;
			//	root_finder(a, b, c);
			//}
			//else {
			//	x1 = (-b + sqrt((b * b) - (4 * a * c)))/2*a;
			//	x2 = (-b - sqrt((b * b) - (4 * a * c))) / 2 * a;
			//	cout << "the roots are " << x1 << ", " << x2;
			//}
           // }
   //  int main() {
          //float a, b, c;
		 //vector<float> root;
		 //cout << "Enter the coefficents a b c of quadratic equation \n";
		 //cin >> a >> b >> c;
		 //root_finder(a, b, c);
	  //}


   // Q12

//vector<int>Ans(4);
//vector<int>guess(4);
//
//int check_bull(vector<int>guess) {
//	int bull_count = 0;
//
//	for (int i = 0;i < 4;i++) {
//		if (guess[i] == Ans[i]) {
//			++bull_count;
//		}
//	}
//	return bull_count;
//	
//
//	  }
//
// 
//int check_cow(vector<int>guess) {
//	int cow_count = 0; int i = 0;
//	
//	while(i<4){
//		
//		for (int j = 0;j < 4;j++) {
//			if (guess[i] == Ans[j] && (j != i)) ++cow_count;
//		}
//		++i;
//	}
//	
//	return cow_count;
//	
//
//}
//
//// Check for repetition
//
//void check_repeat(int j) {
//	
//	for (int i = 0;i<j;i++) {
//		if (guess[i] == guess[j])
//		{
//			cout << "Repeated digit not allowed. Enter again\n";
//			cin >> guess[j];
//			check_repeat(j);
//		}
//	}
//}
//
//void start() {
//	
//	bool answer = true;
//	int result[2];
//
//	while (answer) {
//		cout << "Enter your guess, digit by digit. Dont repeat the digit\n";
//
//
//		for (int i = 0;i < 4;i++) {
//			cin >> guess[i];
//			check_repeat(i);
//
//		}
//		cout << "\n" << "Your Guess: ";
//		for (int i = 0;i < 4;i++) {
//			cout << guess[i];
//		}
//		cout << "\n";
//
//		result[0] = check_bull(guess);
//		result[1] = check_cow(guess);
//
//		cout << "My answer: ";
//
//		if (result[0] == 4) {
//			answer = false;
//			cout << result[0] << "bulls";
//		}
//		else cout << result[0] << " bull and " << result[1] << " cow" << "\n\n\n";
//
//	}
//}
//bool check_unique(int num){
//
//	int temp[4],i=3,check=0;
//
//	while (num!=0)
//	{
//		temp[i] = num % 10;
//		num = num / 10;
//		--i;
//
//	}
//
//	for (int i = 1;i<=3;i++) {
//
//		for (int j = 0;j < i;j++) {
//          if (temp[j] == temp[i]) ++check; 
//
//			}
//	}
//
//	if (check == 0) return false;
//	else return true;
//
//}
//
//void Ans_gen() {
//	int gen_num,seed;
//	bool repeat = true;
//
//	cout << "Give me a number u like upto 3 digits";
//	cin >> seed;
//
//	for()
//
//	if(gen_num > 999){}
//
//	if(gen_num < 10000){}
//
//	if(repeat)
//	repeat=check_unique(gen_num);
//
//}
//     
//          int main() {
//
//			  
//			  cout << "Lets play bulls and cows\n\n";
//			  Ans_gen();
//			  start();
//			  
//			  
//       }






