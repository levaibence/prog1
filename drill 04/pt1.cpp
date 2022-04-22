#include <iostream>
#include "Graph.h"
#include "Window.h"

//fuggvenyek definicioi

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return slope(x)+cos(x); }

int main()
{
    //ablak, tengely, origo beallitasai
 
    using namespace Graph_lib;    
    constexpr int wwidth = 600;
    constexpr int wheight = 600;
    int xalength = 400;
    int yalength = 400;
    Point origo = {300,300};

    Window win{Point{100,100},wwidth,wheight,"Function graphs."};
    
    Axis xa {Axis::x, Point{origo.x - xalength / 2 , origo.y}, xalength, 20, "1 = 20 pixels"};
    Axis ya {Axis::y, Point{origo.x, origo.y + yalength / 2}, yalength, 20, "1 = 20 pixels"};

    xa.set_color(Color::red);
    ya.set_color(Color::red);

    //fuggvenybeallitasok (minden fuggvenyre vonatkozik)
 
    int xscale = 20;
    int yscale = 20;
    int pointnum = 400;
    int range_min = -10;
    int range_max = 11; //(sic)

    Function f1 {one, range_min, range_max, origo, pointnum, xscale, yscale}; //konstans
    Function f2 {slope, range_min, range_max, origo, pointnum, xscale, yscale}; //linearis
    Text label {Point{origo.x - xalength/2, origo.y * yscale * slope(range_min) + 30}, "x/2"};
    Function f3 {square, range_min, range_max, origo, pointnum, xscale, yscale}; //negyzetes
    Function f4 {[](double x){return cos(x);}, range_min, range_max, origo, pointnum, xscale, yscale}; //koszinusz
    f4.set_color(Color::blue);
    Function f5 {sloping_cos, range_min, range_max, origo, pointnum, xscale, yscale}; //linearis + koszinusz

    win.attach(xa);
    win.attach(ya);
    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    win.attach(f5);
    win.attach(label);
   
    return Fl::run();
}
