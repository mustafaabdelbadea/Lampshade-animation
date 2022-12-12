#include <iostream>
#include<graphics.h>
#include<windows.h>
#include <chrono>
#include <thread>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }

    Point(int val1, int val2)
    {
        x = val1;
        y = val2;
    }

    Point(int value)
    {
        x = y = value;
    }


    void setX(int value)
    {
        x = value;
    }
    void setY(int value)
    {
        y = value;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    void Draw();
};



class Line
{
    Point Start;
    Point End;
public:
    Line() {}

    Line(int x1, int y1, int x2, int y2) : Start(x1, y1), End(x2, y2)
    {

    }

    Line (Point P1, Point P2) : Start(P1.getX(), P1.getY()), End(P2.getX(), P2.getY())
    {

    }

    void Draw()
    {
        setcolor(GREEN);

        line(Start.getX(), Start.getY(), End.getX(), End.getY());
    }
};

class Rect
{
    Point UL;
    Point LR;
public:
    Rect() {}

    Rect(int x1, int y1, int x2, int y2) : UL(x1, y1), LR(x2, y2)
    {

    }

    Rect (Point P1, Point P2) : UL(P1.getX(), P1.getY()), LR(P2.getX(), P2.getY())
    {

    }

    void Draw()
    {
        setcolor(GREEN);
        rectangle(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};

class Circle
{
    Point c;
    int rad;
public:
    Circle() {}
    Circle(int x1, int x2, int Rad) : c(x1, x2)
    {
        rad = Rad;
    }
    Circle(Point P1, int Rad) : c(P1.getX(), P1.getY())
    {
        rad = Rad;
    }
    void Draw()
    {
        setcolor(GREEN);
        circle(c.getX(), c.getY(), rad);


    }
};

class Picture
{
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;
    int cNum;
    int rNum;
    int lNum;
public:
    Picture()
    {
        pCircles = NULL;
        pLines = NULL;
        pRects = NULL;
        cNum = rNum = lNum = 0;
    }

    Picture(Circle *pc, Rect *pr, Line *pl, int cn, int rn, int ln)
    {
        pCircles = pc;
        pRects = pr;
        pLines = pl;
        cNum = cn;
        rNum = rn;
        lNum = ln;
    }

    void setCircles(Circle *pc, int cn)
    {
        pCircles = pc;
        cNum = cn;
    }
    void setRects(Rect *pr, int rn)
    {
        pRects = pr;
        rNum = rn;
    }
    void setLines(Line *pl, int ln)
    {
        pLines = pl;
        lNum = ln;
    }

    void paintPic()
    {
        int i;
        for(i = 0 ; i < cNum; i++)
        {
            pCircles[i].Draw();
        }

        for(i = 0 ; i < rNum; i++)
        {
            pRects[i].Draw();
        }
        for(i = 0 ; i < lNum; i++)
        {
            pLines[i].Draw();
        }
    }
};

int main()
{

    /*
        initwindow(600, 600);

        Line L(10, 20, 50,100);
        L.Draw();

        Rect R(10, 20, 50,100);
        R.Draw();

        Circle c(10, 20, 50 );
        c.Draw();

        getch();
        closegraph();
    */
    int counter;
    int open = 1;
    int cSize = 4, rSize = 2, lSize = 100;
    initwindow(600, 600);
    for( counter = 0; counter < 20; counter++)
    {
        cleardevice();
        cout<< "\n open" << open;
        if(open)
        {
            open= 0;
            Circle cArr[cSize] =
            {
                Circle(300, 300, 30),
                Circle(290, 290, 5),
                Circle(320, 290, 5),
                Circle(250, 375, 7),

            };


            setfillstyle(SOLID_FILL, YELLOW);
            ellipse(210, 225, 0, 360, 22, 11);
            setcolor(YELLOW);
            ellipse(300, 250, 0, 360, 25, 12.5);

            Rect rArr[rSize] =
            {
                Rect(180, 400, 230, 380)
            };

            Line lArr[lSize]
            {
                Line(300, 325, 300,380),
                Line(300, 350, 255, 375),
                Line(300, 350, 345, 375),
                Line(300, 380, 255, 400),
                Line(300, 380, 345, 400),
                Line(200,300,200,380),
                Line(210,300,210,380),
                Line(170, 300,250,300),
                Line(170, 300, 190, 230),
                Line(250, 300, 230, 230),

            };


            Picture myPic(cArr, rArr, lArr, cSize, rSize,lSize);
            myPic.paintPic();
        }
        else
        {

 open =1;
            Circle cArr[cSize] =
            {
                Circle(300, 300, 30),
                Circle(290, 290, 5),
                Circle(320, 290, 5),
                Circle(250, 375, 7),

            };


            fillellipse(210, 225, 22,11);
            setfillstyle(SOLID_FILL, YELLOW);
            ellipse(210, 225, 0, 360, 22, 11);



            setcolor(RED);
            ellipse(300, 250, 0, 360, 25, 12.5);
            Rect rArr[rSize] =
            {
                Rect(180, 400, 230, 380)
            };

            Line lArr[lSize]
            {
                Line(300, 325, 300,380),
                Line(300, 350, 255, 375),
                Line(300, 350, 345, 375),
                Line(300, 380, 255, 400),
                Line(300, 380, 345, 400),
                Line(200,300,200,380),
                Line(210,300,210,380),
                Line(170, 300,250,300),
                Line(170, 300, 190, 230),
                Line(250, 300, 230, 230),

            };


            Picture myPic(cArr, rArr, lArr, cSize, rSize,lSize);
            myPic.paintPic();
        }


      std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    getch();
    closegraph();
    return 0;

}
