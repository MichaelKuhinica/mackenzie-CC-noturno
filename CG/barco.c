/**************************
Ariane Moreira de Oliveira Gouveia
TIA: 306.3942-5
Michael Martins Kuhinica
TIA: 306.5363-0
Curso: Ciência da Computação - Noturno - 5N
Projeto 1 - Computação Gráfica.
**************************/

#include <GL/glut.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define _USE_MATH_DEFINES
#define GL_PI 3.1415f

static int eixoyMundo = 0,  eixoxMundo = 0,  eixozMundo = 0;

/*protótipos das funcoes*/
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);

/*variaveis globais*/

 
GLfloat posXObjeto = 0.0,
  posYObjeto = 0.0,
  posZObjeto = 0.0;
 
int eixoyObjeto = 0,
 eixoxObjeto = 0,
 eixozObjeto = 0;
 
 GLfloat ctrlpoints[4][3] = {
    { -50.0, -4.0, 0.0},
    { -2.0, 4.0, 0.0},
    {2.0, -4.0, 0.0},
    {50.0, 2.0, 0.0}};
 
/*iluminacao do ambiente*/
const GLfloat light_ambient[]  = { 1.0f, 1.0f, 0.5f, 0.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 0.0f, 0.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 0.0f };
const GLfloat light_position[] = { -30.0f, 38.0f, 0.5f, 0.0f };

/*************************Funcao principal*************************/

int main(int argc, char** argv){
 
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (800, 600);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Barquinho");
 
  init();
 
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special);
 
  //  glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    
  glutMainLoop();
 
  return 0;
}

/**************FIM Funcao principal**************/



/************Função de Tela********************/
void init(void){
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glOrtho (-50,50,-50,50,-50,50);
  glShadeModel(GL_FLAT);
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
   glEnable(GL_MAP1_VERTEX_3);
}



/**********************desenhando o sol***************************/
void desenhaSol()
{
   
      glPushMatrix();// Bolinha
          glColor3f(1.0,1.0,0);
          glTranslatef(-30.0,38.0,0.0);
          glScalef(2,2,2);
         glutSolidSphere(4,1000,1000);
         glPopMatrix();
   glPushMatrix();

/*Pontinhas do sol*/
  glBegin(GL_LINES);
  glColor3f (1.0, 1.0, 0.0);// AMARELA
  glVertex3f(-34.0, 42.0,0.0); glVertex3f(-40.0, 45.0,0.0);
  glVertex3f(-36.0, 39.0,0.0); glVertex3f(-42.0, 39.0,0.0);
  glVertex3f(-34.0, 36.0,0.0); glVertex3f(-40.0, 33.0,0.0);
 
  glVertex3f(-30.0, 30.0,0.0); glVertex3f(-30.0, 27.0,0.0);
 
  glVertex3f(-25.0, 36.0,0.0); glVertex3f(-19.0, 33.0,0.0);
  glVertex3f(-25.0, 39.0,0.0); glVertex3f(-18.0, 39.0,0.0);
  glVertex3f(-26.0, 42.0,0.0); glVertex3f(-20.0, 45.0,0.0);
 
  glVertex3f(-30.0, 43.0,0.0); glVertex3f(-30.0, 48.0,0.0);
  glEnd();
  glBegin(GL_LINES);
  glColor3f (1.0, 1.0, 0.0);// AMARELA
 
  glEnd();
 
  glEnd();
 
 
}
 
/**************************Desenho do mundo************************************/
void display(void){
 
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
 
//girar o objeto
 glRotatef((GLfloat) eixoxObjeto, 1.0, 0.0, 0.0);
 glRotatef((GLfloat) eixoyObjeto, 0.0, 1.0, 0.0);
 glRotatef((GLfloat) eixozObjeto, 0.0, 0.0, 1.0);
 
 

//  glPushMatrix();
 
  /*parte da frentde do barquinho*/
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);// VERDE
  glVertex3f(15.0, 0.0,0.0);
  glVertex3f(5.0, 5.0,0.0);
  glVertex3f(40.0, 5.0,0.0);
  glVertex3f(30.0, 0.0,0.0);
  glEnd();
 
  /*parte de trás do barquinho*/
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);// AMARELO
  glVertex3f(15.0, 0.0,-10.0);
  glVertex3f(5.0, 5.0,-10.0);
  glVertex3f(40.0, 5.0,-10.0);
  glVertex3f(30.0, 0.0,-10.0);
  glEnd();
 
   /*parte de baixo do barquinho*/
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);// VERDE
  glVertex3f(15.0, 0.0,-10.0);
  glVertex3f(15.0, 0.0,0.0);
  glVertex3f(30.0, 0.0,0.0);
  glVertex3f(30.0, 0.0,-10.0);
  glEnd();
 
 
 /*parte esquerda do barquinho*/
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 1.0);// AZUL
  glVertex3f(15.0, 0.0,0.0);
  glVertex3f(15.0, 0.0,-10.0);
  glVertex3f(5.0, 5.0,-10.0);
  glVertex3f(5.0, 5.0,0.0);
  glEnd();

 
 /*parte direita do barquinho*/
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);//
  glVertex3f(30.0, 0.0,0.0);
  glVertex3f(30.0, 0.0,-10.0);
  glVertex3f(40.0, 5.0,-10.0);
  glVertex3f(40.0, 5.0,0.0);
  glEnd();
 
