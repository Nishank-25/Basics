
#include"../../../std_lib_facilities.h"


class Token {           //Token class
public: char kind;
      double value;
      Token(char ch) : kind(ch), value(0) {}
      Token(char ch, double val) : kind(ch), value(val) {}
};
class Token_stream {    //Token_stream class
public: 
     Token_stream();
      Token get();
      void putback(Token t);
private:bool full{ false };
       Token buffer;
};
// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}
Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch) {
    case ';': case 'q': case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': return Token{ ch };
    case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{ '8', val };
    }
    default:error("Bad token");
    }
}


void Token_stream::putback(Token t) { 
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}
Token_stream ts;
double expression();
double primary() {          //primary
    Token t = ts.get();
    switch (t.kind) {
    case '(': {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
        break;
    }
    case '{': {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
        break;
    }
    case '8': return t.value;
    default:  error("primary expected");
    }
}
double term() {         //term
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '*': left *= primary();
            t = ts.get();
            break;
        case '/': {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:  ts.putback(t);
            return left;
        }
    }
}
double expression() {       //expression
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '+': left += term();
            t = ts.get();
            break;
        case '-': left -= term();
            t = ts.get();
            break;
        default:  ts.putback(t);
            return left;
        }
    }
}
int main()          //main
try {
    double val = 0;
    while (cin) {
        cout << "> ";
        Token t = ts.get();
        if (t.kind == 'q') break;
        if (t.kind == ';')
            cout << "=" << val << '\n';
        else ts.putback(t);
        val = expression();
        keep_window_open();
    }
}
catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
    return 2;
}

//enum Month {
//
//    jan=1,feb,mar,apr
//};
//int main() {

    /// mystery of cin
    /*string s;
        cin >> s;

        cout << "tp";

        string s1;
        cout << "tp1";
        cin >> s1;

        cout << s1;

    char c; char x;

    cin >> c;

    cin.putback(c);

    cin.putback('t');
    string a;
    cin >> a;
    cin.putback('k');
    cin >> x;

    cout << c << " " << a << " " << x;*/

    /*float x = 5.5;
    int i = narrow_cast<int>(x);
    cout << i;*/

    // get() i/p h i m

    // case 1
    //char s, c, v;
    //cout << "case1:";
    //cin >> s;
    //cin>>c;
    //cin >> v;
    //cout << s<<c<<v;
    //
    ////case 2 
    //char s1, c1, v1;
    //cout<< "case2:";
    //cin.get(s1);
    //cin.get(c1);
    //cin.get(v1);
    //cout << s1<< c1 << v1;

    // String vs string

    /*string s{"hello"};
    String s1;
    s1.append("world");
    cout << s << s1;*/

    //double d{ 3.4 };
    
   // a = 5;
    
    /*double d;
    cin >> d;
    int x = static_cast<int>(d);
    int x1 = narrow_cast<int>(d);  doesn't allow info loss
    cout << x<<x1;*/

   /* int i = 0;
    int& r=i;
   
    &r;
    

}*/

