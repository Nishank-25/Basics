// Completing A Program D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//  Grammar used

//Calculation:
//    Statement 
//	  Print
//	  Quit
//	  Calculation
//	  Statement 
//
//Statement : 
//      Declaration 
//	  Expression 
//
//Declaration : 
//     "let" Name "=" Expression
//
//Expression : 
//       Term
//       Expression + Term
//	   Expression - Term
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
//	  '{' ('Expression')' '}'
//
//Number :
//		  Floating Point literal


#include "../../../std_lib_facilities.h"

class Variable {
public:
	string name; // name for the variable 
	double value;// value of the variable
	Variable(string n, double v) :name(n), value(v) { } // make a variable with name n and value v
};
vector<Variable>var_table;

class Token {

public:
	char kind;    // what kind of token
	double value; // for numbers: a value
	string name;  // for name: a string
	Token(char ch) :kind(ch) { }           // make a token with kind operator
	Token(char ch, double val) :kind(ch), value(val) { } // make a token with kind number and double
	Token(char ch, string n) : kind(ch), name(n) {}    // make a token with kind name and string
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

const char let = 'l';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const string declkey = "let";

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
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;  // check for whether only digit succeeds alphabet
			cin.putback(ch);
			if (s == declkey) return Token(let);
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

double get_value(string s)
{
	// returns tha value given the name of Variable
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	//sets value for given name of Variable 
	for (int i = 0; i <= var_table.size(); ++i)
		if (var_table[i].name == s) {
			var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
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
//------------------------------------------------------------------------------

// deal with numbers , parentheses , curly braces {} , factorial !
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
		// if (t.kind != ')') error("')' expected); // error(3)
		if (t.kind != ')') error("')' expected");
		break;
	}


	case number:
		d = t.value;
		break;

	case name: return get_value(t.name);
		break;

	case '-':
		return -primary();  // for ex -2+3
		break;

	case '+':
		return  primary();  // for ex +3+2
		break;

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

//------------------------------------------------------------------------------

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

double declaration()
{
	// handle name = expression
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration"); // check for name after seeing let
	string name = t.name;

	if (is_declared(name)) error(name, " declared twice");  // check for multiple declrations
	Token t2 = ts.get();

	if (t2.kind != '=') error("= missing in declaration of ", name); // check for '=' 
	double d = expression();
	var_table.push_back(Variable(name, d));
	return d;
}

double statement()
{
	// handle expression and declration
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
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

void calculate() {

	double val = 0;
	while (cin)
		try
	{
		cout << prompt; Token t = ts.get();  // prompts user for an input
		while (t.kind == print) t = ts.get(); // eat ‘=’ so that x gets checked for ex 2+3=x
		if (t.kind == quit) { keep_window_open(); return; }
		ts.putback(t);
		cout << result << statement() << "\n";
	}

	catch (exception& e) {
		cerr << e.what() << "\n";
		clean_mess();
	}
}

int main()
try
{
	cout << "Welcome to our simple calculator.\n";
	cout << "Please enter expressions using floating-point numbers.\n";
	cout << "We can handle variables ex let x=3+2; \n";
	cout << "[+, -, *, /, !, %]operators, [q]quit, [;]print result, {()} allowed\n";

	calculate();
	keep_window_open();
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
