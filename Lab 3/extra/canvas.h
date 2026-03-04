#pragma once
class Canvas {
private:
    int width;
    int height;
    char ** mat;
public:
    Canvas(int lines, int columns);
	~Canvas();
    // contructor will call the clear method
    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);
    // tuples of x, y, value
    void set_pixels(int count, ...);
    void clear();
    void print() const;
};


