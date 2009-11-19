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

#define PASSO 0

void inicia_threads(void);
void trabalha(void*);
void inicializa_casas(void);
void inicializa_pedreiros(void);
void print_pedreiros(void);
void print_estoque(void);
void print_casas(void);
int decide_casa(void);
int checa_todas(void);
void checa_casa(casa_struct*);

int rodando = 1;

int main(void) {

    printf("Numero de pedreiros: ");
    scanf("%d",&P);
    printf("Quantidade de casas a construir: ");
    scanf("%d",&C);
    printf("Cada casa precisa de quanto cimento? ");
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
    printf("Quantos segundos ele demora para concluir o trabalho? ");
    scanf("%d",&Pts); 
   
    m_casas = (pthread_mutex_t *)malloc(C * sizeof(pthread_mutex_t));
    t_pedreiros = (pthread_t *)malloc(P * sizeof(pthread_t));
    casas = (casa_struct *)malloc(C * sizeof(casa_struct));
    pedreiros = (pedreiro_struct *)malloc(P * sizeof(pedreiro_struct));
    
    estoque_tijolos = C*Ct;
    estoque_cimento = C*Cc;
    
    system("clear");

    inicializa_casas();
    inicializa_pedreiros();
    
    inicia_threads();
    while(rodando == 1) {
        system("clear");        
        
        print_pedreiros();
        printf("\n*************************\n");
        print_casas();
        printf("\n*************************\n");
        print_estoque();
        
        if(PASSO == 1)
            getchar();
    }
    
    printf("\nCasas prontas! =D\n");
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
        pedreiros[i].casa = -1;
    }
}

void inicia_threads() {
 int i;
 for(i=0; i<P; i++) {
        pthread_create(&t_pedreiros[i], NULL, trabalha, (void*) &pedreiros[i]); 
 }   
}

void print_estoque() {
    printf("\nEstoque:\n");
    printf("Cimento: \t%d\n", estoque_cimento);
    printf("Tijolos: \t%d\n", estoque_tijolos);
    printf("\n");
}

void print_casas() {
    int i;
    printf("\n\t\t");
    for(i=0; i < C; i++) {
        printf("Casa %d\t\t", i);
    }
    printf("\nCimento\t\t");
    for(i=0; i < C; i++) {
        printf("%d\t\t", casas[i].cimento);
    }
    printf("\nTijolos\t\t");
    for(i=0; i < C; i++) {
        printf("%d\t\t", casas[i].tijolos);
    }
    printf("\nPronta?   \t");
    for(i=0; i < C; i++) {
        if(casas[i].pronta == 0)
            printf("Nao\t\t");
        else
            printf("Sim\t\t");
    }
    printf("\nOcupada?   \t");
    for(i=0; i < C; i++) {
        if(casas[i].ocupada == 0)
            printf("Nao\t\t");
        else
            printf("Sim\t\t");
    }
    printf("\n");

    
}

void print_pedreiros() {
    int i;
    printf("\n\t");
    for(i=0; i < P; i++) {
        printf("Pedreiro %d\t", i);
    }
    printf("\nCimento\t\t");
    for(i=0; i < P; i++) {
        printf("%d\t\t", pedreiros[i].cimento);
    }
    printf("\nTijolos\t\t");
    for(i=0; i < P; i++) {
        printf("%d\t\t", pedreiros[i].tijolos);
    }
    printf("\nCasa   \t\t");
    for(i=0; i < P; i++) {
        if(pedreiros[i].casa < 0)
            printf("Nenhuma\t\t");
        else
            printf("%d\t\t", pedreiros[i].casa);
    }
    printf("\n");
}

void trabalha(void *ped) {
    int qtd_cimento;
    int qtd_tijolos;
    int tijolos_precisa;
    int cimento_precisa;
    while(rodando == 1) {
                                        
        pedreiro_struct *p;
        p = (pedreiro_struct *) ped;
        pthread_mutex_lock( &m_cimento );
        qtd_cimento = Pc - p->cimento;
        if((estoque_cimento - qtd_cimento) >= 0) {
            estoque_cimento = estoque_cimento - qtd_cimento;
            p->cimento = p->cimento + qtd_cimento;
            sleep(Ptc);
        }            
        pthread_mutex_unlock( &m_cimento );

        pthread_mutex_lock( &m_tijolos );
        qtd_tijolos = Pt - p->tijolos;
        if((estoque_tijolos - qtd_tijolos) >= 0) {
            estoque_tijolos =  estoque_tijolos - qtd_tijolos;
            p->tijolos = p->tijolos + qtd_tijolos;
            sleep(Ptt);
        }
        pthread_mutex_unlock( &m_tijolos );
    
        int casa;
        casa = decide_casa();
        if(casa == -1)
            rodando = 0;
        else {
            pthread_mutex_lock((pthread_mutex_t*) &m_casas[casa]);
            casas[casa].ocupada = 1;
            p->casa = casa;
            
            tijolos_precisa = Ct - casas[casa].tijolos;
            cimento_precisa = Cc - casas[casa].cimento;
            
            if(tijolos_precisa > p->tijolos)
                tijolos_precisa = p->tijolos;
            if(cimento_precisa > p->cimento)
                cimento_precisa = p->cimento;
            
            casas[casa].cimento = casas[casa].cimento+cimento_precisa;
            casas[casa].tijolos = casas[casa].tijolos+tijolos_precisa;
            
            p->cimento = p->cimento - cimento_precisa;
            p->tijolos = p->tijolos - tijolos_precisa;
            
            sleep(Pts);
            p->casa = -1;
            casas[casa].ocupada = 0;
            checa_casa(&casas[casa]);
            rodando = checa_todas();
            pthread_mutex_unlock((pthread_mutex_t*) &m_casas[casa]);        
        }
        if(PASSO == 1)
            getchar();
    }
}

int decide_casa() {
    int i = 0;
    while(casas[i].pronta == 1 || casas[i].ocupada == 1) {
        if(i == (C - 1))
            i = 0;
        else 
            i++;
    }
    return i;
}

int checa_todas() {
    int i;
    for(i=0; i<C; i++) {
        if(casas[i].pronta == 0)
            return 1;
    }
    return 0;
}

void checa_casa(casa_struct* c) {
    if(c->cimento >= Cc && c->tijolos >= Ct)
        c->pronta = 1;
}
