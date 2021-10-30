#include<bits/stdc++.h>
#include<graphics.h>
#include<windows.h>
#include<math.h>

using namespace std;

const int WINDOW_W = 800, WINDOW_H = 600;


void drawAxis()
{
    for (int i = 0; i < WINDOW_H; i++)
        putpixel(WINDOW_W/2,i,WHITE);
    for (int i = 0; i < WINDOW_W; i++)
        putpixel(i,WINDOW_H/2,WHITE);
}

void drawPixel(int x,int y)
{
    x  += WINDOW_W/2;
    y  = -y;
    y  += WINDOW_H/2;

    putpixel(x,y,YELLOW);
}
void bressenhamCircle(int xc,int yc, int r)

{
    int x =0;
    int y = r;
    int d = 3  - 2*r;
    drawPixel(x,y);
    while(y >= x)
    {
        x++;
        if (d >=0)
        {
            y--;
            d= d + 4 *(x -y) +10;

        }
        else{
            d = d + 4 * x +6;
        }
        drawPixel(xc+x,yc+y);
        drawPixel(xc-x,yc+y);
        drawPixel(xc+x,yc-y);
        drawPixel(xc-x,yc-y);
        drawPixel(xc+y,yc+x);
        drawPixel(xc-y,yc+x);
        drawPixel(xc+y,yc-x);
        drawPixel(xc-y,yc-x);
    }

}

void midpointCircle(int xc,int yc, int r)

{
    int x =0,y = r;

    int d = 1 -r;
    drawPixel(x,y);
    while(x <= y)
    {
        if(d < 0)
        {
            d =  d + 2 * x +3;
        }
        else{
            d = d + 2 * (x -y) + 5;
            y --;
        }
        x++;
        drawPixel(xc+x,yc+y);
        drawPixel(xc-x,yc+y);
        drawPixel(xc+x,yc-y);
        drawPixel(xc-x,yc-y);
        drawPixel(xc+y,yc+x);
        drawPixel(xc-y,yc+x);
        drawPixel(xc+y,yc-x);
        drawPixel(xc-y,yc-x);

    }



}



int main()
{
    initwindow(WINDOW_W,WINDOW_H);
    drawAxis();
    int x =10,y =20;
    int r = 200;
    midpointCircle(x,y,r);
    x = 40,y = 60, r =150;
    bressenhamCircle(x,y,r);



    getchar();

    return 0;
}