/**************************PARTE DO SALVA VIDAS**************************************/

   /* PRIMEIRO salva Vidas do barquinho*/
   glPushMatrix();
        glColor3f (1.5, 0.5, 0.5);// NAO SEI Q COR EH ESSA
        glTranslated(15.0,3.5,-6);
        glutSolidTorus(0.5,1,20,20);
    glPopMatrix();
    
    /* SEGUNDO salva Vidas do barquinho*/
   glPushMatrix();
        glColor3f (1.5, 0.5, 0.5);// NAO SEI Q COR EH ESSA
        glTranslated(20.0,3.5,-6);
        glutSolidTorus(0.5,1,20,20);
    glPopMatrix();
    
    /* TERCEIRO salva Vidas do barquinho*/
   glPushMatrix();
        glColor3f (1.5, 0.5, 0.5);// NAO SEI Q COR EH ESSA
        glTranslated(25.0,3.5,-6);
        glutSolidTorus(0.5,1,20,20);
    glPopMatrix();
   
   /* QUARTO salva Vidas do barquinho*/
   glPushMatrix();
        glColor3f (1.5, 0.5, 0.5);// NAO SEI Q COR EH ESSA
        glTranslated(30.0,3.5,-6);
        glutSolidTorus(0.5,1,20,20);
    glPopMatrix();

  /*************************Mastro do barquinho***************************/
  glBegin(GL_LINES);
  glColor3f (0.0, 0.0, 0.0);// PRETO
  glVertex3f(23.0, 5.0,0.0);
  glVertex3f(23.0, 15.0,0.0);
  glEnd();
   

  /*************************Bandeirinha do barquinho********************************/
     glPushMatrix();
          glColor3f (0.5, 0.7, 1.0);
          glTranslatef(23.0,12.0,0.0);
          glRotatef(-270,0,1,0);
          glScalef(1.0,3.0,1.0);
          glutSolidCone(1.0,5.0, 15.0, 15.0);        
          glPopMatrix();
 
  /***************************desenho de mar*******************************************/
  glBegin(GL_LINE_STRIP);
  glColor3f (0.0, 0.0, 1.0);
      for (i = 0; i <= 30; i++)
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
  /* `mostragem dos pontos de controle  */
  glPointSize(5.0);
   glColor3f(0.0, 0.0, 1.0);
   
   glBegin(GL_POINTS);
      for (i = 0; i < 4; i++)
         glVertex3fv(&ctrlpoints[i][0]);
   glEnd();
   
   
  desenhaSol();
 
  glFlush();
  glutSwapBuffers();
}

/*Funcoes de teclado*/
void keyboard(unsigned char key, int x, int y) {
 switch (key) {
 case 27:
  exit(0);
  break;
 case 'y':
  eixoyObjeto = (eixoyObjeto - 5) % 360;
  break;
 case 'Y':
  eixoyObjeto = (eixoyObjeto + 5) % 360;
  break;
 case 'x':
  eixoxObjeto = (eixoxObjeto - 5) % 360;
  break;
 case 'X':
  eixoxObjeto = (eixoxObjeto + 5) % 360;
  break;
 case 'z':
  eixozObjeto = (eixozObjeto - 5) % 360;
  break;
 case 'Z':
  eixozObjeto = (eixozObjeto + 5) % 360;
  break;
 case 'r':    // resetando o objeto
  eixoxObjeto = 0;
  eixoyObjeto = 0;
  eixozObjeto = 0;
  break;
 case 'R':    // resetano o mundo
   eixoxMundo = 0;
  eixoyMundo = 0;
  eixozMundo = 0;
  break;
 case 'u':   // eixo X do observador
  eixoxMundo = (eixoxMundo - 5) % 360;
  break;
 case 'U':   // eixo X do observador aumenta
  eixoxMundo = (eixoxMundo + 5) % 360;
  break;
 case 'i':  //  eixo y observador
  eixoyMundo = (eixoyMundo - 5) % 360;
  break;
 case 'I': // eixo y observador aumenta
  eixoyMundo = (eixoyMundo + 5) % 360;
  break;
 case 'o': // eixo Z observador
  eixozMundo = (eixozMundo - 5) % 360;
  break;
 case 'O': // eixo Z observador aumenta
  eixozMundo = (eixozMundo + 5) % 360;
  break;
 case 'l':
  glEnable(GL_LIGHTING);
  break;
 case 'L':
  glDisable(GL_LIGHTING);
  break;
 }
 glutPostRedisplay();
}

/*teclas especiais*/
void special(int key, int x, int y){
switch (key) {
  case GLUT_KEY_UP:
    glTranslatef (0.0, 0.5, 0.0);
    break;
  case GLUT_KEY_DOWN:
    glTranslatef (0.0, -0.5, 0.0);
    break;
  case GLUT_KEY_LEFT:
    glTranslatef (-0.5, 0.0, 0.0);
    break;
  case GLUT_KEY_RIGHT:
    glTranslatef (0.5, 0.0, 0.0);
    break;
  case GLUT_KEY_PAGE_UP:
    glTranslatef (0.0, 0.0, 0.5);
    break;
  case GLUT_KEY_PAGE_DOWN:
    glTranslatef (0.0, 0.0, -0.5);
    break;
  }
  glutPostRedisplay();
}
