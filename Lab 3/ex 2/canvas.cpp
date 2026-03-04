#include "canvas.h"
#include <cmath>
#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height)
{
	Canvas::width = width;
	Canvas::height = height;
	mat = new char* [height];
	for (int i = 0; i < height; i++)
	{
		mat[i] = new char[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mat[i][j] = ' ';
		}
	}
}
Canvas::~Canvas()
{
	for (int i = 0; i < width; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		mat[y][x] = ch;
}
void Canvas::DrawRect(int left, int top, int right,int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		SetPoint(i, top, ch);   
		SetPoint(i, bottom, ch);
	}
	for (int j = top; j <= bottom; j++)
	{
		SetPoint(left, j, ch);
		SetPoint(right, j, ch);
	}
	
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		for (int j = top; j <= bottom; j++)
		{
			SetPoint(i, j, ch);
		}
	}
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx =abs( x2 - x1),sx=x1<x2?1:-1;
	int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int er = dx +dy,e2;
	while (true)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) break;
		e2 = 2 * er;
		if (e2 >= dy)
		{
			er += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			er += dx;
			y1 += sy;
		}
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{	
	int xi = 0, yi = ray;
	int d = 3 - 2 * ray;
	while (yi >= xi)
	{
		SetPoint(x + xi, y + yi, ch); 
		SetPoint(x - xi, y + yi, ch);
		SetPoint(x + xi, y - yi, ch);
		SetPoint(x - xi, y - yi, ch);
		SetPoint(x + yi, y + xi, ch);
		SetPoint(x - yi, y + xi, ch);
		SetPoint(x + yi, y - xi, ch);
		SetPoint(x - yi, y - xi, ch);
		if (d<0)
			d = d + 4 * xi + 6;
		else 
		{
			d = d + 4 * (xi - yi) + 10;
			yi--;
		}
		xi++;
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = -ray; i <= ray; i++)
	{
		for (int j=-ray; j <= ray; j++)
		{
			if (i * i + j * j <= ray * ray)
			{
				SetPoint(x + i, y + j, ch);
			}
		}
	}
}
void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << mat[i][j];
		}
		cout << std::endl;
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mat[i][j] = ' ';
		}
	}
}