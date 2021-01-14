//#include "../../../std_lib_facilities.h"
//
//// D2
//
////void swap_v(int a , int b) {
////	int temp;
////	temp = a;
////	a = b;
////	b = temp;
////}
////void swap_r(int& a, int& b) {
////	int temp;
////	temp = a;
////	a = b;
////	b = temp;
////}
//////void swap_cr(const int& a, const int& b){
//////	int temp;
//////	temp = a;
//////	a = b;
//////	b = temp;
//////}
////
////void D2() {
////	int x = 7;
////	int y = 9;
////	swap_v(x, y);
////	swap_v(7, 9);
////	//cout << x << y; // no swaping since x and y are not changed
////
////	/*const int cx = 7;
////	const int cy = 9;         function cant modify by a call by const ref
////	swap_cr(cx,cy);
////	swap_cr(7.7,9.9);*/
////
////	int dx = 7;
////	int dy = 9.;
////	swap_r(dx, dy);
////	cout << dx << dy;
////	//swap_r(7,9); // for call by non const reference actual arguments must be lvalue
////}
//
//// D3
//
////namespace X {
////	int var;
////	void print() { cout << var<<"\n"; }
////}
////namespace Y {
////	int var;
////	void print() { cout << var << "\n"; }
////}
////namespace Z {
////	int var;
////	void print() { cout << var << "\n"; }
////}
////void D3(){
////	X::var = 7; // full qualified name
////	X::print(); // print X’s var
////
////	using namespace Y;  // using using directive
////	var = 9;
////	print(); // print Y’s var 
////
////	{
////		using Z::var; // using using declaration
////		using Z::print;
////		var = 11;
////		print(); // print Z’s var
////	}
////}
//
//// E2
//
////void print(vector<int>&v, const string& label) {
////
////	for (int x : v) { cout << label << x << "\n"; }
////	
////}
////void E2(){
////	vector<int>v;
////	for (int x;cin >> x;)
////		v.push_back(x);    // non int type terminates the loop
////
////	print(v, "Day");
////}
//
//// E3
//
////void fibonacci(int x, int y, vector<int>&f, int n) {
////	f.push_back(x);
////	f.push_back(y);
////	int z = 0;
////	for (int i=0; i < n - 2;++i) {
////		z = x + y;
////		f.push_back(z);
////		x = y;
////		y = z;
////	}
////}
////void E3() {
////	vector<int>v;
////	int x=0, y=0, n=0;
////	cout << "Enter the first 2 elements and number of elements :";
////	cin >> x >> y >> n;
////	fibonacci(x, y, v, n);
////	print(v, " ");
////}
//
////E7
//
////void E7() {
////
////	// There are three different logical blocks reading,sorting,writing 
////	// which can be made into different fucntions
////	
////	// reading pairs
////	cout << "Enter name and age , ! to terminate\n";
////	vector<string>name;
////	vector<int>age;
////	string s; int n;
////	while (cin >> s && s != "!" && cin>>n)
////	{
////		name.push_back(s);
////		age.push_back(n);
////	}
////
////	// sorting the pairs
////	vector<string>name1 = name; // cpoying name and age vector
////	vector<int>age1 = age;
////
////	// sorting names
////	sort(name.begin(), name.end());
////
////	// sorting age according to respective names
////	for (int i = 0;i < name.size();++i)
////		for (int j = 0;j < name1.size();++j) {
////			string s;
////			s = name[i];
////			if (s == name1[j]) age[i] = age1[j];
////		}
////
////	// writing the pairs after sort
////	cout << "After sorting" << "\n";
////	for (int i = 0;i < name.size();++i)
////		cout << name[i] << "," << age[i] << "\n";
////}
//
//// E11
//
////struct Stats
////{
////	int lrg=0;
////	int sml=0;
////	double median=0.0;
////	double mean= 0.0;
////};
////Stats vector_stat(vector<int>& v , Stats& s) {
////    
////	int n= v.size();
////
////	// sorted the vector
////	sort(v.begin(), v.end());
////	s.sml = v[0]; // smallest value
////	s.lrg = v[n - 1]; //largest value
////
////	if (n % 2 == 0) s.median = (double(v[n / 2]) + double(v[n / 2 - 1])) / 2; // if n is even 
////	else s.median = v[n / 2];  // if n is odd
////
////	// mean is sum of elements by number of elements
////	double sum = 0.0;
////	for (int x : v) sum = sum + x;
////	s.mean= sum/ n;
////
////	return s; // returning Stats
////}
////void E11() {
////	Stats s;
////	vector<int>v = { 2,3,1,4,5,5,7,2,8,10 };
////	vector_stat(v, s);
////	cout << s.sml << s.lrg << s.median << s.mean;
////}
//
////E12
//
////void print_untill_s(vector<string>& v, const string& quit) {
////	for (string s : v) {
////		if (s == quit) return;
////		cout << s << "\n";
////	}
////}
////void E12() {
////	vector<string>v;
////	string s1;
////	string s = "quit";
////	while (v.size() < 5) { cin >> s1; v.push_back(s1); }
////	print_untill_s(v, s);
////}
//
////E13
//
//int char_count(string s1) {
//	int count = 0;
//	for (char c : s1) 
//		count++;
//	
//	return count;
//}
//vector<int> vect_prop(vector<string>& s) {
//
//	vector<int>count;
//
//	// counting the charcaters of the each string
//	for (string s1 : s) {
//		count.push_back(char_count(s1));
//	}
//
//	// finding the smallest and largest
//	vector<int> count1 = count; // copy of count
//    sort(count1.begin(), count1.end()); // sort the count1
//	string sml_s, lrg_s;
//	    
//	    // search for the string having highest and lowest count
//		for (int j = 0; j < s.size();++j) {
//			int sml = count1[0];
//			int lrg = count1[count.size() - 1];
//				if (sml == count[j]) sml_s = s[j];
//				if (lrg == count[j]) lrg_s = s[j];
//		}
//	 cout << "smallest string :"<<sml_s <<" largest string :"<< lrg_s<<"\n";
//
//	 // lexicographically first and last strings
//		sort(s.begin(), s.end()); // sort the strings a to d
//		cout << "lexicographically "<<"first string :" << s[0] << " last string :" << s[s.size()-1];
//
//	return count; // return the character count vector
//}
//void E13() {
//	vector<string>s;
//	cout << "Enter strings,only lowercase , ! to terminate";
//	string s1;
//	while (cin >> s1 && s1 != "!") s.push_back(s1);
//
//	vector<int> c_count = vect_prop(s);
//	//for (int x : i) cout << x;
//}
//
//
//int main() 
//try
//{
//	//	D2();  //Drills 2
//   //   D3(); // Drills 3
//   //   E2(); // Exercises 2
//   //   E3();
//   //   E7();
//   //   E11();
//   //   E12();
//   //   E13();
//}
//	
//catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
//	cout << e.what() << '\n';
//	keep_window_open("~");
//}
//catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
//	cout << "exiting\n";
//	keep_window_open("~");	
//}
