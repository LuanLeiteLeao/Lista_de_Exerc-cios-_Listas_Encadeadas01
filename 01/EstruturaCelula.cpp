#include <stdlib.h>
#include <iostream>
#define TAM 5
using namespace std;

/****** 1.Escreva a estrutura da célula de uma lista encadeada. ******/

/*O struct criado eh uma estrutura de uma celula (TAD - Tipo abstrato de dados), 
Como ha uma estrutura para uma lista, nela deve haver um ponteiro que aponta para o proximo,
este ponteiro deve ser do mesmo tipo da estrutura "struct lista *prox".
Desta forma, ela fara� a chamada da proxima celula.*/

/*typedef struct - Eh uma forma de declarar um tipo, comportando um unico 
tipo de dado no caso um inteiro (int)*/

typedef struct lista lista;

struct lista
{
	int numero;
	struct lista *prox;
};

/***** 2.Escreva uma funcao que encontre uma celula com conteudo minimo. ******/

/*Como parametro deve ser adicionado tanto a da struct e uma variavel ponteiro para a lista encadeada
-Quando utilizar o for deve criar um ponteiro que ira auxiliar na passagem para o "proximo" (proximoVariavel), este por
sua vez, recebe toda a struct em sua variavel. Tendo assim acesso ao conteudo.
-Se o "proximo" haver algum conteudo, continuara� no for ate encontrar o VAZIO
-Por ultimo, o proximoVariavel ira receber o proximo da struct */

int buscaCelula(int NumeroProcurado, lista *ListaEncadeada)
{
	for (lista *proximoVariavel = ListaEncadeada; proximoVariavel != NULL; proximoVariavel = proximoVariavel->prox)

		if (proximoVariavel->numero == NumeroProcurado)
		{
			cout << "Achou! " << proximoVariavel->numero;
			break;
		}
		else
		{
			cout << "Nom existi :( ";
		}
}

/***** 3.Escreva uma funcao que copie o conteudo de um vetor para uma lista encadeada preservando a ordem dos elementos. ******/

/*A lista* NovaCelula ira poupar o trabalho de ter que repetir o malloc em todas as funcoes que devera utilizar
  desta lista, tempo simplesmente que chama-la, ela nao precisa de um parametro, e sendo parte de uma struct, ela
  deve ser chamada atraves de um ponteiro.
*/

lista *NovaCelula()
{
	/*A variavel Celula ira receber o inteiro do espaco alocado que esta� incluso na struct
	  A funcao malloc (o nome eh uma abreviatura de memory allocation) aloca espaco para um bloco de bytes consecutivos na memoria 
	  RAM (= random access memory) do computador e devolve o endereco desse bloco.  
	  O numero de bytes especificado no argumento da funcao. 
	  No seguinte fragmento de codigo, malloc aloca 1 byte, a funca A expressao sizeof(XXXX) 
	  retorna o numero de bytes ocupado por um XXXX. 
	*/

	lista *Celula = (struct lista *)malloc(sizeof(struct lista *));

	return Celula;
}

/*Ela vai criar uma nova Celula e atribuir um número inteiro para a nova Celula
  Pegar a lista e buscar o final da lista, quando for encontrado o espaço
  vazio ela irá pegar o final dela e apontar para uma nova célula que 
  será adicionada e a nova apontará para NULL.
*/

lista *InicialistaNovaCelula(int Numero)
{
	lista *Celula = NovaCelula();
	Celula->numero = Numero;
	Celula->prox = NULL;
}

/* Esta funcao possui a responsabilidade de procurar o final da lista e 
inserir uma nova celula no final da lista*/

