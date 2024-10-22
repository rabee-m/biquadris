#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[10];

 public:
  Xwindow(int width=600, int height=450);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.

  enum {White=0, Black, Red, Green, Blue, Purple, Pink, Orange, Coral, Yellow}; // Available colours.

  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=White);

  // Draws a string
  void drawString(int x, int y, std::string msg);

};

#endif
