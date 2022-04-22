#include <iostream>
#include "std_lib_facilities.h"

class B1
{
    public:    
    virtual void vf()
    {
        std::cout<<"B1::vf\n";
    }
    virtual void pvf() = 0;
    void f()
    {
        std::cout<<"B1::f\n";
    }
};

class D1 : public B1
{
    public:
    void vf()
    {
        std::cout<<"D1::vf\n";
    }   
    void f()
    {
        std::cout<<"D1::f\n";
    }
};

class D2 : public B1
{
    public:    
    void pvf()
    {
        std::cout<<"D2::pvf\n";
    }
};

class B2
{
    public:
    virtual void pvf() = 0;
};

class D21 : public B2
{
    string value;
    public:
    D21()
    {
        value = "value";
    }    
    void pvf()
    {
        cout << value << "\n";
    }
};

class D22 : public B2
{
    int value;    
    public:
    D22()
    {
        value = 1;
    }
    void pvf()
    {
        cout << value << "\n";
    }
};

void f(B2& arg)
{
    arg.pvf();
}

int main()
{
/*    //1., 2., 4.
    B1 b;
    D1 d;s  
    b.vf();
    b.f();
    b.pvf();
    d.vf();
    d.f();
    d.pvf();

    //3.
    B1& bref = d;
    bref.vf();
    bref.f(); 
    bref.pvf(); */
    //a bref referencia tulajdonképpen egy D1 osztályú objektumra utal, ezért a virtuális függvények felülírásra kerülnek, de mivel a referencia típusa B1, ezért a felülírhatatlan fügvények a B1 típusból jönnek  
    //egy pure virtual function létrehozása B1 osztályt absztrakttá teszi, így közvetlenül nem lesz használható. Mivel D1 sem definiálja a pvf() függvényt, ezért az is absztraktnak minősül.

/*    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();*/

    D21 strd;
    D22 intd;

    f(intd);
    f(strd);

    return 0;
}
