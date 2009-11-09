/**************************
Ariane Moreira de Oliveira Gouveia
TIA: 306.3942-5
Michael Martins Kuhinica
TIA: 306.5363-0
Curso: Ciência da Computação - Noturno - 5N
Projeto 1 - Computação Gráfica.
**************************/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define BRANCO   1.0, 1.0, 1.0
#define PRETO    0.0, 0.0, 0.0
#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6
#define CINZA_A  0.95, 0.95, 0.95
#define CINZA_B  0.85, 0.85, 0.85
#define CINZA_C  0.7, 0.7, 0.7
#define CINZA_D  0.5, 0.5, 0.5
#define CINZA_E  0.2, 0.2, 0.2

#define PI 3.1415
#define STARS 1000

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void reshape(int w, int h);
void special(int, int, int);
void rotacaoCamX( GLfloat );
void rotacaoCamY( GLfloat );
void rotacaoCamZ( GLfloat );
void printBarco(void);

int eYObj = 0,
	eXObj = 0,
	eZObj = 0;

int eYMundo = 0,
	eXMundo = 0,
	eZMundo = 0;

GLfloat posXObj = 0.0,
		posYObj = 0.0,
		posZObj = 0.0;

GLfloat posXCam = 1.0,
		posYCam = 1.0,
		posZCam = 1.0;

GLfloat anguloYCam = 0.0,
		anguloXCam = 0.0,
		anguloZCam = 0.0;

int width, height;

GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]= { 0.0f, 0.0f, -7.0f, 1.0f };
float estrelas[STARS][3];

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

void init(void) {

    srand(time(NULL));

    int i;
    for(i=0; i<STARS; i++) {
        estrelas[i][0] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	    estrelas[i][1] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	    estrelas[i][2] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
    }

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
}


void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	width = w;
	height = h;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0, (GLfloat) width / (GLfloat) height, 1.0, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(posXCam, posYCam, posZCam, 0, 0, 0, 0, 1, 0);
}

void display(void) {
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(AZUL);  // desenhando o plano Y
	glBegin(GL_LINES);
		glVertex3f(0.0, -30.0, 0.0);
		glVertex3f(0.0, 30.0, 0.0);
	glEnd();

	glColor3f(VERMELHO);  // desenhando o plano X
	glBegin(GL_LINES);
		glVertex3f(-30.0, 0.0, 0.0);
		glVertex3f(30.0, 0.0, 0.0);
	glEnd();

	glColor3f(AMARELO);  // desenhando o plano Z
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, -30.0);
		glVertex3f(0.0, 0.0, 30.0);
	glEnd();

    glPushMatrix();
		glLoadIdentity();
		glTranslatef(6.0, 5.0, -10.0);
		glRotatef((GLfloat) eYObj, 0.0, 1.0, 0.0);
		glRotatef((GLfloat) eXObj, 1.0, 0.0, 0.0);
		glRotatef((GLfloat) eZObj, 0.0, 0.0, 1.0);

		glColor3f(AZUL);  // desenhando o plano Y
		glBegin(GL_LINES);
			glVertex3f(0.0, -1.0, 0.0);
			glVertex3f(0.0, 1.0, 0.0);
		glEnd();

		glPushMatrix();  // quadradinho do positivo
			glTranslatef(0.0, 1.0, 0.0);
			glutSolidCube(0.09);
		glPopMatrix();

		glColor3f(VERMELHO);  // desenhando o plano X
		glBegin(GL_LINES);
			glVertex3f(-1.0, 0.0, 0.0);
			glVertex3f(1.0, 0.0, 0.0);
		glEnd();

		glPushMatrix();  // quadradinho do positivo
			glTranslatef(1.0, 0.0, 0.0);
			glutSolidCube(0.09);
		glPopMatrix();

		glColor3f(AMARELO);  // desenhando o plano Z
		glBegin(GL_LINES);
			glVertex3f(0.0, 0.0, -1.0);
			glVertex3f(0.0, 0.0, 1.0);
		glEnd();

		glPushMatrix();   // quadradinho do positivo
			glTranslatef(0.0, 0.0, -1.0);
			glutSolidCube(0.09);
		glPopMatrix();

	glPopMatrix();  // 	fim - desenhando o plano auxiliar no canto da tela


    glPushMatrix();
	
	    glRotatef((GLfloat) eXObj, 1.0, 0.0, 0.0);
	    glRotatef((GLfloat) eYObj, 0.0, 1.0, 0.0);
	    glRotatef((GLfloat) eZObj, 0.0, 0.0, 1.0); 

        glColor3f(BRANCO);
            
        printBarco();
        
    glPopMatrix();
    
	glutSwapBuffers();

}

void atualizaCam()
{
    glLoadIdentity();
    gluLookAt(posXCam, posYCam, posZCam, posXObj, posYObj, posZObj, 0, 1, 0);
}


