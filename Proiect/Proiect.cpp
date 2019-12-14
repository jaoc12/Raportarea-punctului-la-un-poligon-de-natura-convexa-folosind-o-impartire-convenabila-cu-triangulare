#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("date.in");

struct punct {
    double x, y;
};

double arie(punct a, punct b, punct c) {
    double area = 0.0;
    area = (a.x) * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    area = abs(area / 2);
    return area;
}

int inTriunghi(punct a, punct b, punct c, punct p) {
    double a1 = arie(a, b, c);
    double a2 = arie(a, b, p);
    double a3 = arie(a, c, p);
    double a4 = arie(b, c, p);
    if (a1 == a2 + a3 + a4) {
        if (a2 == 0) {
            return 1;
        }
        if (a3 == 0) {
            return 0;
        }
        if (a4 == 0) {
            return 2;
        }
        return 0;
    }
    return -1;
}

int main()
{
    vector<punct> v;
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        in >> x >> y;
        v.push_back({ x,y });
    }
    punct p;
    in >> p.x >> p.y;
    for (int i = 1; i < n - 1; i++) {
        int rez = inTriunghi(v[0], v[i], v[i + 1], p);
        if (rez == 0) {
            cout << "Punctul este in interior";
            return 0;
        }
        if (rez == 1) {
            cout << "Punctul este pe latura determinata de punctele " << v[0].x << " " << v[0].y << " si "
                << v[i].x << " " << v[i].y;
            return 0;
        }
        if (rez == 2) {
            cout << "Punctul este pe latura determinata de punctele " << v[i+1].x << " " << v[i+1].y << " si "
                << v[i].x << " " << v[i].y;
            return 0;
        }
    }
    cout << "Punctul este in exteriorul poligonului";
}
