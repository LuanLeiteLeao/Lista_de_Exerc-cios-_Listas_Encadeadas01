

#include<stdlib.h>
#include<iostream>
using namespace std;

//1.Escreva a estrutura da c�lula de uma lista encadeada.

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

//2.Escreva uma fun��o que encontre uma c�lula com conte�do m�nimo.

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

//3.Escreva uma fun��o que copie o conte�do de um vetor para uma lista encadeada preservando a ordem dos elementos.

//4.Escreva uma fun��o que copie o conte�do de uma lista encadeada para um vetor preservando a ordem dos elementos.

//5.Escreva uma fun��o que fa�a uma c�pia de uma lista encadeada.

//6.Escreva uma fun��o que concatene duas listas encadeadas (isto �, engate a segunda no fim da primeira).

//7.Escreva uma fun��o que conte o n�mero de c�lulas de uma lista encadeada.

//8.Escreva uma fun��o que verifique se duas listas encadeadas s�o iguais, ou melhor, se t�m o mesmo conte�do. Fa�a duas vers�es: uma iterativa e uma recursiva.


int main(){
	
	return 0;
}