void special(int key, int x, int y) {
    switch(key){

	case GLUT_KEY_LEFT:
		posXObj -= 0.1;
		break;
	case GLUT_KEY_RIGHT:
		posXObj += 0.1;
		break;
	case GLUT_KEY_UP:
		posZObj -= 0.1;
		break;
	case GLUT_KEY_DOWN:
		posZObj += 0.1;
		break;
	case GLUT_KEY_PAGE_UP:
		posYObj += 0.1;
		break;
	case GLUT_KEY_PAGE_DOWN:
		posYObj -= 0.1;
		break;
	}

	glutPostRedisplay();
	atualizaCam();
	glutPostRedisplay();
}

void rotacaoCamY( GLfloat anguloY ){

	posXCam = ( posXCam * cos(anguloY) ) + ( posZCam * sin(anguloY) );
	posYCam = posYCam;
	posZCam = ( posZCam * cos(anguloY) ) - ( posXCam * sin(anguloY) );

}

void rotacaoCamZ( GLfloat anguloZ ){

	posXCam = ( posXCam * cos(anguloZ) ) - ( posYCam * sin(anguloZ) );
	posYCam = ( posYCam * cos(anguloZ) ) + ( posXCam * sin(anguloZ) );
	posZCam = posZCam;

}

void rotacaoCamX( GLfloat anguloX ){

	posXCam = posXCam;
	posYCam = ( posYCam * cos(anguloX) ) - ( posZCam * sin(anguloX) );
	posZCam = ( posYCam * sin(anguloX) ) + ( posZCam * cos(anguloX) );


}


void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 'y':
		eYObj = (eYObj - 5) % 360;
		break;
	case 'Y':
		eYObj = (eYObj + 5) % 360;
		break;
	case 'x':
		eXObj = (eXObj - 5) % 360;
		break;
	case 'X':
		eXObj = (eXObj + 5) % 360;
		break;
	case 'z':
		eZObj = (eZObj - 5) % 360;
		break;
	case 'Z':
		eZObj = (eZObj + 5) % 360;
		break;
	case 'r':    // resetando o Obj
		eXObj = 0;
		eYObj = 0;
		eZObj = 0;
		break;
	case 'R':    // resetano o mundo
 		eXMundo = 0;
		eYMundo = 0;
		eZMundo = 0;
		break;
	case 'u':   // e X do observador
		posXCam = (posXCam - 1);
        atualizaCam();
		break;
	case 'U':   // e X do observador aumenta
		posXCam = (posXCam + 1);
        atualizaCam();
        break;
	case 'i':  //  e y observador
		posYCam = (posYCam - 1);
        atualizaCam();
		break;
	case 'I': // e y observador aumenta
		posYCam = (posYCam + 1);
        atualizaCam();
		break;
	case 'o': // e Z observador
		posZCam = (posZCam - 1);
        atualizaCam();
		break;
	case 'O': // e Z observador aumenta
		posZCam = (posZCam + 1);
        atualizaCam();
		break;

	case 'j':
		rotacaoCamX(-0.01);
		break;
	case 'J':
		rotacaoCamX(0.01);
		break;
	case 'k':
		rotacaoCamY(-0.01);
		break;
	case 'K':
		rotacaoCamY(0.01);
		break;
	case 'l':
		rotacaoCamZ(-0.01);
		break;
	case 'L':
		rotacaoCamZ(0.01);
		break;


	}

	glutPostRedisplay();
    atualizaCam();
}

