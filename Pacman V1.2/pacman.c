
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include "LIB01.h"

void SpaceFree(int x1, int y1, int x2, int y2);  //genera el espacio de trabajo del juego
void PacmanOp(int x, int y, int color);  //Genera a pacman con la boca cerrada
void PacmanCl(int x, int y, int color);  //Genera a pacman con la boca abierta
void PacmanLef(int x ,int y, int color);  //gira a pacman a la izquierda
void PacmanDwn(int x ,int y, int color);  //gira a pacman a la derecha
void PacmanUp(int x, int y, int color);  //gira a pacman hacia arriba
void MovePacman();
void fantasma(int x, int y, int color);
void aleatorio(int option, int iCorxF, int iCoryF);

int main()
{

    //int radx = 30;  //radio de pacman

    initwindow(800, 600, "PACMAN:V");  //pantalla incial de tamaño 800x600
    SpaceFree(0, 0, 800, 600);  //espacio de trabajo 800x600
    /*PacmanOp(400, 300, radx);
    PacmanCl(500, 400, radx);*/
    //fantasma(300, 400, RED);
    MovePacman();  //funcion para mover a pacman
    getch();

}

//Funcion para generar un espacio con bordes
void SpaceFree(int x1, int y1, int x2, int y2)
{
    rectangle(x1+5, y1+5, x2-5, y2-5);  //rectangulo intermedio
    interior(x1, y1, x2, y2, 15);
    exterior(x1 +20, y1 +20, x2 -20, y2 -20, 0);
}


//Funcion para generar a pacman abierto
void PacmanOp(int x, int y, int color)
{
    int radx = 15;  //radio de pacman
//Cuerpo de pacman

   setfillstyle(1,color);
   setcolor(color);
   fillellipse(x, y, radx, radx);

//Boca de pacman
  /* setcolor(7);
   arc(x, y, 0, 45, radx);
   setcolor(YELLOW);
   line(x, y, x+radx, y);
   line(x, y, x+(.70*radx), y-(.70*radx));*/


//Boca de pacman alternativa

    setcolor(color);
    setfillstyle(1,0);
    pieslice(x,y, -10, 50, radx);
    setcolor(7);
    arc(x, y, 0, 45, radx);

//Ojo de pacman
   setcolor(0);
   setfillstyle(1,0);
   fillellipse(x, y-(radx/2), radx/10, radx/10);
}

void PacmanCl(int x, int y, int color)  //pacman cerrado
{
    int radx = 15;
    //Cuerpo de pacman

   setfillstyle(1,color);
   setcolor(color);
   fillellipse(x, y, radx, radx);

   //Ojo de pacman
   setcolor(0);
   setfillstyle(1,0);
   fillellipse(x, y-(radx/2), radx/10, radx/10);
}

void fantasma(int x, int y, int color)
{
    int radx = 10;

    setcolor(color);

    setfillstyle(1, color);

    /*rectangle(x-10, y-10, x+10, y+10);
    fillellipse(x, y, radx*.7, radx);
    for(int i = 0; i < 3; i++)
    {
            fillellipse(x+radf, y+radx, radx *.1, radx*.3);
            radf =- 10;
    }*/

    arc(x, y, 0, 180, radx);
    line(x+radx, y, x+radx, y+radx*2);
    line(x-radx, y, x-radx, y+radx*2);
    line(x+radx, y+radx*2, x+(radx/2), y+(radx));
    line(x+(radx/2), y+(radx), x,  y+radx*2);
    line(x, y+radx*2, x-(radx/2), y+radx);
    line(x-(radx/2), y+radx, x-radx, y+radx*2);
    floodfill(x, y, color);
    setcolor(BLACK);
    setfillstyle(1, BLACK);
    fillellipse(x+radx/2, y, radx/6, radx/4);
    fillellipse(x-radx/2, y, radx/6, radx/4);

}

