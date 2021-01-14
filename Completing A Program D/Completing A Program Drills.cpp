// Completing A Program D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//  Grammar used

//Calculation:
//    Statement 
//	  Print
//	  Quit
//    Help
//	  Calculation Statement 
//
//Statement : 
//      Declaration 
//	    Expression 
//      Expression Statement
//
//Declaration : 
//     "let" Name '=' Expression
//     "const" Name '=' Expression
//
//Expression : 
//       Term
//       Expression + Term
//	     Expression - Term
//
//Term :
//	   Primary
//	   Term * Primary
//	   Term / Primary
//	   Term % Primary
//
//Primary :
//	   Number
//	   Number !
//     Name
//	  '{' ('Expression')' '}'
//     sqrt'(' Expression ')'
//     power'(' Base, Exponent ')'
//
//Number :
//		  Floating Point literal
//Name : 
//      Alphabets
//      AlphabetsDigits
//      Alphabets'_'Digits
//
// Base :
//      Expression

//   Exponent :
//           Integer 

#include "../../../std_lib_facilities.h"
class Variable {

public:
	string name; // name for the variable or a constant
	double value;// value of the variable
	bool is_const;// a variable is constant or not E3

	Variable(string n, double v, bool isc) :name{ n }, value{ v }, is_const{isc}  { } // make a Variable with name n and value v
};

vector<Variable>var_table;

class Token {

public:
	char kind;    // what kind of token
	double value; // for numbers: a value
	string name;  // for name: a string
	Token(char ch) :kind(ch) { }           // make a token with kind operator and kind itself be the value
	Token(char ch, double val) :kind(ch), value(val) { } // make a token with kind number and double value
	Token(char ch, string n) : kind(ch), name(n) {}    // make a token with kind name and string value
};

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
	void ignore(char c);
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream() :full(false), buffer(0) {}   // no Token in buffer 


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

void help() {

	cout << "Enter expressions using floating-point numbers ex 5+3*2; \n";
	cout << "We can handle variables ex let x=3+2 and can assign them too ex x=9; \n";
	cout << "To define a constant use const ex const x=5; \n";
	cout << "[q]quit, [;]print result \n";
	cout << "[+, -, *, /, !, %]operators, [ sqrt(value), pow(base,exponent)  ]functions,  {()} allowed\n";
}


const char underscore = '_'; //E1
const char let = 'l';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char Sqrt = 's';
const char Power = 'p';
const char Const = 'c';
const char Help = 'h';
const string declkey = "let";
const string sqrtkey = "sqrt";
const string powerkey = "pow";
const string Constkey = "const";

// gets the token from the token stream
Token Token_stream::get()
{
	if (full)// do we have a token ready
	{
    // remove the token from the buffer
		full = false; 
		return buffer; 
	}
	char ch;
	cin >> ch;   // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {

	case Help:
	case 'H': 
	case '(':
	case ')':
	case '}':
	case '{':
	case '!':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
	case quit:
		return Token(ch);  // let the character represents itself

	case '.':  // a floating point literal can start with a .
	case '0':
	case '1':
	case '2':
	case '3':   // floating point literals
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	           {	
	             cin.putback(ch); // put the digit back into input stream
	             double val;
	             cin >> val;  // read the value
	             return Token(number, val);
	           }

	default:
		if (isalpha(ch)) {  // check for an alphabet
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) ||ch==underscore|| isdigit(ch))) s += ch;  // check for whether name satisfies grammar
			cin.putback(ch);
			if (s == declkey) return Token(let);  
			if (s == sqrtkey) return Token(Sqrt); // returns kind square root or 's'
			if (s == powerkey)  return Token(Power); // returns kind power or 'p'
			if (s == Constkey) return Token(Const); // returns kind const or 'c' E3
			return Token(name, s);
		}
		else
		cout << ch;  // print the bad token
		error(" is Bad token");
	}
}


