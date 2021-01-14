// Writing A ProgramD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../../std_lib_facilities.h"
//// Q2.

//class Token {
//public:
//    char kind;        // what kind of token
//    double value;     // for numbers: a value
//    Token(char ch)    // make a Token from a char
//        :kind(ch), value(0) { }
//    Token(char ch, double val)     // make a Token from a char and a double
//        :kind(ch), value(val) { }
//};
//
////------------------------------------------------------------------------------
//
//class Token_stream {
//public:
//    Token_stream();   // make a Token_stream that reads from cin
//    Token get();      // get a Token (get() is defined elsewhere)
//    void putback(Token t);    // put a Token back
//private:
//    bool full;        // is there a Token in the buffer?
//    Token buffer;     // here is where we keep a Token put back using putback()
//};
//
////------------------------------------------------------------------------------
//
//// The constructor just sets full to indicate that the buffer is empty:
//Token_stream::Token_stream()
//    :full(false), buffer(0)    // no Token in buffer
//{
//}
//
////------------------------------------------------------------------------------
//
//// The putback() member function puts its argument back into the Token_stream's buffer:
//void Token_stream::putback(Token t)
//{
//    if (full) error("putback() into a full buffer");
//    buffer = t;       // copy t to buffer
//    full = true;      // buffer is now full
//}
//
////------------------------------------------------------------------------------
//
//// Token get() // error(2)
//Token Token_stream::get()
//{
//    if (full) {       // do we already have a Token ready?
//        // remove token from buffer
//        full = false;
//        return buffer;
//    }
//
//    char ch;
//    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
//
//    switch (ch) {
//    case '=':    // for "print"
//    case 'x':    // for "quit"
//    case '{': case '}':case '(': case ')': case '!': case '+': case '-': case '*': case '/':
//        return Token(ch);        // let each character represent itself
//    case '.':
//    case '0': case '1': case '2': case '3': case '4':
//        // case '5': case '6': case '7': case '9': // logic error(1)
//    case '5': case '6': case '7': case '8': case '9':
//    {
//        cin.putback(ch);         // put digit back into the input stream
//        double val;
//        cin >> val;              // read a floating-point number
//        return Token('8', val);   // let '8' represent "a number"
//    }
//    default:
//        error("Bad token");
//    }
//}
//
////------------------------------------------------------------------------------
//
//Token_stream ts;        // provides get() and putback()
//
////------------------------------------------------------------------------------
//
//double expression();    // declaration so that primary() can call expression()
//double factorial(double d);
////------------------------------------------------------------------------------
//
//// deal with numbers , parentheses , curly braces {} , factorial !
//double primary()
//{
//    Token t = ts.get();
//    double d = 0;
//    switch (t.kind) {
//    
//    case '{':        // handle '{' '(' expression ')' '}'
//    {
//        d = expression();
//        t = ts.get();
//        if (t.kind != '}') error("'}' expected");
//        break;
//    }
//    
//    case '(':    // handle '(' expression ')'
//    {
//        d = expression();
//        t = ts.get();
//        // if (t.kind != ')') error("')' expected); // error(3)
//        if (t.kind != ')') error("')' expected");
//        break;
//    }
//
//    
//    case '8':            // we use '8' to represent a number
//       d= t.value;  
//       break;
//    default:
//        error("primary expected");
//    }
//
//
//    // check if next token is !
//
//    t = ts.get();
//    if (t.kind != '!') { // if not a ! put back the token and return d
//        ts.putback(t);
//        return d;
//    }
//    return factorial(d); // if ! return the factorial
//}
//
////------------------------------------------------------------------------------
//
//// deal with factorial !
//
//double factorial(double d) {
//
//    // factorial must be postive integer
//    // 0! is defined as 1
//    int t =d, fact = 1;
//
//    if (t != d)  error("factorial not possible for non integers");
//    else if (d < 0) error("factorial not possible for negative integers");
//    else if (d == 0) return fact;
//    else if (d > 31)error("factorial too large");
//    else { 
//        for (int  i = d; i>=1; --i)
//        {
//            fact = fact * i;
//        }
//        return fact;
//    }
//}
//
//
//// deal with *, /, and %
//double term()
//{
//    double left = primary();
//    Token t = ts.get();        // get the next token from token stream
//
//    while (true) {
//        switch (t.kind) {
//        case '*':
//            left *= primary();
//            t = ts.get();
//            // logic error(2)
//            break;
//        case '/':
//        {
//            double d = primary();
//            if (d == 0) error("divide by zero");
//            left /= d;
//            t = ts.get();
//            break;
//        }
//        default:
//            ts.putback(t);     // put t back into the token stream
//            return left;
//        }
//    }
//}
//
////------------------------------------------------------------------------------
//
//// deal with + and -
//double expression()
//{
//    // double left = term(;      // read and evaluate a Term // error(4)
//    double left = term();      // read and evaluate a Term
//    Token t = ts.get();        // get the next token from token stream
//
//    while (true) {
//        switch (t.kind) {
//        case '+':
//            left += term();    // evaluate Term and add
//            t = ts.get();
//            break;
//        case '-':
//            // left += term();    // evaluate Term and subtract // logic error(3)
//            left -= term();    // evaluate Term and subtract
//            t = ts.get();
//            break;
//        default:
//            ts.putback(t);     // put t back into the token stream
//            return left;       // finally: no more + or -: return the answer
//        }
//    }
//}
//
//
//
//void question_two(){
//    try
//    {
//        cout << "Welcome to our simple calculator.\n";
//        cout << "Please enter expressions using floating-point numbers.\n";
//        cout << "[+, -, *, /,!]operators, [x]quit, [=]print result, {()} allowed\n";
//        // error(5)
//        double val = 0;
//        while (cin) {
//            Token t = ts.get();
//
//            if (t.kind == 'x') break; // 'x' for quit
//            if (t.kind == '=')        // '=' for "print now"
//                cout << val << '\n';
//            else
//                ts.putback(t);
//            val = expression();
//        }
//        keep_window_open();
//    }
//    catch (exception& e) {
//        cerr << "error: " << e.what() << '\n';
//        keep_window_open();
//        return;
//    }
//    catch (...) {
//        cerr << "Oops: unknown exception!\n";
//        keep_window_open();
//        return;
//    }
//
//}
////------------------------------------------------------------------------------


