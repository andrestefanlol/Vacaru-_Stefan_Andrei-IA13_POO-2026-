#include <iostream>
#include "Canvas.h"

using namespace std;

int main() {
    Canvas c(60, 20);
    c.Clear();
    while (true)
    {
        cout << "Dreptunghi(1),Linie(2),Cerc(3),Cerc Plin(4),Punct(5)";
        int x;
        char s;
        cin >> x;
        if (x == 1)
            cin >> s, c.DrawRect(2, 2, 57, 17, s), c.Print();
        else if (x == 2)
            cin >> s, c.DrawLine(2, 2, 57, 17, s), c.Print();
        else if (x == 3)
            cin >> s, c.DrawCircle(15, 10, 6, s), c.Print();
        else if (x == 4)
            cin >> s, c.FillCircle(45, 10, 5, s), c.Print();
        else
            cin >> s, c.SetPoint(30, 10, s), c.Print();
		cout << "Exit(1),Continue(2)";
        cin >> x;
		if (x == 1)
			break;
		c.Clear();
    }
    return 0;
}