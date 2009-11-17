/*
  Diego Martins         TIA:3064296-5
  Michael Kuhinica          3065363-0
  Artur Machado             4068427-1
*/
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vars.c"

void inicia_threads(void);
void trabalha(void*);
void inicializa_casas();
void inicializa_pedreiros();
void print_pedreiro(pedreiro_struct*);

int rodando = 1;

int main(void) {
    /*printf("Numero de pedreiros: ");
    scanf("%d",&P);
    printf("Quantidade de casas a construir: ");
    scanf("%d",&C);
    printf("Cada casa precissa de quanto cimento? ");
    scanf("%d",&Cc);
    printf("Cada casa precisa de quantos tijolos? ");
    scanf("%d",&Ct);
    printf("Um peao carrega quanto de cimento? ");
    scanf("%d",&Pc);
    printf("Quantos segundos ele demora para carregar o carrinho de cimento? ");
    scanf("%d",&Ptc);
    printf("Um peao carrega quanto de tijolo? ");
    scanf("%d",&Pt);
    printf("Quantos segundos ele demora para carregar o carrinho de tijolos? ");
    scanf("%d",&Ptt); 
    */
    m_casas = (pthread_mutex_t *)malloc(C * sizeof(pthread_mutex_t));
    t_pedreiros = (pthread_t *)malloc(P * sizeof(pthread_t));
    casas = (casa_struct *)malloc(C * sizeof(casa_struct));
    pedreiros = (pedreiro_struct *)malloc(P * sizeof(pedreiro_struct));
    
    inicializa_casas();
    inicializa_pedreiros();
    
    int i;
    inicia_threads();
    system("clear");
    while(rodando == 1) {
        system("clear");
        
        for(i=0; i<P; i++) {
            print_pedreiro(&pedreiros[i]);
        }  
    }
    
    return 0;
}

void inicializa_casas() {
    int i;
    for(i=0; i<C; i++) {
        casas[i].cimento = 0;
        casas[i].tijolos = 0;
        casas[i].numero = i;
        casas[i].pronta = 0;
    }
}

void inicializa_pedreiros() {
    int i;
    for(i=0; i<P; i++) {
        pedreiros[i].cimento = 0;
        pedreiros[i].tijolos = 0;
        pedreiros[i].numero = i;
    }
}

void inicia_threads() {
 int i;
 for(i=0; i<P; i++) {
        pthread_create(&t_pedreiros[i], NULL, trabalha, (void*) &pedreiros[i]); 
 }   
}

void print_pedreiro(pedreiro_struct *p) {
    printf("Pedreiro n%d\nCimento: %d\nTijolos: %d\nTrabalhando na casa:%d\n", p->numero, p->cimento, p->tijolos, p->casa);
}

void trabalha(void *ped) {
    pedreiro_struct *p;
    p = (pedreiro_struct *) ped;
    pthread_mutex_lock( &m_cimento );
    sleep(Ptc);
    p->cimento = Pc;
    pthread_mutex_unlock( &m_cimento );

    pthread_mutex_lock( &m_tijolos );
    sleep(Ptt);
    p->tijolos = Pt;
    pthread_mutex_unlock( &m_tijolos );

    
    
}