//// Q4.

//class Name_value {
//
//public:
//	Name_value(string n, int s) : name(n), value(s) { }
//	string name;
//	int value;
//};
//vector<Name_value>Nv;
//
//void question_four() {
//    
//	try
//	{
//		string n; int v,count;
//
//		cout << "Enter the name value pairs,don't repeat the entry" << "\n";
//		cout<<"Enter Noname 0 to terminate"<<"\n";
//		while (cin >> n>>v && n!="Noname") {
//
//			count = 0;
//			for (int i = 0; i < Nv.size(); ++i) 
//				if (n == Nv[i].name) ++count;  // check for repeat
//
//			if (count == 0)
//				Nv.push_back(Name_value(n, v));
//			else cout << "repeated :" << n;
//			
//		}
//
//		for (int i = 0; i < Nv.size(); ++i)
//			cout << '(' << Nv[i].name << ',' << Nv[i].value << ")\n";
//		
//
//		keep_window_open();
//	}
//	catch (exception& e)
//	{
//		cerr << "error: " << e.what() << '\n';
//		       keep_window_open();
//		        return;
//
//	}
//	catch (...) {
//		       cerr << "Oops: unknown exception!\n";
//               keep_window_open();
//		        return;
//		    }
//
//}
/////----------------------------------------------------------------------------

//// Q6. 

