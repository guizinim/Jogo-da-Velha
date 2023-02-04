#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<GL/glut.h>
#include <stdio.h>

void desenhaTexto();
void inicioJogo();
void recomecar();
void ganhar();
void desenhaMouse();
void desenharO();
void desenharX();
void identificarEstado();
void desenhaTitulo();
void desenhaNome();
void desenhaVez();
void declararVencedor();
void desenha ();
int main(int argc, char* argv[]);

//inicio jogo
char vezJogador = 'X';
bool vencedor = false;

//mouse
bool estado = false;
int x,y;
int local[3][3];

//funcao para desenhar texto
void desenhaTexto(char text[])
{
    int i;
    int textLength = strlen(text);

    for(i = 0; i < textLength; i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN,text[i]);
    }
}

//troca jogador
void inicioJogo()
{
    if (vezJogador == 'X')

        vezJogador ='O';

    else

        vezJogador = 'X';
}

void escutarTeclado(unsigned char tecla, int x, int y)
{
        switch (tecla) {

            case 'r':
                 printf("\nRecomecando...");
                 vezJogador = 'O';
                 vencedor = false;
                 recomecar();
            break;

            case 'R':
                 printf("\nRecomecando...");
                 vezJogador = 'O';
                 vencedor = false;
                 recomecar();
            break;

    }
    glutPostRedisplay();
}

void recomecar()
{
    ChangeDisplaySettings(NULL , 0);
    ShowCursor(true);
}


void declararVencedor()
{
    if(vencedor == true)
    {
        printf("\nPartida encerrada");
        printf("\nVencedor %c",vezJogador == 'X' ? 'O' : 'X');
        printf("\nDeseja recomecar o jogo? - [r]\n");
    }

    else if (((local[0][0] == 'X') || (local[0][0] == 'O')) &&
            ((local[0][1] == 'X') || (local[0][1] == 'O')) &&
            ((local[0][2] == 'X') || (local[0][2] == 'O')) &&
            ((local[1][0] == 'X') || (local[1][0] == 'O')) &&
            ((local[1][1] == 'X') || (local[1][1] == 'O')) &&
            ((local[1][2] == 'X') || (local[1][2] == 'O')) &&
            ((local[2][0] == 'X') || (local[2][0] == 'O')) &&
            ((local[2][1] == 'X') || (local[2][1] == 'O')) &&
            ((local[2][2] == 'X') || (local[2][2] == 'O')))
    {
        printf("\nPartida encerrada");
        printf("\nEmpate");
        printf("\nDeseja recomecar o jogo? - [r]\n");
    }


}
//as possibilidade de ganhar ou empatar
void ganhar()
{


    if (((local[0][0] == 'X') && (local[0][1] == 'X') && (local[0][2] == 'X')) || ((local[0][0] == 'O') && (local[0][1] == 'O') && (local[0][2] == 'O')))
    {
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        //primeira linha vertical
        glVertex2f(200,420);
        glVertex2f(600,420);
        glEnd();
         vencedor = true;
    }
    else if (((local[1][0] == 'X') && (local[1][1] == 'X') && (local[1][2] == 'X')) || ((local[1][0] == 'O') && (local[1][1] == 'O') && (local[1][2] == 'O')))
    {
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        //segunda linha vertical
        glVertex2f(200,310);
        glVertex2f(600,310);
        glEnd();
         vencedor = true;
    }
    else if(((local[2][0] == 'X') && (local[2][1] == 'X') && (local[2][2] == 'X')) || ((local[2][0] == 'O') && (local[2][1] == 'O') && (local[2][2] == 'O')))
    {
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        //terceira linha vertical
        glVertex2f(200,200);
        glVertex2f(600,200);
        glEnd();
         vencedor = true;
    }
    else if(((local[0][0] == 'X') && (local[1][0] == 'X') && (local[2][0] == 'X')) || ((local[0][0] == 'O') && (local[1][0] == 'O') && (local[2][0] == 'O')))
        {
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        //primeira linha horizontal
        glVertex2f(250,470);
        glVertex2f(250,150);
        glEnd();
         vencedor = true;
    }
    else if(((local[0][1] == 'X') && (local[1][1] == 'X') && (local[2][1] == 'X')) || ((local[0][1] == 'O') && (local[1][1] == 'O') && (local[2][1] == 'O'))){
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        //segunda linha horizontal
        glVertex2f(400,470);
        glVertex2f(400,150);
        glEnd();
         vencedor = true;
    }

     else if(((local[0][2] == 'X') && (local[1][2] == 'X') && (local[2][2] == 'X')) || ((local[0][2] == 'O') && (local[1][2] == 'O') && (local[2][2] == 'O')))
    {
         glBegin(GL_LINES);
         glColor3f(1,0,0);
         //terceira linha horizontal
        glVertex2f(550,470);
        glVertex2f(550,150);
        glEnd();
        vencedor = true;
     }
     else if(((local[0][2] == 'X') && (local[1][1] == 'X') && (local[2][0] == 'X')) ||((local[0][2] == 'O') && (local[1][1] == 'O') && (local[2][0] == 'O')))
        {
        glBegin(GL_LINES);
         glColor3f(1,0,0);
        //diagonal [/]
        glVertex2f(600,470);
        glVertex2f(200,150);
        glEnd();
        vencedor = true;
        }

    else if(((local[0][0] == 'X') && (local[1][1] == 'X') && (local[2][2] == 'X')) || ((local[0][0] == 'O') && (local[1][1] == 'O') && (local[2][2] == 'O'))){
        glBegin(GL_LINES);
        glColor3f(1,0,0);
        //diagonal [\]
        glVertex2f(200,470);
        glVertex2f(600,150);
        glEnd();
        vencedor = true;
    }

}
//Coloca o objeto onde for clicado
void desenhaMouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        estado = true;
        x = mousex ;
        y = 700 - mousey ;
        //printf("%d,%d\n",x,y);
    }
    glutPostRedisplay();
}
 //Desenha O