void Token_stream::ignore(char c)
// c represents the kind of Token 
{
	// first look in buffer: 
	if (full || c == buffer.kind) { full = false; return; }
    full = false;
	
	// now search input:
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

// returns tha value given the name of Variable
double get_value(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error(" get:undefined name ", s);
}

//sets value for given name of Variable 
void set_value(string s, double d)
{
	for (int i = 0; i <= var_table.size(); ++i)
		if (var_table[i].name == s) {
			if (var_table[i].is_const) error("const value can't be changed"); // check for a const name E3
			var_table[i].value = d;
			return;
		}
	error("set:undefined name ", s);
}

bool is_declared(string s)
{
	// check whether the Variable is already declared
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();    // declaration so that primary() can call expression()
double factorial(double d);
double power(double base, int exp);
//------------------------------------------------------------------------------

// deal with numbers , parentheses , curly braces {} , factorial ! , sqrt(), pow()
double primary()
{
	Token t = ts.get();
	double d = 0;
	switch (t.kind) {

	case '{':        // handle '{' '(' expression ')' '}'
	{
		d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		break;
	}

	case '(':    // handle '(' expression ')'
	{
		d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		break;
	}

	case number:
		d = t.value; // return number itself
		break;

	case name: 
	{
		//E2
		if (!is_declared(t.name)) error(t.name, " variable not declared");  // check for no declrations
        Token next = ts.get();// get the next token
		if (next.kind == '=') {	// handle name = expression
			d = expression();
			set_value(t.name, d);
			
		}
		else {
			ts.putback(next);		// not an assignment: return the value
			d= get_value(t.name); // return the variable's value
		}
		break;
	}		

	case '-':
		return -primary();  // for ex -2
		break;

	case '+':
		return  primary();  // for ex +3
		break;

	case Sqrt:  // sqrt'(' Expression ')'
	{  //D7
		t = ts.get();
		if (t.kind != '(') error("'(' expected"); // check for opening parenrhesis
		double value=expression();// calulate the expression D8
		if (value < 0)error("square root not possible for negative");
		d = sqrt(value);
		t = ts.get();
		if (t.kind != ')') error("')' expected"); // check for closing parenthesis
		break;
	}

	case Power:  	//power'(' Base, Exponent ')
	{ //D9
		t = ts.get();
		if (t.kind != '(') error("'(' expected"); // check for opening parenrhesis
		double base = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected"); // check for comma
		t = ts.get();
		if (t.kind != number)error("exponent is not a number");
		if (t.value != int(t.value)) error("expected a integer exponent");
		double exp = t.value;		
		t = ts.get();
		if (t.kind != ')') error("')' expected"); // check for closing parenthesis
		d = power(base, exp);
		break;
	}

	default:
		error("primary expected");
	}
	 
	

	// check if next token is !

	t = ts.get();
	if (t.kind != '!') { // if not a ! put back the token and return d
		ts.putback(t);
		return d;
	}
	return factorial(d); // if ! return the factorial
}

// deal with pow()

double power(double base, int exp) {
	double temp = 1.0;
	for (int i = 0; i < exp; i++) 
		temp *= base;
	return temp;
}

// deal with factorial !

double factorial(double d) {

	// factorial must be postive integer
	// 0! is defined as 1
	int t = d, fact = 1;

	if (t != d)  error("factorial not possible for non integers");
	else if (d < 0) error("factorial not possible for negative integers");
	else if (d == 0) return fact;
	else if (d > 31)error("factorial too large");
	else {
		for (int i = d; i >= 1; --i)
		{
			fact = fact * i;
		}
		return fact;
	}
}


// deal with *, /, and %
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			// logic error(2)
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		
		case '%':
		{
			double d = primary();
			if (d == 0) error("divide by zero");         
			left = fmod(left, d); // fmod is used for floating point literals
			t = ts.get();
			break;
		}

		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	// double left = term(;      // read and evaluate a Term // error(4)
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			// left += term();    // evaluate Term and subtract // logic error(3)
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//E3
void define_name(string s, double val, bool is_const)
// add (s,val,is_const) to var_table
{
	if (is_declared(s)) error(s, " declared twice");
	var_table.push_back(Variable(s, val, is_const));
	
}


double declaration(Token t)
{
	
		// handle variablename = expression or constname = expression
		Token t1 = ts.get();
		if (t1.kind != name) error("name expected in declaration"); // check for name after seeing let
		string name = t1.name;

		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name); // check for '=' 
		
		double d = expression();
		define_name(name, d, t.kind == Const);
		return d;
	}




double statement()
{
	// handle expression, declration and assignment 
	Token t = ts.get();
	switch (t.kind) {
	case let:
	case Const: 
		return declaration(t);

	default: 
		
		ts.putback(t);
		return expression();
	}
}

void clean_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate(){

	double val = 0;
	while (cin)
	try
	{
	cout<<"\n" << prompt; Token t = ts.get();  // prompts user for an input
	while (t.kind == print) t = ts.get(); // eat ‘=’ so that q gets checked for ex 2+3;q
    if (t.kind == quit){keep_window_open("~~"); return;}
	if (t.kind == Help) help();
	else {
		ts.putback(t);
		cout << result << statement() << "\n";
	}
	}

    catch (exception& e){
	cerr << e.what() << "\n";
	clean_mess();
	}
}


int main()
try
{
	cout << "Welcome to our simple calculator.\n";
	cout << "Press h or H for  help. \n";
	define_name("k", 100,true);

	calculate();
	//keep_window_open();
	return 0;


}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~"); /// updated error handling
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open("~~");
	return 2;
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