//vector<string>sentence;
//vector<string>noun;
//vector<string>verb;
//vector<string>conj;
//int pos = 0;
//
//bool is_noun();
//
//void init_grammar() {
//    noun.push_back("Birds");
//    noun.push_back("C++");
//    noun.push_back("Fish");
//
//    verb.push_back("fly");
//    verb.push_back("rules");
//    verb.push_back("swim");
//
//    conj.push_back("and");
//    conj.push_back("but");
//    conj.push_back("or");
//   
//}
//
//bool is_conj(){
//    for (int i = 0; i < conj.size(); i++)
//        if (sentence[pos] == conj[i]) { pos++; return true; }
//    return false;
//}
//
//bool is_verb() {
//    for (int j = 0; j < verb.size(); j++)
//        if (sentence[pos] == verb[j]){ pos++; return true; }
//    return false;
//}
//
//bool is_noun() {
//    for (int i = 0; i < noun.size(); i++)
//        if (sentence[pos] == noun[i]) {pos++; return true;}
//    return false;
//}
//
//bool is_sentence() {
//    
//    // check if noun verb
//    if (!is_noun())return false;  
//    if (!is_verb())return false;  
//
//    // check if sentence conjunction sentence 
//    if (sentence[pos] == ".") return true; // end
//    else if (!is_conj()) return false; // not an end and not conjuction
//        return is_sentence();
//
//
//        
//    }
//
//void question_six() {
//    
//    
//    // Grammar used 
//
//    /*Sentence: Noun Verb                      e.g., C++ 
//             Sentence Conjunction Sentence      e.g., Birds fly but fish swim 
//
//    Conjunction: "and" 
//                 "or" 
//                 "but"
//
//        Noun: "birds" 
//              "fish" 
//               "C++" 
//
//    Verb: "rules" 
//          "fly" 
//          "swim"*/
//
//
//    try
//    {
//        cout << "enter the sentence(terminated by dot)" << "\n";
//        init_grammar();
//
//        string s, s1;
//        cin >> s;
//        sentence.push_back(s);
//
//        while (s1 != ".")  // a check whether a sentence is terminated by a dot
//        {
//            cin >> s1;
//            sentence.push_back(s1);
//
//            for (int i = 0;i < verb.size();++i) {
//                if (s1 == verb[i] + ".") {
//                    cout << "not ok " << "Try again!!" << "\n\n";     /// check wether a space is not before a dot
//                    sentence.clear();
//                    pos = 0;
//                    question_six();
//                }
//            }
//
//
//        }
//
//        bool b = is_sentence();
//        if (b) {
//            cout << "ok" << "\n \n";
//            sentence.clear();
//
//            char ans;
//            cout << "Exit?(Y or N)" << "\n";
//            cin >> ans;
//            
//            if (ans == 'Y' || ans == 'y') { cout << "Thankyou";  exit(0); }
//            else {
//                pos = 0;
//                sentence.clear(); question_six();
//            }
//        }
//        else {
//            cout << "not ok " << "Try again!!" << "\n \n";
//            sentence.clear();
//            pos = 0;
//            question_six();
//        }
//    }
//    catch (runtime_error e)
//    {
//        cout << e.what() << "\n";
//    }
//    
//}
//----------------------------------------------------------------------------


//// Q9.

//void question_nine() {
//   
//	try
//	{
//		int n, temp;;
//		cout << "How many digits? (Max allowed:4) \n";
//		cin >> n;
//		temp = n;
//		if (temp <= 4) {
//
//			while (temp) {
//				char c;
//				cin >> c;
//
//				switch (n)
//				{
//				case 4: cout << c << " Thousand ";--n; break;
//				case 3: cout << c << " Hundred ";--n; break;
//				case 2: cout << c << " Tens ";--n; break;
//				case 1: cout << c << " Ones";--n; break;
//				default:
//					break;
//				}
//				//number.push_back(c - '0');
//				--temp;
//			}
//		}
//		else cout << "Can't handle more than 4 digits";
//
//	}
//	catch (runtime_error e)
//	{
//		cout << e.what();
//	}
//}



int main()
{
   // question_two(); // Q2 Add the ability to use {} as well as () in the program
                   // Q3 Add a factorial operator: use a suffix ! operator to represent “factorial.”
    
    //question_four(); // take name, value pair as i/p ex Nishank 19 and add them to a vector of Name_value type
                      // check for uniqueness of name and terminate if entered twice or more

	//question_six(); /// Input a string through cin and push it into a vector and then check for a sentence
                      // according to the grammar

    //question_nine();/// Input charcaters and compose them into int for ex 123 into 123= 100+20+3 
                      // Output 1 hundred 2 tens 3 ones for 123
    
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