void MovePacman()
{
    //iCorxU = variable para mover el objeto del usuario
    //iCorxF = Variable del fantasma que se mueve autonomamente
    int iOp, iCorxU=50, iCorxF=50, iCoryU=50, iCoryF=50, iCoryF2 = 50;
    //interfaz();
    PacmanOp(iCorxU, 50,YELLOW);
    fantasma(iCorxF, 250, YELLOW); //fantasma
    do {
        if (kbhit()){ //espera que alguna tecla sa presionada
        iOp=getch();  //gurada en una variable wl avlr ascii
        switch(iOp)
        {
            case 77: //72 arriba, 75 izquierda, 80 abajo
            PacmanOp(iCorxU, iCoryU, YELLOW);//aparece abierto
            PacmanCl(iCorxU, iCoryU, YELLOW);  //aparece cerrado
            PacmanOp(iCorxU, iCoryU, BLACK);    //desaparece abierto
            PacmanCl(iCorxU, iCoryU, YELLOW);  //aparece cerrado
            PacmanCl(iCorxU, iCoryU, BLACK);  //desaparece cerrado
            //PacmanOp(iCorxU, 40, 0);*/
            if(iCorxU<=750)
            {
                iCorxU+=10;
                PacmanOp(iCorxU, iCoryU, YELLOW);
            }

            else{
                iCorxU=50;
            PacmanOp(iCorxU, iCoryU, YELLOW);
            //delay(50);
            //PacmanCl(iCorxU, 40, YELLOW);
            }
            break;

            case 75: //izquierda
            PacmanLef(iCorxU, iCoryU, YELLOW);
            PacmanCl(iCorxU, iCoryU, BLACK);
            PacmanLef(iCorxU, iCoryU, BLACK);
            PacmanCl(iCorxU, iCoryU, YELLOW);  //aparece cerrado
            PacmanCl(iCorxU, iCoryU, BLACK);
            if(iCorxU>=50)
            {
                iCorxU-=10;
                PacmanLef(iCorxU, iCoryU, YELLOW);
            }

            else{
                iCorxU=750;
            PacmanLef(iCorxU, iCoryU, YELLOW);
            //delay(50);
            //PacmanCl(iCorxU, 40, YELLOW);
            }

            break;

            case 72:  //arriba
            PacmanUp(iCorxU, iCoryU, YELLOW);
            PacmanCl(iCorxU, iCoryU, BLACK);
            PacmanUp(iCorxU, iCoryU, BLACK);
            PacmanCl(iCorxU, iCoryU, YELLOW);  //aparece cerrado
            PacmanCl(iCorxU, iCoryU, BLACK);
                if(iCoryU>=50)
            {
                iCoryU-=10;
                PacmanUp(iCorxU, iCoryU, YELLOW);
            }

            else{
                iCoryU=550;
            PacmanUp(iCorxU, iCoryU, YELLOW);
            //delay(50);
            //PacmanCl(iCorxU, 40, YELLOW);
            }

            break;

            case 80: //abajo
            PacmanDwn(iCorxU, iCoryU, YELLOW);
            PacmanCl(iCorxU, iCoryU, BLACK);
            PacmanDwn(iCorxU, iCoryU, BLACK);
            PacmanCl(iCorxU, iCoryU, YELLOW);  //aparece cerrado
            PacmanCl(iCorxU, iCoryU, BLACK);
                if(iCoryU<=550)
            {
                iCoryU+=10;
                PacmanDwn(iCorxU, iCoryU, YELLOW);
            }

            else{
                iCoryU=50;
            PacmanDwn(iCorxU, iCoryU, YELLOW);
            //delay(50);
            //PacmanCl(iCorxU, 40, YELLOW);
            }


    }
        }
        fantasma(iCorxF, 250, 0);  //fantasma amarillo, hacia la drecha
    if(iCorxF <= 750)
        iCorxF += 15;
    else
        iCorxF =50;
    fantasma(iCorxF, 250, YELLOW);

    fantasma(250, iCoryF, 0);  //fantasma rojo, hacia abajo
    if(iCoryF <= 550)
        iCoryF += 15;
    else
        iCoryF =50;
    fantasma(250, iCoryF, RED);

    //aleatorio(rand() % 2, iCorxF, iCoryF);

    fantasma(150, iCoryF2, 0);  //fantasma azul, hacia arriba
    if(iCoryF2 >= 50)
        iCoryF2 -= 15;
    else
        iCoryF2 =550;
    fantasma(150, iCoryF2, BLUE);



    }while(iOp!=27);

}

void PacmanLef(int x, int y, int color){
    int radx = 15;  //radio de pacman
//Cuerpo de pacman

   setfillstyle(1,color);
   setcolor(color);
   fillellipse(x, y, radx, radx);


//Boca de pacman alternativa

    setcolor(color);
    setfillstyle(1,0);
    pieslice(x,y, 130, 190, radx);
    setcolor(7);
    arc(x, y, 130, 190, radx);

//Ojo de pacman
   setcolor(0);
   setfillstyle(1,0);
   fillellipse(x, y-(radx/2), radx/10, radx/10);
}

void PacmanDwn(int  x, int y, int color)
{
    int radx = 15;  //radio de pacman
//Cuerpo de pacman

   setfillstyle(1,color);
   setcolor(color);
   fillellipse(x, y, radx, radx);


//Boca de pacman alternativa

    setcolor(color);
    setfillstyle(1,0);
    pieslice(x,y, 260, 320, radx);
    setcolor(7);
    arc(x, y, 260, 320, radx);

//Ojo de pacman
   setcolor(0);
   setfillstyle(1,0);
   fillellipse(x, y-(radx/2), radx/10, radx/10);
}

void PacmanUp(int x, int y, int color)
{
     int radx = 15;  //radio de pacman
//Cuerpo de pacman

   setfillstyle(1,color);
   setcolor(color);
   fillellipse(x, y, radx, radx);


//Boca de pacman alternativa

    setcolor(color);
    setfillstyle(1,0);
    pieslice(x,y, 80, 140, radx);
    setcolor(7);
    arc(x, y, 80, 140, radx);

//Ojo de pacman
   setcolor(0);
   setfillstyle(1,0);
   fillellipse(x, y-(radx/2), radx/10, radx/10);
}


void aleatorio(int option, int iCorxF, int iCoryF)
{

    switch(option)
    {
        case 1:
        fantasma(iCorxF, 250, 0);  //fantasma amarillo, hacia la drecha
    if(iCorxF <= 750)
        iCorxF += 15;
    else
        iCorxF =50;
    fantasma(iCorxF, 250, YELLOW);
    break;

    case 2:
    fantasma(250, iCoryF, 0);  //fantasma rojo, hacia abajo
    if(iCoryF <= 550)
        iCoryF += 15;
    else
        iCoryF =50;
    fantasma(250, iCoryF, RED);
    break;
    }


}
