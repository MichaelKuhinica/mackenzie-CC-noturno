//============================================================================
// Name        : 1.cpp
// Author      : Fernando Pazin TIA 40642550
// Author      : Felipe Brandao TIA 40609804
//============================================================================

#include <iostream>
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
#define VAGOES   3
#define PI 3.1415


using namespace std;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);
void teclaEspecial(int key, int x, int y);
void rotacaoCameraX( GLfloat anguloX );
void rotacaoCameraY( GLfloat anguloY );
void rotacaoCameraZ( GLfloat anguloZ );


void atualizaCamera();

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     0.0, 1.0, 1.0


int eixoyObjeto = 0,
	eixoxObjeto = 0,
	eixozObjeto = 0;

int eixoyMundo = 0,
	eixoxMundo = 0,
	eixozMundo = 0;

GLfloat posXObjeto = 0.0,
		posYObjeto = 0.0,
		posZObjeto = 0.0;

GLfloat posXCamera = 1.0,
		posYCamera = 1.0,
		posZCamera = 10.0;

GLfloat anguloYCamera = 0.0,
		anguloXCamera = 0.0,
		anguloZCamera = 0.0;

int largura, altura;


float objeto1[3] = {0,0,0};
float objeto2[3] = {0,0,0};
float objeto3[3] = {0,0,0};
float objeto4[3] = {0,0,0};


GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]= { 0.0f, 0.0f, -7.0f, 1.0f };



int main(int argc, char** argv) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(teclaEspecial);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

void init(void) {

	srand(time(NULL));

	// posições iniciais das bolinhas
	objeto1[0] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto1[1] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto1[2] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );

	objeto2[0] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto2[1] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto2[2] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );

	objeto3[0] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto3[1] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto3[2] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );

	objeto4[0] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto4[1] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );
	objeto4[2] = (rand() % 5) + 1 * ( pow( -1 , rand() % 3 + 1) );

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);


	// tentando iluminar pra ver o que to errando
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);
	glEnable(GL_LIGHT1);



}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	largura = w;
	altura = h;

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0, (GLfloat) largura / (GLfloat) altura, 1.0, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(posXCamera, posYCamera, posZCamera, 0, 0, 0, 0, 1, 0);

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


	// desenhando as bolinhas...
	glPushMatrix();
		glColor3f(AZUL);
		glTranslatef(objeto1[0], objeto1[1], objeto1[2]);
		glutSolidSphere(0.1, 8, 5);
	glPopMatrix();

	glPushMatrix();
		glColor3f(VERMELHO);
		glTranslatef(objeto2[0], objeto2[1], objeto2[2]);
		glutSolidSphere(0.1, 8, 5);
	glPopMatrix();

	glPushMatrix();
		glColor3f(VERDE);
		glTranslatef(objeto3[0], objeto3[1], objeto3[2]);
		glutSolidSphere(0.1, 8, 5);
	glPopMatrix();

	glPushMatrix();
		glColor3f(CYAN);
		glTranslatef(objeto4[0], objeto4[1], objeto4[2]);
		glutSolidSphere(0.1, 8, 5);
	glPopMatrix();
	// fim - desenhando as bolinhas...



	// desenhando o plano auxiliar no canto da tela
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(6.0, 5.0, -10.0);
		glRotatef((GLfloat) eixoyObjeto, 0.0, 1.0, 0.0);
		glRotatef((GLfloat) eixoxObjeto, 1.0, 0.0, 0.0);
		glRotatef((GLfloat) eixozObjeto, 0.0, 0.0, 1.0);

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




	// Navezinha simplista
	glPushMatrix();

		glTranslatef( posXObjeto, posYObjeto, posZObjeto );

		glRotatef((GLfloat) eixoxObjeto, 1.0, 0.0, 0.0);
		glRotatef((GLfloat) eixoyObjeto, 0.0, 1.0, 0.0);
		glRotatef((GLfloat) eixozObjeto, 0.0, 0.0, 1.0);

		glColor3f(AZUL);
		glBegin(GL_POLYGON);
			glVertex3f(0.0, 0.75, 0.0);
			glVertex3f(-1.0, -0.25, 0.0);
			glVertex3f(1.0, -0.25, 0.0);
		glEnd();

		glColor3f(VERMELHO);
		glBegin(GL_POLYGON);
			glVertex3f(0.0, 0.75, 0.0);
			glVertex3f(0.0, -0.25, 1.0);
			glVertex3f(-1.0, -0.25, 0.0);
		glEnd();

		glColor3f(AMARELO);
		glBegin(GL_POLYGON);
			glVertex3f(0.0, 0.75, 0.0);
			glVertex3f(1.0, -0.25, 0.0);
			glVertex3f(0.0, -0.25, 1.0);
		glEnd();

		glColor3f(VERDE);
		glBegin(GL_POLYGON);
			glVertex3f(1.0, -0.25, 0.0);
			glVertex3f(-1.0, -0.25, 0.0);
			glVertex3f(0.0, -0.25, 1.0);
		glEnd();

	glPopMatrix();



	glutSwapBuffers();

}

