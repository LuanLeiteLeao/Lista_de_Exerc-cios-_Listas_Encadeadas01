

#include<stdlib.h>
#include<iostream>
using namespace std;

//1.Escreva a estrutura da célula de uma lista encadeada.

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

//2.Escreva uma função que encontre uma célula com conteúdo mínimo.

int buscaCelula(int NumeroProcurado, lista *ListaEncadeada)
{    
	for (lista *prox = ListaEncadeada; prox != NULL; prox = prox->prox)          
	if (prox->numero == NumeroProcurado)        
	{             
		cout << "Achou! "<< prox -> numero;
		break;
	} else{
		cout << "Nom existi :( ";
	}
}

//3.Escreva uma função que copie o conteúdo de um vetor para uma lista encadeada preservando a ordem dos elementos.

//4.Escreva uma função que copie o conteúdo de uma lista encadeada para um vetor preservando a ordem dos elementos.

//5.Escreva uma função que faça uma cópia de uma lista encadeada.

//6.Escreva uma função que concatene duas listas encadeadas (isto é, engate a segunda no fim da primeira).

//7.Escreva uma função que conte o número de células de uma lista encadeada.

//8.Escreva uma função que verifique se duas listas encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões: uma iterativa e uma recursiva.


int main(){
	
	return 0;
}
