#include <iostream>
#include "Graph.h"
#include "Simple_window.h"
#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title);
    Open_polyline lines;
    
    private:
    Button next_button; // add (next_x,next_y) to lines
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Button menu_button, ls_menu_button;
    Menu color_menu,ls_menu;    

    void next();
    void quit();
   
    static void cb_red(Address, Address); // callback for red button
    static void cb_blue(Address, Address); // callback for blue button
    static void cb_black(Address, Address); // callback for black button
    static void cb_menu(Address, Address); // callback for menu button
    static void cb_solid(Address, Address); // callback for red button
    static void cb_dot(Address, Address); // callback for blue button
    static void cb_dash(Address, Address); // callback for black button
    static void cb_lsmenu(Address, Address); // callback for menu button

    // the actions:
    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); }
    void black_pressed() { change(Color::black); hide_menu(); }
    
    void solid_pressed() { changels(Line_style::solid); ls_hide_menu(); }
    void dot_pressed() { changels(Line_style::dot); ls_hide_menu(); }
    void dash_pressed() { changels(Line_style::dash); ls_hide_menu(); }

    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void hide_menu() { color_menu.hide(); menu_button.show(); }
    void ls_menu_pressed() { ls_menu_button.hide(); ls_menu.show(); }
    void ls_hide_menu() { ls_menu.hide(); ls_menu_button.show(); }
    void change(Color c) { lines.set_color(c); }
    void changels(Line_style c) { lines.set_style(c); }
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-150,0}, 70, 20, "Next point",
    [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
    [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
    next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
    xy_out{Point{100,0}, 100, 20, "current (x,y):"},
    color_menu{Point{x_max()-70,40}, 70, 20,Menu::vertical,"color"},
    menu_button{Point{x_max()-80,30}, 80, 20, "color menu", cb_menu},
    ls_menu{Point{x_max()-70,100}, 70, 20,Menu::vertical,"linestyle"},
    ls_menu_button{Point{x_max()-80,110}, 80, 20,"ls menu", cb_lsmenu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");

    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});

    ls_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    ls_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
    ls_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});

    attach(color_menu);
    attach(ls_menu);
    color_menu.hide();
    ls_menu.hide();
    attach(menu_button);
    attach(ls_menu_button);
    attach(lines);
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_lsmenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).ls_menu_pressed();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x,y});
    // update current position readout:
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    redraw();
}

void Lines_window::quit()
{
    hide(); // curious FLTK idiom to delete window
}

int main()
try 
{
    Lines_window win {Point{100,100},600,400,"lines"};
    return gui_main();
}
    catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
    catch (...) {
    cerr << "Some exception\n";
    return 2;
}