lista *InsereFinalLista(lista *MinhaLista, int Numero)
{
	/*Deve ser declarada do lado de fora do "for" pois assim que sair do "for"
	ela perdera o valor da variavel*/

	lista *ProximoAux;

	lista *CelulaInserir = InicialistaNovaCelula(Numero);

	/*ProximoAux = MinhaLista       ---- Recebe tudo que está dentro da struct como parâmetro
	
	  ProximoAux -> prox != NULL    ---- Irá apontar exatamente para o conteúdo, evitando assim, 
	  									 que apareça "NULL" após o último número que será exibido
	  									 
	  ProximoAux = ProximoAux -> prox -- Este, funciona de forma parecida ao contador de um vetor,
	  									 Simplemente ira apontar para o proximo da lista sequencialmente.
	--------------------------------------------------------------------------------------------------------
	  
	  O "for" possui um ";" (ELE NAO RODA NADA EM LOOP, OBSERVE QUE NAO EXISTE CHAVE E APENAS 
	  UM PONTO E VIRGULA, ELE POSSUI APENAS A RESPONSABILIDADE DE RODAR A LISTA E VERIFICAR SE HA� ALGUM VALOR)
	  */

	/*Ela compara se na lista da estrutura esta vazia, se estiver 
	vazia ela inicializa uma vez preenchendo o primeiro espaco com o item da Celula com o numero da primeira
	casa do vetor*/

	if (MinhaLista == NULL)
	{
		MinhaLista = CelulaInserir;
	}

	/*Caso a lista ja esteja inicializada ira entrar no else*/

	else
	{
		/*Ele roda o endereco ate encontrar o final da lista para entao inserir o valor na celula*/

		for (ProximoAux = MinhaLista; ProximoAux->prox != NULL; ProximoAux = ProximoAux->prox)
		{
			// nao faz nadaaaaaaaaaaaaaaaaa
			// apenas roda ate o final
		}

		/*Apos encontrar o ultimo valor da lista ele insere ao final a celula criada 
		(Ele adiciona uma celula)*/

		ProximoAux->prox = CelulaInserir;
	}

	return MinhaLista; // Se nao houver o return ele ira retornar apenas as 2 ultimas casas do vetor
}

//void imprimeLista(lista *MinhaLista)
//{
//	for (lista *ProximoAux = MinhaLista; ProximoAux != NULL; ProximoAux = ProximoAux->prox)
//	{
//		cout << ProximoAux->numero << endl;
//	}
//}

void imprimeLista(lista *Lista)
{

	for (lista *ListaAux = Lista; ListaAux != NULL; ListaAux = ListaAux->prox)
	{
		cout << ListaAux->numero << endl;
	}
}

lista *CopiaVet(int vet[])
{
	//inicializa a lista como NULL
	lista *MinhaLista = NULL;

	for (int i = 0; i < TAM; i++)
	{
		MinhaLista = InsereFinalLista(MinhaLista, vet[i]);
	}
	//cout << "--------------------------------------------------" << endl;
	//imprimeLista(MinhaLista);

	return MinhaLista;

	//	cout << TamanhoLista(MinhaLista);
}

//4.Escreva uma funcao que copie o conteudo de uma lista encadeada para um vetor preservando a ordem dos elementos.

int TamanhoLista(lista *MinhaLista)
{
	int Contador = 0;

	for (lista *ProximoAux = MinhaLista; ProximoAux != NULL; ProximoAux = ProximoAux->prox)
	{
		Contador++;
	}

	return Contador;
}

void CopiaLista(lista *MinhaLista)
{
	int TamanhoVetor = TamanhoLista(MinhaLista);
	int Vetor[TamanhoVetor], ContadorVetor = 0;

	/*Um "for" pode portar mais de um item da mesma categoria contando que tenha virgula*/

	for (lista *ProximoAux = MinhaLista; ProximoAux != NULL; ProximoAux = ProximoAux->prox, ContadorVetor++)
	{
		/*Para passar um valor da lista para uma variavel
		Eh necessario utilizar o auxiliar que esta apontando para a lista
		indicando o conteudo dela, que no nosso caso eh a variavel
		"numero" da struct*/

		Vetor[ContadorVetor] = ProximoAux->numero;
	}
}

//5.Escreva uma funcao que faca uma copia de uma lista encadeada.

lista *CopiaEncadeada(lista *MinhaCelula1)
{
	lista *CelulaCopia = NULL;
	for (lista *ProximoAux = MinhaCelula1; ProximoAux != NULL; ProximoAux = ProximoAux->prox)
	{
		// cout << ProximoAux->numero << endl;
		CelulaCopia = InsereFinalLista(CelulaCopia, ProximoAux->numero);
	}

	return CelulaCopia;
}