void desenharO(float largura,float altura)
{
    char text[2] = "O";
    glPushMatrix();
        glColor3f(0,0,0.8);
        glTranslatef(largura,altura,0);
        glScalef(0.75,0.75,0.75);
        glLineWidth(3);
    desenhaTexto(text);
    glPopMatrix();
}
//Desenha X
void desenharX(int largura, int altura)
{
     char text[2] = "X";
      glPushMatrix();
         glColor3f(0,1,0);
         glTranslatef(largura,altura,0);
         glScalef(0.75,0.75,0.75);
         glLineWidth(3);
      desenhaTexto(text);
      glPopMatrix();
}
//desenha X ou O dependendo da vez do jogador
void desenharJogador ()
{
    if (local[0][0] == 'X')
        desenharX(200,390);
        else if (local[0][0] == 'O')
        desenharO(200,390);

    if(local[0][1] == 'X')
        desenharX(370,390);
        else if(local[0][1] == 'O')
        desenharO(370,390);

    if(local[0][2] == 'X')
        desenharX(530,390);
        else if(local[0][2] == 'O')
        desenharO(530,390);

    if (local[1][0] == 'X')
        desenharX(200,270);
        else if(local[1][0] == 'O')
        desenharO(200,270);

    if (local[1][1] == 'X')
        desenharX(370,270);
        else if (local[1][1] == 'O')
        desenharO(370,270);

    if (local[1][2] == 'X')
        desenharX(530,270);
        else if (local[1][2] == 'O')
        desenharO(530,270);

     if (local[2][0] == 'X')
        desenharX(200,150);
        else if (local[2][0] == 'O')
        desenharO(200,150);

    if (local[2][1] == 'X')
        desenharX(370,150);
        else if(local[2][1] == 'O')
        desenharO(370,150);

    if (local[2][2] == 'X')
        desenharX(530,150);
        else if (local[2][2] == 'O')
        desenharO(530,150);

}
//Reconhece o local onde foi clicado, e imprimi a vez do jogador no bloco
void identificarEstado()
{
    if(estado == true)
{
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();

        estado = false;
}
    //Divide os quadrado da tabela

    if(vencedor == true){
        return;
    }

     //Quadrado 1
    if(200 < x && x < 300 && 390 < y && y < 500 ){
            {if (local[0][0] == 0)
            {
                local[0][0] = vezJogador;
                inicioJogo();
            }
                }
}
    //Quadrado 2
    else if(300 < x && x < 500 && 390 < y && y < 500)
           {if (local[0][1] == 0)
            {
                local[0][1] = vezJogador;
                inicioJogo();
            }
            }

    //Quadrado 3
    else if(500 < x && x < 600 && 390 < y && y < 500)
          {if (local[0][2] == 0)
            {
                local[0][2] = vezJogador;
                inicioJogo();
            }
            }

    //Quadrado 4
    else if(200 < x && x < 300 && 250 < y && y < 380)
           {if (local[1][0] == 0)
            {
                local[1][0] = vezJogador;
                inicioJogo();
            }
            }

    //Quadrado 5
    else if(300 < x && x < 500 && 250 < y && y < 380)
           {if (local[1][1] == 0)
            {
                local[1][1] = vezJogador;
                inicioJogo();
            }
            }

    //Quadrado 6
    else if(500 < x && x < 600 &&  250 < y && y < 380)
           {if (local[1][2] == 0)
            {
                local[1][2] = vezJogador;
                inicioJogo();
            }
            }

    //Quadrado 7
    else if(200 < x && x < 300 && 100 < y && y < 250)
           {if (local[2][0] == 0)
            {
                local[2][0] = vezJogador;
                inicioJogo();
            }
            }

    //Quadrado 8
    else if(300 < x && x < 500 && 100 < y && y < 250)
         {
             if (local[2][1] == 0)
            {
                local[2][1] = vezJogador;
                inicioJogo();
            }
            }

    //Quadrado 9
    else if(500 < x && x < 600 && 100 < y && y < 250 )
          {
           if (local[2][2] == 0)
         {
                local[2][2] = vezJogador;
                inicioJogo();
            }
            }
}


