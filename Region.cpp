#include<bits/stdc++.h>
#include<graphics.h>
#include<windows.h>
#include<math.h>

using namespace std;

const int WINDOW_W = 800, WINDOW_H = 600;

struct PT
{
    double x, y;
    PT() {}
    PT(double a, double b)
    {
        x = a;
        y = b;
    }
};

void drawAxis()
{
    for (int i = 0; i < WINDOW_H; i++)
        putpixel(WINDOW_W/2,i,WHITE);
    for (int i = 0; i < WINDOW_W; i++)
        putpixel(i,WINDOW_H/2,WHITE);
}

PT convertPixel(PT p)
{
    p.x  += WINDOW_W/2;
    p.y  = -p.y;
    p.y  += WINDOW_H/2;
    return p;
}
void drawPixel(PT p, int color)
{
    p = convertPixel(p);
    putpixel((int)(p.x+0.5),(int)(p.y+0.5),color);
}
void drawLine(PT a, PT b,int col)
{
    if(a.x > b.x) swap(a, b);

    ///horizontal

    if(a.y == b.y)
    {
        for(int x = a.x; x <= b.x; x++)
        {
            drawPixel(PT(x, a.y), col);
        }
    }

    ///vertical

    else if(a.x == b.x)
    {
        if(a.y > b.y) swap(a, b);
        for(int y = a.y; y <= b.y; y++)
        {
            drawPixel(PT(a.x, y), col);
        }
    }

    else
    {
        double m = (b.y-a.y)/(b.x-a.x);
        double m_inv = 1.0/m;
        if(fabs(m) <= 1.0)
        {
            if(a.x>b.x) swap(a,b);

            while(a.x <= b.x)
            {


                drawPixel(a, col);
                a.y+=m;
                a.x += 1;
            }

        }
        else
        {
            if(a.y >b.y) swap(a,b);
            while(a.y <= b.y)
            {


                drawPixel(a, col);
                a.x+=m_inv;
                a.y += 1;
            }
        }
    }
}

void drawPolygon(vector<PT> points)
{
    int n = points.size();
    for(int i=0; i<n; i++)
    {
        drawLine(points[i], points[(i+1)%n],WHITE);
    }
}


void BoundaryFill(PT currPixel, int boundaryColor, int fillColor)
{
    PT pixel = convertPixel(currPixel);
    int currColor = getpixel(pixel.x, pixel.y);
    if(currColor == boundaryColor || currColor == fillColor)
    {
        return;
    }

    drawPixel(currPixel, fillColor);

    BoundaryFill(PT(currPixel.x, currPixel.y+1), boundaryColor, fillColor);
    BoundaryFill(PT(currPixel.x, currPixel.y-1), boundaryColor, fillColor);
    BoundaryFill(PT(currPixel.x+1, currPixel.y), boundaryColor, fillColor);
    BoundaryFill(PT(currPixel.x-1, currPixel.y), boundaryColor, fillColor);
}
void floodFill(PT currPixel,int fillColor, int oldcolor)
{
    PT pixel = convertPixel(currPixel);
    int currentColor = getpixel(pixel.x,pixel.y);

    if(currentColor != oldcolor)
    {
        return;

    }
    drawPixel(currPixel, fillColor);
    floodFill(PT(currPixel.x,currPixel.y+1),fillColor,oldcolor);
    floodFill(PT(currPixel.x,currPixel.y-1),fillColor,oldcolor);
    floodFill(PT(currPixel.x+1,currPixel.y),fillColor,oldcolor);
    floodFill(PT(currPixel.x-1,currPixel.y),fillColor,oldcolor);

}

int main()
{
    initwindow(WINDOW_W,WINDOW_H,"Window 1");



    vector<PT> poly;

    poly.push_back(PT(40, 35));
    poly.push_back(PT(100, 70));
    poly.push_back(PT(45, 140));
    poly.push_back(PT(50, 180));
    poly.push_back(PT(-60,100));
    poly.push_back(PT(-30,-100));


    drawPolygon(poly);

    PT p = convertPixel(PT(0,0));
    int currentColor  = getpixel(p.x,p.y);
    floodFill(PT(0,0),YELLOW,currentColor);
    drawAxis();


    initwindow(WINDOW_W,WINDOW_H,"Window 2");

    vector<PT> poly2;
    poly2.push_back(PT(0,0));
    poly2.push_back(PT(0,100));
    poly2.push_back(PT(100,100));
    poly2.push_back(PT(100,0));
    drawPolygon(poly2);
    BoundaryFill(PT(10,10),WHITE,RED);
    drawAxis();




    getchar();

    return 0;
}