//6.Escreva uma funcao que concatene duas listas encadeadas (isto e, engate a segunda no fim da primeira).

lista *ConcatenaLista(lista *MinhaCelula1, lista *MinhaCelula2)
{
	lista *ProximoAux;

	for (ProximoAux = MinhaCelula1; ProximoAux->prox != NULL; ProximoAux = ProximoAux->prox)
	{
	}

	ProximoAux->prox = MinhaCelula2;

	return MinhaCelula1;
}

//7.Escreva uma funcao que conte o numero de celulas de uma lista encadeada.

int ContarCelulas(lista *MinhaCelula)
{
	int Cont = 1;

	for (lista *ProximoAux = MinhaCelula; ProximoAux->prox != NULL; ProximoAux = ProximoAux->prox)
	{
		Cont++;
	}

	return Cont;
}

//8.Escreva uma funcao que verifique se duas listas encadeadas sao iguais, ou melhor, se tem o mesmo conteudo. Faca duas versoes: uma iterativa e uma recursiva.

int ComparaListaItera(lista *MinhaCelula1, lista *MinhaCelula2)
{
	for (lista *ProxAux1 = MinhaCelula1, *ProxAux2 = MinhaCelula2; ProxAux1 != NULL; ProxAux1 = ProxAux1->prox, ProxAux2 = ProxAux2->prox)
	{
		if (ProxAux1->numero != ProxAux2->numero)
		{
			cout << "NAO SAO IGUAIS!";
			return 0;
		}
	}

	cout << "ELES SAO IGUAIS :3 ";
	return 1;
}

int main()
{
	int Vet[TAM] = {1, 2, 3, 4, 5}, Vet2[6] = {6, 7, 8, 9, 10, 11};

	lista *MinhaLista = CopiaVet(Vet);
	lista *CopiaDaLista = CopiaEncadeada(MinhaLista);
	//	imprimeLista(cop);

	//MinhaLista = ConcatenaLista(MinhaLista,CopiaDaLista);

	int QuantCelulas1 = ContarCelulas(MinhaLista);

	ComparaListaItera(CopiaVet(Vet2), CopiaVet(Vet2));
	//int QuantCelulas2 = ContarCelulas(CopiaDaLista);
	//ConcatenaLista(CopiaVet(Vet),CopiaVet(Vet2));

	// lista *Node1 = NULL;
	// lista *Node2 = NULL;
	// lista *Node3 = NULL;
	// lista *Node4 = NULL;
	// lista *Node5 = NULL;

	/*A variavel Node1 ira receber o inteiro do espaço alocado que estao incluso na struct
	  A funcao malloc (o nome eh uma abreviatura de memory allocation) aloca espanco para um bloco de bytes consecutivos na memoria 
	  RAM (= random access memory) do computador e devolve o endereço desse bloco.  
	  O numero de bytes é especificado no argumento da funcao. 
	  No seguinte fragmento de codigo, malloc aloca 1 byte, a funca A expressao sizeof(XXXX) 
	  retorna o numero de bytes ocupado por um XXXX.
	  (O primeiro struct entre parenteses pode representar uma conversao, como uma mensagem
	  de que o inteiro que esta sendo passado para o armazenamento dos bytes eh do tipo (STRUCT LISTA*) 
	*/

	// Node1 = (struct lista *)malloc(sizeof(struct lista *));

	// Node1->numero = 10;

	// Node2 = (struct lista *)malloc(sizeof(struct lista *));

	// Node2->numero = 10;

	// Node3 = (struct lista *)malloc(sizeof(struct lista *));

	// Node3->numero = 10;

	// Node4 = (struct lista *)malloc(sizeof(struct lista *));

	// Node4->numero = 10;

	// Node5 = (struct lista *)malloc(sizeof(struct lista *));

	// Node5->numero = 10;

	// Node1->prox = Node2;
	// Node2->prox = Node3;
	// Node3->prox = Node4;
	// Node4->prox = Node5;
	// Node5->prox = NULL;

	return 0;
}
