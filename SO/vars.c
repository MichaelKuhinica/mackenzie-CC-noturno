
typedef struct {
    int cimento;
    int tijolos;
    int numero;
    int pronta;
} casa_struct;

typedef struct {
    int cimento;
    int tijolos;
    int casa;
    int numero;
} pedreiro_struct;

//variaveis obrigatorias do exercicio
static int C=3;                         //indica o numero de casas
static int P=2;                            //indica o numero de pedreiros
static int Cc=10;                        //indica quantos quilos de cimento cada casa precisa
static int Ct=20;                        //indica quantos tijolos para a contrução de cada casas
static int Pc=5;                        //indica quantos quilos de cimento o peao pode carregar
static int Ptc=1;                       //indica quanto tempo para colocar Pc no carrinho
static int Pt=10;                        //indica quantos tijolos o peao consegue carregar
static int Ptt=1;                       //indica quanto tempo demora para colocar Pt no carrinho
static int Pts=3;                       // quanto tempo o pedreiro demora trabalhando

int estoque_tijolos;
int estoque_cimento; 

pthread_mutex_t m_tijolos = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m_cimento = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t *m_casas;

pthread_t *t_pedreiros;

casa_struct *casas;
pedreiro_struct *pedreiros;


