#include "canvas.h"
#include <iostream>
#include <stdarg.h>
void Canvas::clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mat[i][j] = ' ';
		}
	}
}
Canvas::Canvas(int lini, int coloane)
{
	Canvas::width = coloane;
	Canvas::height = lini;
	mat = new char* [height];
	for (int i = 0; i < height; i++)
	{
		mat[i] = new char[width];
	}
	Canvas::clear();
}
Canvas::~Canvas()
{
	for (int i = 0; i < height; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
void Canvas::set_pixel(int x, int y, char value)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		mat[y][x] = value;
}
void Canvas::set_pixels(int count, ...)
{
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char value = (char)va_arg(args, int);
		set_pixel(x, y, value);
	}
	va_end(args);
}
void Canvas::print() const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
}