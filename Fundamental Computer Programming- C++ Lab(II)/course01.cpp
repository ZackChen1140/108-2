#include<iostream>
#include<iomanip>
using namespace std;

struct OwO
{
   double x1;
   double y1;
   double x2;
   double y2;
   double x3;
   double y3;
   double x4;
   double y4;
   void ans()
   {
      if(x1==x3&&y1==y3)
         cout << fixed << setprecision(3) << x2 + x4 - x1 << " " << fixed << setprecision(3) << y2 + y4 - y1 << endl;
      else if(x2==x3&&y2==y3)
         cout << fixed << setprecision(3) << x1 + x4 - x2 << " " << fixed << setprecision(3) << y1 + y4 - y2<<endl;
      else if(x1==x4&&y1==y4)
         cout<< fixed << setprecision(3) << x2 + x3 - x1 << " " << fixed << setprecision(3) << y2 + y3 - y1 << endl;
      else
         cout<< fixed << setprecision(3) << x1 + x3 - x2 << " " << fixed << setprecision(3) << y1 + y3 - y2 << endl;
   }
};

int main()
{
   double a, b, c, d, e, f, g, h;
   while(cin >> a >> b >> c >> d >> e >> f >> g >> h)
   {
      OwO v =
      {
         a,
         b,
         c,
         d,
         e,
         f,
         g,
         h
      };
      v.ans();
   }
   return 0;
}