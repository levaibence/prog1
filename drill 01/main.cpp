#include <iostream>
#include "Graph.h"
#include "Simple_window.h"

double qr(double x)
{
    return x*x;
} 

int main()
{
    using namespace Graph_lib;

    Point base{100,100};
    Simple_window win{base,809,500,"My window"}; //aranymetszet

    Polygon poly{};
    poly.add(Point{300,200});
    poly.add(Point{150,300});
    poly.add(Point{210,60});
    poly.set_fill_color(Color::green);    

    win.attach(poly);

    Point origo{20,480};
    int gsize = 350;
    int gsegm = 7;
    int fscalex = gsize/gsegm; //fuggveny nagyitasi merteke a behuzasok szamatol fugg
    int fscaley = fscalex; //egybevagosagi valami idk

    Function quad{qr,0,gsegm,origo,fscalex,fscaley}; //negyzetfuggveny

    //Function oc {one,11,11,{250,405},200,30,30};

    Closed_polyline poly2{};
    poly2.add(origo);
    poly2.add(Point{30,480});
    poly2.add(Point{40,470});
    poly2.add(Point{30,460});
    poly2.set_style(Line_style(Line_style::dash,7));
    poly2.set_fill_color(Color::yellow);

    Rectangle tegla{Point{400,400},200,300};
    tegla.set_fill_color(Color::red);
    tegla.set_style(Line_style(Line_style::dash,2));

    Text tt {Point{600,200},"iskolalos ur tobb reszpektist kivanok"}; //a szoveg direkt van ott
    tt.set_font_size(16);
    tt.set_font(Font::times_italic);

    Axis x {Axis::x, origo, gsize, gsegm,"x"};  
    Axis y {Axis::y, origo, gsize, gsegm,"y"}; 

    Image tukan {Point{0,0},"image.jpeg"};

    win.attach(tukan);
    win.attach(x);
    win.attach(y);
    win.attach(quad);
    win.attach(poly);
    win.attach(poly2);
    win.attach(tegla);
    win.attach(tt);

    Circle c {Point{100,200},40};
    Ellipse e {Point{100,200}, 90,50};
    e.set_color(Color::dark_blue);
    Mark m {Point{100,200},'x'};

    ostringstream oss;
    oss << "kepernyomeret: " << x_max() << "*" << y_max() << "; ablakmeret: " << win.x_max() << "*" << win.y_max();

    Text sizes {Point{100,20},oss.str()};
    Image cal {Point{225,225},"snow_cpp.jpeg"}; // 320*240-pixel gif
    cal.set_mask(Point{40,40},200,150); // display center part of image

    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");
    win.wait_for_button();
       
    return 0;
}
