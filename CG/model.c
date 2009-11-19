void printBarco(void) {
    glPushMatrix();
    
        //Melhorando tamanho do barco
        glScalef(2.0, 2.0, 2.0);
        /* CASCO */
        glColor3f(CINZA_E);
        glBegin(GL_POLYGON);
	        glVertex3f(-0.22, -0.16, 0.00);
	        glVertex3f(-0.53, -0.02, 0.12);
	        glVertex3f(-0.53, -0.02, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(0.04, -0.16, 0.00);
	        glVertex3f(0.35, -0.02, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.04, -0.16, 0.00);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(0.35, -0.02, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.04, -0.16, 0.00);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(0.46, -0.00, 0.00);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(0.04, -0.16, 0.00);
	        glVertex3f(0.46, -0.00, 0.00);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(0.46, -0.00, 0.00);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(0.46, -0.00, 0.00);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(-0.53, -0.02, -0.12);
	        glVertex3f(-0.53, 0.00, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(-0.53, 0.00, -0.12);
	        glVertex3f(0.35, 0.00, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, -0.02, 0.12);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(0.35, 0.00, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, -0.02, 0.12);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(-0.53, 0.00, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, -0.02, -0.12);
	        glVertex3f(-0.53, -0.02, 0.12);
	        glVertex3f(-0.53, 0.00, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, -0.02, -0.12);
	        glVertex3f(-0.53, 0.00, 0.12);
	        glVertex3f(-0.53, 0.00, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(0.04, -0.16, 0.00);
	        glVertex3f(-0.53, -0.02, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.04, -0.16, 0.00);
	        glVertex3f(-0.22, -0.16, 0.00);
	        glVertex3f(-0.53, -0.02, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.04, -0.16, 0.00);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(-0.22, -0.16, 0.00);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(-0.53, -0.02, 0.12);
	        glVertex3f(-0.22, -0.16, 0.00);
        glEnd();
        /* FIM - CASCO */
        
        /* CABINE */
        
        glColor3f(PRETO);
        glBegin(GL_POLYGON);
	        glVertex3f(0.26, 0.00, 0.06);
	        glVertex3f(0.26, 0.00, -0.06);
	        glVertex3f(0.14, 0.10, -0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.14, 0.10, -0.06);
	        glVertex3f(-0.44, 0.10, -0.06);
	        glVertex3f(0.14, 0.10, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.44, 0.10, -0.06);
	        glVertex3f(-0.44, 0.10, 0.06);
	        glVertex3f(0.14, 0.10, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.26, 0.00, 0.06);
	        glVertex3f(0.14, 0.10, -0.06);
	        glVertex3f(0.14, 0.10, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.26, 0.00, -0.06);
	        glVertex3f(-0.44, 0.00, -0.06);
	        glVertex3f(0.14, 0.10, -0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.44, 0.00, -0.06);
	        glVertex3f(-0.44, 0.10, -0.06);
	        glVertex3f(0.14, 0.10, -0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.44, 0.00, 0.06);
	        glVertex3f(0.26, 0.00, 0.06);
	        glVertex3f(0.14, 0.10, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.44, 0.00, 0.06);
	        glVertex3f(0.14, 0.10, 0.06);
	        glVertex3f(-0.44, 0.10, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.44, 0.00, -0.06);
	        glVertex3f(-0.44, 0.00, 0.06);
	        glVertex3f(-0.44, 0.10, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.44, 0.00, -0.06);
	        glVertex3f(-0.44, 0.10, 0.06);
	        glVertex3f(-0.44, 0.10, -0.06);
        glEnd();
        
        /* FIM - CABINE */
        
        /* PROA */   
        
        glColor3f(CINZA_C);
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, 0.00, -0.12);
	        glVertex3f(-0.53, 0.00, 0.12);
	        glVertex3f(-0.44, 0.00, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, 0.00, -0.12);
	        glVertex3f(-0.44, 0.00, 0.06);
	        glVertex3f(-0.44, 0.00, -0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, 0.00, 0.12);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(-0.44, 0.00, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.26, 0.00, 0.06);
	        glVertex3f(-0.44, 0.00, 0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(-0.53, 0.00, -0.12);
	        glVertex3f(0.26, 0.00, -0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(-0.53, 0.00, -0.12);
	        glVertex3f(-0.44, 0.00, -0.06);
	        glVertex3f(0.26, 0.00, -0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(0.26, 0.00, -0.06);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.26, 0.00, -0.06);
	        glVertex3f(0.26, 0.00, 0.06);
        glEnd();
         glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.46, -0.00, 0.00);
        glEnd();    
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(0.35, -0.02, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.35, -0.02, 0.12);
	        glVertex3f(0.35, 0.00, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(0.35, 0.00, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, -0.02, -0.12);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(0.35, -0.02, -0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.35, 0.00, 0.12);
        glEnd();
        glBegin(GL_POLYGON);
	        glVertex3f(0.35, 0.00, -0.12);
	        glVertex3f(0.35, 0.00, 0.12);
	        glVertex3f(0.35, 0.00, -0.12);
        glEnd();
        /* FIM - PROA */      
    glPopMatrix();
    
    //Deixo as janelas separadas pois Disks são mais faceis de se trabalhar deste tamanho
    /* JANELAS */   
    glColor4f(AMARELO_C, 0.7);
    glPushMatrix();
        glTranslatef(0.2, 0.13, -0.125);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0.13, -0.125);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();
           
    glPushMatrix();
        glTranslatef(-0.6, 0.13, -0.125);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0.2, 0.13, 0.125);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.2, 0.13, 0.125);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.6, 0.13, 0.125);
        gluDisk( gluNewQuadric() , 0 , 0.07, 18, 5);
    glPopMatrix(); 
        
    /* FIM - JANELAS */
    
}


void printEixos() {
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

}
