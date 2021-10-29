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


void drawPixel(int x,int y,int color)
{
    x += WINDOW_W/2;
    y = -y;
    y += WINDOW_H/2;
    putpixel(x,y,color);
}



void dda(int x1,int x2,int y1,int y2)
{

    double m = (double)(y2-y1)/(double)(x2-x1);


    if (abs(m) <= 1)
    {

        int x = x1, y = y1;
        drawPixel(x,y,YELLOW);
        while(x <= x2)
        {
            y =(int)floor(y+m);
            x++;
            drawPixel(x,y,YELLOW);
        }
    }

    else
    {

        double m = (double)(x2-x1)/(double)(y2-y1);
        int x = x1 ,y = y1;
        drawPixel(x,y,YELLOW);
        while(y <= y2)
        {
            x =(int)floor(x+m);
            y++;
            drawPixel(x,y,YELLOW);
        }


    }


}

void bressenhamLine(int x1,int x2,int y1,int y2)
{
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    int d = 2 * (dy - dx);

    int x= x1, y =y1;

    while(x < x2)
    {
        if (d >= 0)
        {
            drawPixel(x,y,YELLOW);
            y++;
            d = d + 2 * dy - 2 * dx;
        }
        else{
            drawPixel(x,y,YELLOW);
            d = d + 2 *dy;
        }
        x++;
    }


}
int main()
{
    initwindow(WINDOW_W,WINDOW_H);
    drawAxis();
    int x1= 20,y1= 10,x2 =100,y2=150;
    bressenhamLine(x1,y1,x2,y2);

    getchar();

    return 0;
}

