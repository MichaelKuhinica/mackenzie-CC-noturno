/*
  Diego Martins         TIA:3064296-5
  Michael Kuhinica          3065363-0
  Artur Machado             4068427-1
*/
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//variaveis obrigatorias do exercicio
static int C=0;                         //indica o numero de casas
static int P=0;                         //indica o numero de pedreiros
static int Cc=0;                        //indica quantos quilos de cimento
static int Ct=0;                        //indica quantos tijolos para a contrução
static int Pc=0;                        //indica quantos quilos de cimento busca do estoque
static int Ptc=0;                       //indica quanto tempo para colocar Pc no carrinho
static int Pt=0;                        //indica quantos tijolos sao buscados no estoque
static int Ptt=0;                       //indica quanto tempo demora para colocar Pt no carrinho


//variaveis do programa
static int cont=0;			 //verificador de lista de pedreiros - permite controle do revezamento
static int cont2=0;			 //verificador de estoque utilizado nas casas - para decisao de final de contrucao da casa
static int termino=0;                    //libera o termino do programa, quando todas as casas tiverem sido construidas
static int constCasas=0;                 //quantidade atual de casas construidas
static int pedreiros[50];		 //lista de pedreiros trabalhando na obra
static int casas[50];		 	 //lista com dados v[a] valor de cimento da casa e v[a+1] valor de tijolos


pthread_mutex_t m_est_cimento;               /*politica de acesso ao estoque de cimento
                                        apenas um pedreiro por vez pode acessar o estoque de cimento*/

pthread_mutex_t m_est_tijolo;               /*politica de acesso ao estoque de tijolo
                                          apenas um pedreiro por vez pode acessar o estoque de tijolo*/

pthread_mutex_t m_const_casa;               /*politica de acesso a casa
                                          apenas um pedreiro por vez pode construir partes da casa*/

pthread_t thread;





void espera ( float segundos )          //funcao usada para o loop do periodo de busca de produtos e contrucao de parte da casa
{
  clock_t fimEspera;
  fimEspera = clock () + segundos * CLOCKS_PER_SEC ;
  while (clock() < fimEspera) {}
}




void *constroi(void *threadid)            //funcao principal onde é feito todo o trabalho dos pedreiros
{
	int tid;
	int i=0; //---------------------------------------------- remover esta variavel, utilizada apenas para imprimir o vetor que contem informacoes v[a] quantidade faltante de cimento e v[a+1] quantidade faltante de tijolo

	do{

	if ( pedreiros[cont] == 0 )		// se caso o pedreiro ainda nao existe
		pedreiros[cont]=(int)threadid;

	if (cont+1 == P )			// para retornar a funcao ao primeiro pedreiro
		cont=0;
	
	tid=pedreiros[cont];

	//modifica estoques
	pthread_mutex_lock(&m_est_cimento);                  //trava estoque de cimento
		printf("\nPedreiro ID=%d carregando cimento\n",tid);
		printf("Est. cimento: ");
			scanf("%d",&Pc);
	if ( Cc <= Pc )Cc=Pc;
	Cc = Cc-Pc;
	espera(Ptc); 
	pthread_mutex_unlock(&m_est_cimento);

	pthread_mutex_lock(&m_est_tijolo);                  //trava estoque de tijolo
		printf("\nPedreiro ID=%d carregando tijolo\n",tid);
		printf("Est. tijolos: ");
			scanf("%d",&Pt);
	if ( Ct <= Pt )Ct=Pt;
	Ct = Ct - Pt;
	espera(Ptt); 
	pthread_mutex_unlock(&m_est_tijolo);
	cont++;



	// modifica a casa
	printf("Construindo casa %d\n",cont2);

	pthread_mutex_lock(&m_const_casa);
	if ( casas[cont2*2]-Pc <= 0 ){ //verifica se ja tem o suficiente de cimento para contruir a casa
		Pc = Pc - casas[cont2*2];
		pthread_mutex_lock(&m_est_cimento);
		Cc = Cc + Pc;				//retorna o restante do cimento para estoque
		pthread_mutex_unlock(&m_est_cimento);
		casas[cont2*2] = 0;
	}else{
		casas[cont2*2] = casas[cont2*2] - Pc;
		pthread_mutex_lock(&m_est_cimento);

		Cc = Cc + Pc;				//retorna o restante do tijolo para estoque
		pthread_mutex_unlock(&m_est_cimento);
		
		}

		if ( casas[(cont2*2)+1]-Pt <= 0 ){ //verifica se ja tem o suficiente de cimento para contruir a casa
		Pt = Pt - casas[(cont2*2)+1];
		pthread_mutex_lock(&m_est_tijolo);
		Ct = Ct + Pt;				//retorna o restante do cimento para estoque
		pthread_mutex_unlock(&m_est_tijolo);
		casas[(cont2*2)+1] = 0;
	}else{
		casas[(cont2*2)+1] = casas[(cont2*2)+1] - Pt;
		pthread_mutex_lock(&m_est_tijolo);

		Ct = Ct + Pt;				//retorna o restante do tijolo para estoque
		pthread_mutex_unlock(&m_est_tijolo);
		
		}


	//imprimi como esta as casas
	for ( i=0;i<=6;i++)		//v[a] quantidade faltante de cimento e v[a+1] quantidade faltante de tijolo
	printf("casas[%d]=%d\n",i,casas[i]);


	if ( casas [cont2*2] == 0 &&  casas [(cont2*2)+1] == 0 ){ // se tiver suficiente de tijolo e cimento para a casa, entao a casa ja foi construida
		printf("Casa %d contruida\n",cont2);
		cont2++;
		constCasas++;
		}

	pthread_mutex_unlock(&m_const_casa);

	}while(constCasas!=C);
}



void *inicia(void *threadid)
{
   int tid;
   tid = (int)threadid;
   srand ( time(NULL) );
   int lado,cria,i,rc,threadID;
	i=0;
   for(i=0,threadID=0;i<P;threadID++){
       espera(0.1);
		if (i>0){
		printf("\nEsperando cimento\n");
		}
               pthread_create(&thread,NULL, constroi, (void *)threadID);            //criacao dos pedreiros
		 i++;
           }

	while(constCasas!=C)                    //espera todas as casas serem construidas para terminar o programa
	 termino=1;                                      //liberacao do termino do programa
   pthread_exit(NULL);
}




main (void)
{
	int i=0,cont3=0;
	
   pthread_t asd[1];
   pthread_mutex_init(&m_est_cimento,NULL);                      //inicializacao do mutex m_est_cimento
   pthread_mutex_init(&m_est_tijolo,NULL);                    //inicializacao do mutex m_est_tijolo

   printf("Quantidade de pedreiros: ");
   scanf("%d",&P);
   printf("\nQuantidade de casas: ");
   scanf("%d",&C);

   printf("\nQuantidade de cimento para contruir cada casa: ");
   scanf("%d",&Cc);
    for ( i=0;i<=C;i++){			// inicia lista de casas da obra
	casas[cont3]=Cc;
	cont3=cont3+2;
	}
  cont3=1;
  printf("\nQuantidade de tijolo para contruir cada casa: ");
   scanf("%d",&Ct);	
    for ( i=0;i<=C;i++)	{		// inicia lista de casas da obra
	casas[cont3]=Ct;
	cont3=cont3+2;
	}


   pthread_create(&thread, NULL, inicia,(void *)1);               //criacao da thread geradora
   while(termino!=1);                                   //espera todas as casas serem construidas para terminar o programa
   pthread_exit(NULL);

}











