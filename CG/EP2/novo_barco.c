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
#include "image.h"
#include "image.c"
#include "defines.h"
#include "model.c"

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void reshape(int w, int h);
void special(int, int, int);
void rotacaoCamX( GLfloat );
void rotacaoCamY( GLfloat );
void rotacaoCamZ( GLfloat );
void printBarco(void);
void printEixos(void);
void carregar_texturas(void);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

void init(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClearDepth(1.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
	
    carregar_texturas();
}

void carrega_luzes() {
    
	GLfloat ambientLight[] = {0.6, 0.6, 0.6, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	
    glLightfv(GL_LIGHT0, GL_AMBIENT, l1ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, l1diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, l1position);
    glLightfv(GL_LIGHT0, GL_COLOR, l1cor);
    
    GLfloat solAmb[] = {AMARELO, 1.0};
    GLfloat solDiffuse[] = {AMARELO, 1.0};
    GLfloat solCor[] = {AMARELO, 1.0};
    GLfloat solPos[] = {-5.0, 4.0, -5.0};
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, solAmb);
    glLightfv(GL_LIGHT1, GL_SPECULAR, solDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, solPos);
    glLightfv(GL_LIGHT1, GL_COLOR, solCor);
    
    glEnable(GL_LIGHTING);
    
    if(luzes) {
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
    } else {
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
    }
    
    glEnable(GL_COLOR_MATERIAL);
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
    
    if(texturas) {
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    } else
        glDisable(GL_TEXTURE_2D);
    
    carrega_luzes();
    //printEixos();

    if(anima) {
        contador += ammount;
        if((contador %  10) == 0) {
            z_amm *= -1;
        }
        eZObj += z_amm;
    }
    glPushMatrix();
	
	    glRotatef((GLfloat) eXObj, 1.0, 0.0, 0.0);
	    glRotatef((GLfloat) eYObj, 0.0, 1.0, 0.0);
	    glRotatef((GLfloat) eZObj, 0.0, 0.0, 1.0); 

        glColor3f(BRANCO);
        glTranslatef(posXObj, posYObj -0.05, posZObj);
        printBarco();
        
    glPopMatrix();
    
    glPushMatrix();
         GLfloat mat_ambient[]= { CEU, 0.7 };
         GLfloat mat_diffuse[]= { CEU, 0.7 };
         GLfloat mat_specular[]= { CEU, 0.4 };
         GLfloat mat_shininess[]= { 1.0f };
        
         glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
         glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
         glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
         glMaterialfv (GL_FRONT, GL_SHININESS, mat_shininess); 
         
         GLUquadricObj*  q = gluNewQuadric ( );
        gluQuadricDrawStyle ( q, GLU_FILL   );
        gluQuadricNormals   ( q, GLU_SMOOTH );
        gluQuadricTexture   ( q, GL_TRUE    );
        gluSphere ( q, 25, 50, 20 );           // 5 é o raio
        gluDeleteQuadric ( q ); 
    glPopMatrix();
    
    glPushMatrix();
         GLfloat solColor[] = {AMARELO, 1.0};
         GLfloat solSpecular[] = {AMARELO, 1.0};
     
         glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, solColor);
	     glMaterialfv(GL_FRONT, GL_SPECULAR, solSpecular);

         glTranslatef(-5.0, 4.0, -5.0);
         gluSphere(gluNewQuadric(), 0.7, 10, 15);
    glPopMatrix();
    
    glBegin(GL_QUADS);
        glColor3f(AZUL);
        glTexCoord3fv(ctp[0]);  
        glVertex3f(-30,-0.2,60);
        glTexCoord3fv(ctp[1]);  
        glVertex3f(30,-0.2,60);
        glTexCoord3fv(ctp[2]);  
        glVertex3f(30,-0.2,-60);
        glTexCoord3fv(ctp[3]);  
        glVertex3f(-30,-0.2,-60);
    glEnd();
        
	glutSwapBuffers();

}

void atualizaCam()
{
    glLoadIdentity();
    gluLookAt(posXCam, posYCam, posZCam, posXObj, posYObj, posZObj, 0, 1, 0);
}

void carregar_texturas(){
    IMAGE *img;
    GLenum gluerr;

    /* textura do plano */
    glGenTextures(1, &textura_plano);
    glBindTexture(GL_TEXTURE_2D, textura_plano);

    if(!(img=ImageLoad(TEXTURA_MAR))) {
    fprintf(stderr,"Error reading a texture.\n");
    exit(-1);
    }

    gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 
		       img->sizeX, img->sizeY, 
		       GL_RGB, GL_UNSIGNED_BYTE, 
		       (GLvoid *)(img->data));
    if(gluerr){
    fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
    exit(-1);
    }
    
    
    glGenTextures( 1, &textura_sphere );
    glBindTexture( GL_TEXTURE_2D, textura_sphere );
    img = ImageLoad( "sky.rgb" );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, img->sizeX, img->sizeY, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid *)(img->data) );

     glBindTexture( GL_TEXTURE_2D, textura_sphere );
     glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
    
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

    case 'q':
        if(!luzes)
            luzes = 1;
        else
            luzes = 0;
        break;
    case 'a':
        if(!anima)
            anima = 1;
        else
            anima = 0;
        break;
    case 't':
        if(!texturas)
            texturas = 1;
        else
            texturas = 0;
        break;
	}

	glutPostRedisplay();
    atualizaCam();
}