//titulo jogo da velha
void desenhaTitulo()
{
    char text[14] = "Jogo da Velha";
        glPushMatrix();
        glColor3f(2,2,2);
        glTranslatef(220,530,0);
        glScalef(0.50,0.50,0.50);
        glLineWidth(5);
        desenhaTexto(text);
        glPopMatrix();
        glFlush();
}
//nome na tela
void desenhaNome()
{
    char text[23] = "Guilherme";
        glPushMatrix();
        glColor3f(2,2,2.2);
        glTranslatef(220,500,0);
        glScalef(0.15,0.15,0.15);
        glLineWidth(2);
        desenhaTexto(text);
        glPopMatrix();
        glFlush();
}
//Desenha a vez do jogador
void desenhaVez()
{
    char text[11] = "Player: ";

    //strcat(text, (char *)vezJogador);
    if (vezJogador == 'X')
        strcat(text, "X");
    else
        strcat(text, "O");


    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(430,500,0);
        glScalef(0.15,0.15,0.15);
        glLineWidth(2);

    desenhaTexto(text);
    glPopMatrix();
    glFlush();
}


//Desenha todas funcoes no terminal e Tela de display
 void desenha ()
{
    declararVencedor();

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D( 0, 800, 0, 700 ) ;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    desenhaNome();
    desenhaTitulo();
    desenhaVez();
    identificarEstado();
    desenharJogador ();
    ganhar();

	glBegin(GL_LINES);
    glColor3f(1,1,1);
    /*Vertical */
    glVertex2f(300,150);
    glVertex2f(300,470);
    glVertex2f(500,150);
    glVertex2f(500,470);


    /*Horizontal */
    glVertex2f(200,370);
    glVertex2f(600,370);
    glVertex2f(200,250);
    glVertex2f(600,250);

    glEnd();

	glFlush();
    }
    //Funcao principal

int main(int argc, char* argv[]) {

    glutInit(&argc, argv);
    glutInitWindowSize(800,700);

    glutInitWindowPosition(500,155);

    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutCreateWindow("Jogo da Velha");

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutKeyboardFunc(escutarTeclado);
    glutMouseFunc(desenhaMouse);
    glutDisplayFunc(desenha);

    glutMainLoop();

    return 0;
}
