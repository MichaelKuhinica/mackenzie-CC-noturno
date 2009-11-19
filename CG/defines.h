
#define BRANCO   1.0, 1.0, 1.0
#define PRETO    0.0, 0.0, 0.0
#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define AMARELO_C  0.4, 0.4, 0.0
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
#define COORD_TEXTURA_PLANO 0.0
#define TEXTURA_MAR "ocean.rgb"
#define COR_MAR 0.3,0.52,0.18,1.0
#define CEU 0.50, 1.53, 1.21

#define PI 3.1415

int contador = 0;
int ammount = 1;
float z_amm = 1;

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

int luzes = 1;
int anima = 0;

GLuint  textura_plano;

GLshort texturas=0;

GLfloat ctp[4][2]={
  {-1.0, -1.0},
  {1.0, -1.0},
  {1.0, 1.0},
  {-1.0, 1.0}
};

GLfloat l1ambient[] = {0.4, 0.4, 0.4, 1.0};
GLfloat l1diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat l1position[] = {-5.0, 5.0, 0.0, 1.0};
GLfloat l1cor[] = {0.0, 1.0, 1.0, 1.0};

GLfloat materialColor[] = {0.2f, 0.2f, 1.0f, 1.0f};
GLfloat materialSpecular[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat materialEmission[] = {0.7f, 0.7f, 0.7f, 1.0f};