void printBarco(void) {
    glPushMatrix();
    
        //Melhorando tamanho do barco
        glScalef(2.0, 2.0, 2.0);
        /* CASCO */
        glColor3f(AZUL);
        glBegin(GL_POLYGON);
	        glVertex3f(-0.220890, -0.163880, 0.002740);
	        glVertex3f(-0.530390, -0.021360, 0.125720);
	        glVertex3f(-0.530390, -0.021360, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(0.040770, -0.163880, 0.002740);
	        glVertex3f(0.350270, -0.021360, 0.125720);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.040770, -0.163880, 0.002740);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(0.350270, -0.021360, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.040770, -0.163880, 0.002740);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(0.469610, -0.006550, 0.000390);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(0.040770, -0.163880, 0.002740);
	        glVertex3f(0.469610, -0.006550, 0.000390);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(0.469610, -0.006550, 0.000390);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(0.469610, -0.006550, 0.000390);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(-0.530390, -0.021360, -0.126300);
	        glVertex3f(-0.530390, 0.003040, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(-0.530390, 0.003040, -0.126300);
	        glVertex3f(0.350270, 0.003040, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, -0.021360, 0.125720);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(0.350270, 0.003040, 0.125720);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, -0.021360, 0.125720);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(-0.530390, 0.003040, 0.125720);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, -0.021360, -0.126300);
	        glVertex3f(-0.530390, -0.021360, 0.125720);
	        glVertex3f(-0.530390, 0.003040, 0.125720);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, -0.021360, -0.126300);
	        glVertex3f(-0.530390, 0.003040, 0.125720);
	        glVertex3f(-0.530390, 0.003040, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(0.040770, -0.163880, 0.002740);
	        glVertex3f(-0.530390, -0.021360, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.040770, -0.163880, 0.002740);
	        glVertex3f(-0.220890, -0.163880, 0.002740);
	        glVertex3f(-0.530390, -0.021360, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.040770, -0.163880, 0.002740);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(-0.220890, -0.163880, 0.002740);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(-0.530390, -0.021360, 0.125720);
	        glVertex3f(-0.220890, -0.163880, 0.002740);
        glEnd();
        /* FIM - CASCO */
        
        /* CABINE */
        
        glColor3f(AMARELO);
        glBegin(GL_POLYGON);
	        glVertex3f(0.269530, 0.003040, 0.068660);
	        glVertex3f(0.269530, 0.003040, -0.069250);
	        glVertex3f(0.144730, 0.108010, -0.069250);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.144730, 0.108010, -0.069250);
	        glVertex3f(-0.449650, 0.108010, -0.069250);
	        glVertex3f(0.144730, 0.108010, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.449650, 0.108010, -0.069250);
	        glVertex3f(-0.449650, 0.108010, 0.068660);
	        glVertex3f(0.144730, 0.108010, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.269530, 0.003040, 0.068660);
	        glVertex3f(0.144730, 0.108010, -0.069250);
	        glVertex3f(0.144730, 0.108010, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.269530, 0.003040, -0.069250);
	        glVertex3f(-0.449650, 0.003040, -0.069250);
	        glVertex3f(0.144730, 0.108010, -0.069250);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.449650, 0.003040, -0.069250);
	        glVertex3f(-0.449650, 0.108010, -0.069250);
	        glVertex3f(0.144730, 0.108010, -0.069250);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.449650, 0.003040, 0.068660);
	        glVertex3f(0.269530, 0.003040, 0.068660);
	        glVertex3f(0.144730, 0.108010, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.449650, 0.003040, 0.068660);
	        glVertex3f(0.144730, 0.108010, 0.068660);
	        glVertex3f(-0.449650, 0.108010, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.449650, 0.003040, -0.069250);
	        glVertex3f(-0.449650, 0.003040, 0.068660);
	        glVertex3f(-0.449650, 0.108010, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.449650, 0.003040, -0.069250);
	        glVertex3f(-0.449650, 0.108010, 0.068660);
	        glVertex3f(-0.449650, 0.108010, -0.069250);
        glEnd();
        
        /* FIM - CABINE */
        
        /* PROA */   
        
        glColor3f(VERMELHO);
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, 0.003040, -0.126300);
	        glVertex3f(-0.530390, 0.003040, 0.125720);
	        glVertex3f(-0.449650, 0.003040, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, 0.003040, -0.126300);
	        glVertex3f(-0.449650, 0.003040, 0.068660);
	        glVertex3f(-0.449650, 0.003040, -0.069250);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, 0.003040, 0.125720);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(-0.449650, 0.003040, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.269530, 0.003040, 0.068660);
	        glVertex3f(-0.449650, 0.003040, 0.068660);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(-0.530390, 0.003040, -0.126300);
	        glVertex3f(0.269530, 0.003040, -0.069250);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.530390, 0.003040, -0.126300);
	        glVertex3f(-0.449650, 0.003040, -0.069250);
	        glVertex3f(0.269530, 0.003040, -0.069250);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(0.269530, 0.003040, -0.069250);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.269530, 0.003040, -0.069250);
	        glVertex3f(0.269530, 0.003040, 0.068660);
        glEnd();
         glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.469610, -0.006550, 0.000390);
        glEnd();    
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(0.350270, -0.021360, 0.125720);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.350270, -0.021360, 0.125720);
	        glVertex3f(0.350270, 0.003040, 0.125720);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(0.350270, 0.003040, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, -0.021360, -0.126300);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(0.350270, -0.021360, -0.126300);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.350270, 0.003040, 0.125720);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.350270, 0.003040, -0.126300);
	        glVertex3f(0.350270, 0.003040, 0.125720);
	        glVertex3f(0.350270, 0.003040, -0.126300);
        glEnd();
        
        /* FIM - PROA */      
    glPopMatrix();
    
    //Deixo as janelas separadas pois Disks são mais faceis de se trabalhar deste tamanho
    /* JANELAS */   
    
    glPushMatrix();
        glTranslatef(0.2, 0.13, -0.14);
        glColor3f(VERDE);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0.13, -0.14);
        glColor3f(VERDE);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();
           
    glPushMatrix();
        glTranslatef(-0.6, 0.13, -0.14);
        glColor3f(VERDE);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0.2, 0.13, 0.14);
        glColor3f(VERDE);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0.13, 0.14);
        glColor3f(VERDE);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.6, 0.13, 0.14);
        glColor3f(VERDE);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix(); 
        
    /* FIM - JANELAS */
    
}

