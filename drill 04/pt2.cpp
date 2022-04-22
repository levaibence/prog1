#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

struct Person
{
    private:
    string fn;
    string sn;
    int aa;

    public:
    Person(){}; //ures person adattipus letrehozasanak lehetosegenek megadasa
//    void pcheck(string f, int a){error("not enough arguments!");} ez minden bizonnyal ide nem kell
    bool pcheck(string f, string s, int a);

    string first_name()
    {
        return fn;
    }

    string second_name()
    {
        return sn;
    }

    int age()
    {
        return aa;
    }

    Person(string f, string s, int a)
    {
        if (!pcheck(f,s,a)) error("bad input data!");        
        fn = f;
        sn = s;
        aa = a;
    }
};

bool Person::pcheck(string f, string s, int a)
{
    if (a>=150||a<0) return false; //kor
    
    for (int i=0;i<f.size();i++) // first es second name
    {
        switch(f[i])
        {
            case ';': case ':': case '"': case '\'': case '[': case ']': case '!': 
            case '*': case '&': case '^': case '%': case '$': case '#': case '@':
            return false;   
        }
    }
    //ezt mar kulon functionbe kene idealisan de 30 oraja fent vagyok es most irtam kalkulus zht
    for (int i=0;i<s.size();i++)
    {
        switch(s[i])
        {
            case ';': case ':': case '"': case '\'': case '[': case ']': case '!': 
            case '*': case '&': case '^': case '%': case '$': case '#': case '@':
            return false;   
        }
    }
    
    return true;
}

istream& operator>>(istream& is, Person& person)
{
    string f,s;
s    int a;   

    cout << "enter name and age\n";
    is >> f >> s >> a;
    
    person = Person{f, s, a};
    
    return is;
}

ostream& operator<<(ostream& os, Person& person)
{
    return os << person.first_name() << " " << person.second_name() << ", " << person.age() << endl;
}

int main()
{
    try
    {
        vector<Person> emberek;        
        for (Person e; cin>>e; )//in
        {
            if (e.first_name()==".") break;
            emberek.push_back(e);
        }
        for (int i=0;i<emberek.size();i++)//out
        {
            cout<<emberek[i];
        }
        return 0;
    }

    catch (exception& e)
    {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }

    catch (...)
    {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}

