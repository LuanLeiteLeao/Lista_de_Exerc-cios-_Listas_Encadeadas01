#include<stdlib.h>
#include<iostream>
#define TAM 5
using namespace std;

/****** 1.Escreva a estrutura da célula de uma lista encadeada. ******/


/*O struct criado é uma estrutura de uma célula (TAD - Tipo abstrato de dados), 
Como é uma estrutura para uma lista, nela deve haver um ponteiro que aponta para o próximo,
este ponteiro deve ser do mesmo tipo da estrutura "struct lista *prox".
Desta forma, ela fará a chamada da próxima célula.*/

/*typedef struct - É uma forma de declarar um tipo, comportando um único 
tipo de dado no caso um inteiro (int)*/

typedef struct lista lista;

 struct lista{
	int numero;
	struct lista *prox;
};

/***** 2.Escreva uma função que encontre uma célula com conteúdo mínimo. ******/


/*Como parâmetro deve ser adicionado tanto a da struct e uma variável ponteiro para a lista encadeada
-Quando utilizar o for deve criar um ponteiro que irá auxiliar na passagem para o "próximo" (proximoVariavel), este por
sua vez, recebe toda a struct em sua variável. Tendo assim acesso ao conteúdo.

-Se o "próximo" haver algum conteúdo, continuará no for até encontrar o VAZIO

-Por último, o próximoVariavel irá receber o próximo da struct */

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

/***** 3.Escreva uma função que copie o conteúdo de um vetor para uma lista encadeada preservando a ordem dos elementos. ******/


/*A lista* NovaCelula irá poupar o trabalho de ter que repetir o malloc em todas as funções que deverá utilizar
  desta lista, tempo simplesmente que chamá-la, ela não precisa de um parâmetro, e sendo parte de uma struct, ela
  deve ser chamada através de um ponteiro.
*/
  
lista* NovaCelula()
{
	/*A variável Node1 irá receber o inteiro do espaço alocado que está incluso na struct
	  A função malloc (o nome é uma abreviatura de memory allocation) aloca espaço para um bloco de bytes consecutivos na memória 
	  RAM (= random access memory) do computador e devolve o endereço desse bloco.  
	  O número de bytes é especificado no argumento da função. 
	  No seguinte fragmento de código, malloc aloca 1 byte, a funca A expressão sizeof(XXXX) 
	  retorna o número de bytes ocupado por um XXXX. 
	*/
	
	lista *Celula = (struct lista*) malloc (sizeof(struct lista*));
	
	return Celula;
	
}

/*Ela vai criar uma nova Celula e atribuir um número inteiro para a nova Celula
  Pegar a lista e buscar o final da lista, quando for encontrado o espaço
  vazio ela irá pegar o final dela e apontar para uma nova célula que 
  será adicionada e a nova apontará para NULL.
*/
  
lista* InicializaNovaCelula(int Numero, lista *MinhaLista)
{
	lista *Celula = NovaCelula();
	Celula -> numero = Numero;
	Celula -> prox = NULL;
}

/* Esta função possui a responsabilidade de procurar o final da lista e 
inserir uma nova célula no final da lista*/

void InsereFinalLista(lista *CelulaInserir, lista *MinhaLista)
{
	/*Deve ser declarada do lado de fora do "for" pois assim que sair do "for"
	ela perderá o valor da variável*/
	
	lista *ProximoAux;
	
	/*ProximoAux = MinhaLista       ---- Recebe tudo que está dentro da struct como parâmetro
	
	  ProximoAux -> prox != NULL    ---- Irá apontar exatamente para o conteúdo, evitando assim, 
	  									 que apareça "NULL" após o último número que será exibido
	  									 
	  ProximoAux = ProximoAux -> prox -- Este, funciona de forma parecida ao contador de um vetor,
	  									 Simplemente irá apontar para o próximo da lista sequencialmente.
	--------------------------------------------------------------------------------------------------------
	  
	  O "for" possui um ";" (ELE NÃO RODA NADA EM LOOP, OBSERVE QUE NÃO EXISTE CHAVE E APENAS 
	  UM PONTO E VÍRGULA, ELE POSSUI APENAS A RESPONSABILIDADE DE RODAR A LISTA E VERIFICAR SE HÁ ALGUM VALOR)
	  */ 
	
	for(ProximoAux = MinhaLista; ProximoAux -> prox != NULL; ProximoAux = ProximoAux -> prox);
	ProximoAux -> prox = CelulaInserir;
	
}

void CopiaVet()
{
	
	
}

//4.Escreva uma função que copie o conteúdo de uma lista encadeada para um vetor preservando a ordem dos elementos.

//5.Escreva uma função que faça uma cópia de uma lista encadeada.

//6.Escreva uma função que concatene duas listas encadeadas (isto é, engate a segunda no fim da primeira).

//7.Escreva uma função que conte o número de células de uma lista encadeada.

//8.Escreva uma função que verifique se duas listas encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões: uma iterativa e uma recursiva.


int main(){
	int Vet[TAM]={1,2,3,4,5};
	lista *Node1=NULL;
	lista *Node2=NULL;
	lista *Node3=NULL;
	lista *Node4=NULL;
	lista *Node5=NULL;
	
	/*A variável Node1 irá receber o inteiro do espaço alocado que está incluso na struct
	  A função malloc (o nome é uma abreviatura de memory allocation) aloca espaço para um bloco de bytes consecutivos na memória 
	  RAM (= random access memory) do computador e devolve o endereço desse bloco.  
	  O número de bytes é especificado no argumento da função. 
	  No seguinte fragmento de código, malloc aloca 1 byte, a funca A expressão sizeof(XXXX) 
	  retorna o número de bytes ocupado por um XXXX.
	  (O primeiro struct entre parênteses pode representar uma conversão, como uma mensagem
	  de que o inteiro que está sendo passado para o armazenamento dos bytes é do tipo (STRUCT LISTA*) 
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
