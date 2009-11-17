
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
static int C=10;                         //indica o numero de casas
static int P=3;                         //indica o numero de pedreiros
static int Cc=100;                        //indica quantos quilos de cimento cada casa precisa
static int Ct=200;                        //indica quantos tijolos para a contrução de cada casas
static int Pc=5;                        //indica quantos quilos de cimento o peao pode carregar
static int Ptc=2;                       //indica quanto tempo para colocar Pc no carrinho
static int Pt=10;                        //indica quantos tijolos o peao consegue carregar
static int Ptt=5;                       //indica quanto tempo demora para colocar Pt no carrinho

pthread_mutex_t m_tijolos = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m_cimento = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t *m_casas;

pthread_t *t_pedreiros;

casa_struct *casas;
pedreiro_struct *pedreiros;