void atualizaCamera()
{
    glLoadIdentity();
    gluLookAt(posXCamera, posYCamera, posZCamera, posXObjeto, posYObjeto, posZObjeto, 0, 1, 0);
}

void teclaEspecial(int key, int x, int y) {

	switch(key){

	case GLUT_KEY_LEFT:
		posXObjeto -= 0.1;
		break;
	case GLUT_KEY_RIGHT:
		posXObjeto += 0.1;
		break;
	case GLUT_KEY_UP:
		posZObjeto -= 0.1;
		break;
	case GLUT_KEY_DOWN:
		posZObjeto += 0.1;
		break;
	case GLUT_KEY_PAGE_UP:
		posYObjeto += 0.1;
		break;
	case GLUT_KEY_PAGE_DOWN:
		posYObjeto -= 0.1;
		break;
	}

	glutPostRedisplay();
	atualizaCamera();
	glutPostRedisplay();
}


void rotacaoCameraY( GLfloat anguloY ){

	//angulo Y
	printf(" %f \n ", anguloY);
	printf("x %f y %f z %f \n", posXCamera, posYCamera, posZCamera);

	posXCamera = ( posXCamera * cos(anguloY) ) + ( posZCamera * sin(anguloY) );
	posYCamera = posYCamera;
	posZCamera = ( posZCamera * cos(anguloY) ) - ( posXCamera * sin(anguloY) );

	printf("x %f y %f z %f \n", posXCamera, posYCamera, posZCamera);
}

void rotacaoCameraZ( GLfloat anguloZ ){

	//angulo Z
	printf(" %f \n ", anguloZ);
	printf("x %f y %f z %f \n", posXCamera, posYCamera, posZCamera);

	posXCamera = ( posXCamera * cos(anguloZ) ) - ( posYCamera * sin(anguloZ) );
	posYCamera = ( posYCamera * cos(anguloZ) ) + ( posXCamera * sin(anguloZ) );
	posZCamera = posZCamera;

	printf("x %f y %f z %f \n", posXCamera, posYCamera, posZCamera);
}

void rotacaoCameraX( GLfloat anguloX ){

	//angulo X
	printf(" %f \n ", anguloX);
	printf("x %f y %f z %f \n", posXCamera, posYCamera, posZCamera);

	posXCamera = posXCamera;
	posYCamera = ( posYCamera * cos(anguloX) ) - ( posZCamera * sin(anguloX) );
	posZCamera = ( posYCamera * sin(anguloX) ) + ( posZCamera * cos(anguloX) );

	printf("x %f y %f z %f \n", posXCamera, posYCamera, posZCamera);

}


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
		posXCamera = (posXCamera - 1);
        atualizaCamera();
		break;
	case 'U':   // eixo X do observador aumenta
		posXCamera = (posXCamera + 1);
        atualizaCamera();
        break;
	case 'i':  //  eixo y observador
		posYCamera = (posYCamera - 1);
        atualizaCamera();
		break;
	case 'I': // eixo y observador aumenta
		posYCamera = (posYCamera + 1);
        atualizaCamera();
		break;
	case 'o': // eixo Z observador
		posZCamera = (posZCamera - 1);
        atualizaCamera();
		break;
	case 'O': // eixo Z observador aumenta
		posZCamera = (posZCamera + 1);
        atualizaCamera();
		break;

	case 'j':
		rotacaoCameraX(-0.01);
		break;
	case 'J':
		rotacaoCameraX(0.01);
		break;
	case 'k':
		rotacaoCameraY(-0.01);
		break;
	case 'K':
		rotacaoCameraY(0.01);
		break;
	case 'l':
		rotacaoCameraZ(-0.01);
		break;
	case 'L':
		rotacaoCameraZ(0.01);
		break;


	}

	glutPostRedisplay();
    atualizaCamera();	
}

