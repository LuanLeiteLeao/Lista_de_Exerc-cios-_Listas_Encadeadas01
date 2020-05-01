#include<stdlib.h>
#include<iostream>
#define TAM 5
using namespace std;

/****** 1.Escreva a estrutura da c�lula de uma lista encadeada. ******/


/*O struct criado � uma estrutura de uma c�lula (TAD - Tipo abstrato de dados), 
Como � uma estrutura para uma lista, nela deve haver um ponteiro que aponta para o pr�ximo,
este ponteiro deve ser do mesmo tipo da estrutura "struct lista *prox".
Desta forma, ela far� a chamada da pr�xima c�lula.*/

/*typedef struct - � uma forma de declarar um tipo, comportando um �nico 
tipo de dado no caso um inteiro (int)*/

typedef struct lista lista;

 struct lista{
	int numero;
	struct lista *prox;
};

/***** 2.Escreva uma fun��o que encontre uma c�lula com conte�do m�nimo. ******/


/*Como par�metro deve ser adicionado tanto a da struct e uma vari�vel ponteiro para a lista encadeada
-Quando utilizar o for deve criar um ponteiro que ir� auxiliar na passagem para o "pr�ximo" (proximoVariavel), este por
sua vez, recebe toda a struct em sua vari�vel. Tendo assim acesso ao conte�do.

-Se o "pr�ximo" haver algum conte�do, continuar� no for at� encontrar o VAZIO

-Por �ltimo, o pr�ximoVariavel ir� receber o pr�ximo da struct */

int buscaCelula(int NumeroProcurado, lista *ListaEncadeada)
{    
	for (lista *proximoVariavel = ListaEncadeada; proximoVariavel != NULL; proximoVariavel = proximoVariavel->prox)          
	if (proximoVariavel->numero == NumeroProcurado)        
	{             
		cout << "Achou! "<< proximoVariavel -> numero;
		break;
	} else{
		cout << "Nom existi :( ";
	}
	
}

/***** 3.Escreva uma fun��o que copie o conte�do de um vetor para uma lista encadeada preservando a ordem dos elementos. ******/


/*A lista* NovaCelula ir� poupar o trabalho de ter que repetir o malloc em todas as fun��es que dever� utilizar
  desta lista, tempo simplesmente que cham�-la, ela n�o precisa de um par�metro, e sendo parte de uma struct, ela
  deve ser chamada atrav�s de um ponteiro.
*/
  
lista* NovaCelula()
{
	/*A vari�vel Node1 ir� receber o inteiro do espa�o alocado que est� incluso na struct
	  A fun��o malloc (o nome � uma abreviatura de memory allocation) aloca espa�o para um bloco de bytes consecutivos na mem�ria 
	  RAM (= random access memory) do computador e devolve o endere�o desse bloco.  
	  O n�mero de bytes � especificado no argumento da fun��o. 
	  No seguinte fragmento de c�digo, malloc aloca 1 byte, a funca A express�o sizeof(XXXX) 
	  retorna o n�mero de bytes ocupado por um XXXX. 
	*/
	
	lista *Celula = (struct lista*) malloc (sizeof(struct lista*));
	
	return Celula;
	
}

/*Ela vai criar uma nova Celula e atribuir um n�mero inteiro para a nova Celula
  Pegar a lista e buscar o final da lista, quando for encontrado o espa�o
  vazio ela ir� pegar o final dela e apontar para uma nova c�lula que 
  ser� adicionada e a nova apontar� para NULL.
*/
  
lista* InicializaNovaCelula(int Numero, lista *MinhaLista)
{
	lista *Celula = NovaCelula();
	Celula -> numero = Numero;
	Celula -> prox = NULL;
}

/* Esta fun��o possui a responsabilidade de procurar o final da lista e 
inserir uma nova c�lula no final da lista*/

void InsereFinalLista(lista *CelulaInserir, lista *MinhaLista)
{
	/*Deve ser declarada do lado de fora do "for" pois assim que sair do "for"
	ela perder� o valor da vari�vel*/
	
	lista *ProximoAux;
	
	/*ProximoAux = MinhaLista       ---- Recebe tudo que est� dentro da struct como par�metro
	
	  ProximoAux -> prox != NULL    ---- Ir� apontar exatamente para o conte�do, evitando assim, 
	  									 que apare�a "NULL" ap�s o �ltimo n�mero que ser� exibido
	  									 
	  ProximoAux = ProximoAux -> prox -- Este, funciona de forma parecida ao contador de um vetor,
	  									 Simplemente ir� apontar para o pr�ximo da lista sequencialmente.
	--------------------------------------------------------------------------------------------------------
	  
	  O "for" possui um ";" (ELE N�O RODA NADA EM LOOP, OBSERVE QUE N�O EXISTE CHAVE E APENAS 
	  UM PONTO E V�RGULA, ELE POSSUI APENAS A RESPONSABILIDADE DE RODAR A LISTA E VERIFICAR SE H� ALGUM VALOR)
	  */ 
	
	for(ProximoAux = MinhaLista; ProximoAux -> prox != NULL; ProximoAux = ProximoAux -> prox);
	ProximoAux -> prox = CelulaInserir;
	
}

void CopiaVet()
{
	
	
}

//4.Escreva uma fun��o que copie o conte�do de uma lista encadeada para um vetor preservando a ordem dos elementos.

//5.Escreva uma fun��o que fa�a uma c�pia de uma lista encadeada.

//6.Escreva uma fun��o que concatene duas listas encadeadas (isto �, engate a segunda no fim da primeira).

//7.Escreva uma fun��o que conte o n�mero de c�lulas de uma lista encadeada.

//8.Escreva uma fun��o que verifique se duas listas encadeadas s�o iguais, ou melhor, se t�m o mesmo conte�do. Fa�a duas vers�es: uma iterativa e uma recursiva.


int main(){
	int Vet[TAM]={1,2,3,4,5};
	lista *Node1=NULL;
	lista *Node2=NULL;
	lista *Node3=NULL;
	lista *Node4=NULL;
	lista *Node5=NULL;
	
	/*A vari�vel Node1 ir� receber o inteiro do espa�o alocado que est� incluso na struct
	  A fun��o malloc (o nome � uma abreviatura de memory allocation) aloca espa�o para um bloco de bytes consecutivos na mem�ria 
	  RAM (= random access memory) do computador e devolve o endere�o desse bloco.  
	  O n�mero de bytes � especificado no argumento da fun��o. 
	  No seguinte fragmento de c�digo, malloc aloca 1 byte, a funca A express�o sizeof(XXXX) 
	  retorna o n�mero de bytes ocupado por um XXXX.
	  (O primeiro struct entre par�nteses pode representar uma convers�o, como uma mensagem
	  de que o inteiro que est� sendo passado para o armazenamento dos bytes � do tipo (STRUCT LISTA*) 
	*/
	
	Node1 = (struct lista*) malloc (sizeof(struct lista*));
	
	Node1 -> numero = 10;
	
	Node2 = (struct lista*) malloc (sizeof(struct lista*));
	
	Node2 -> numero = 10;
	
	Node3 = (struct lista*) malloc (sizeof(struct lista*));
	
	Node3 -> numero = 10;
	
	Node4 = (struct lista*) malloc (sizeof(struct lista*));
	
	Node4 -> numero = 10;
	
	Node5 = (struct lista*) malloc (sizeof(struct lista*));
	
	Node5 -> numero = 10;
	
	Node1 -> prox = Node2;
	Node2 -> prox = Node3;
	Node3 -> prox = Node4;
	Node4 -> prox = Node5;
	Node5 -> prox = NULL;
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
