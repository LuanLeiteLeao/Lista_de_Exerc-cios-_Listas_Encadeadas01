#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<new>
#include<locale.h>

using namespace std; 

struct lista{
	
	char nome[50];
	int matricula;
	char email[50];
	char curso[50];
	
	struct lista *proximo;
	
	struct listaTelefone *tel; 
	struct listaDisciplina *disc;
};

struct listaTelefone{
		char telefone[12];
		
		struct listaTelefone *proximo;
};

struct listaDisciplina{
	char disciplina[50];
	
	struct listaDisciplina *proximo;
};

/******************************************************************************************/

//Adiciona os valores da struct do aluno
int addLista(lista *&ponteiroEncadeada, char Nome[], int Matricula, char Telefone[])
{
	if(ponteiroEncadeada == NULL)
	{
		lista *novaPessoa = (struct lista*) malloc (sizeof(struct lista*));
		strcpy (novaPessoa-> nome, Nome);
		novaPessoa-> matricula = Matricula;
		novaPessoa-> proximo = ponteiroEncadeada;
		
		ponteiroEncadeada = novaPessoa;
		return 0;
	}
	
	addLista(ponteiroEncadeada->proximo, Nome, Matricula, Telefone);
}

//Adiciona o n�mero de telefone
int addTel(listaTelefone *&ponteiroTelefone, char Telefone[] )
{
	if(ponteiroTelefone == NULL)
	{
		listaTelefone *telefoneAux = (struct listaTelefone*) malloc (sizeof(struct listaTelefone*));
		strcpy(telefoneAux->telefone, Telefone);
		
		telefoneAux -> proximo = ponteiroTelefone;
		
		ponteiroTelefone = telefoneAux;
		return 0;
	
	}
	
	addTel (ponteiroTelefone->proximo, Telefone);
}

//Adiciona a disciplina
int addDiscp (listaDisciplina *&ponteiroDisciplina, char Disciplina[])
{
		if(ponteiroDisciplina == NULL)
		{
			
			listaDisciplina *disciplinaAux = new listaDisciplina;
			strcpy(disciplinaAux->disciplina, Disciplina);
	
			disciplinaAux -> proximo = ponteiroDisciplina;
	
			ponteiroDisciplina = disciplinaAux;
			
			return 0;
		}
		
		addDiscp (ponteiroDisciplina->proximo, Disciplina);
}

//Ir� fazer uma contagem do tamanho da lista para ter uma no��o do tamanho at� a matr�cula que 
//A pessoa deseja remover
int contador (lista *ponteiroEncadeada, int Matricula, int Cont)
{
	if(ponteiroEncadeada->matricula==Matricula)
	{
		return Cont;
		
	}
	
	contador (ponteiroEncadeada->proximo, Matricula, ++Cont);
}

//Faz a remo��o de uma matr�cula
int remove(lista *&ponteiroEncadeada, int Matricula)
{
	
	int Posicao = contador(ponteiroEncadeada, Matricula, 0);
	lista *p=ponteiroEncadeada;
	
	for(int i=0; i<=Posicao; i++)
	{
		if(i == Posicao-1)
		{
			lista *aux = new lista;
			
			aux = p->proximo;
			p->proximo = aux->proximo;
			
			free(aux);
			
			return 0;
		}
		
		if(i==Posicao)
		{
			ponteiroEncadeada = ponteiroEncadeada->proximo;
		}
		
		p=p->proximo;
	}
	
}

//Vai imprimir a lista completa apenas com um n�mero de telefone adicionado
int imprimeLista(lista *ponteiroEncadeada, listaTelefone *ponteiroTelefone)
{
	if ( ponteiroEncadeada == NULL)
	{
		return 0;
	}
	cout <<"\nNome: "<< ponteiroEncadeada->nome;
	cout <<"\nMatr�cula: "<< ponteiroEncadeada->matricula;
	cout <<"\nTelefone: "<< ponteiroTelefone->telefone;
	printf ("\n-----------------------\n");
	
	imprimeLista(ponteiroEncadeada->proximo, ponteiroTelefone->proximo);
}

//Este ir� mostrar o registro da matr�cula desejada
int procuraMatricula(lista *ponteiroEncadeada, int Matricula, listaTelefone *ponteiroTelefone)
{
	if(ponteiroEncadeada->matricula == Matricula)
	{
		cout <<"\nNome: "<< ponteiroEncadeada->nome;
		cout <<"\nMatr�cula: "<< ponteiroEncadeada->matricula;
			
		return 1;
		
	}else if(ponteiroEncadeada->proximo==NULL){
		cout << "\nMatr�cula n�o encontrada!\n\n";
		
		return 0;
	}
	
	procuraMatricula(ponteiroEncadeada->proximo, Matricula, ponteiroTelefone);
}

int main()
{
	setlocale(LC_ALL,"Portuguese");

	//Vari�veis
	
	int Escolha, Matricula;
	char Nome[50], Telefone[12], SegundoNome[50], Email[50], Curso[50], Disciplina[50];
	
	//Ponteiro Principal
	
	lista *ponteiroEncadeada = NULL;
	listaTelefone *ponteiroTelefone = NULL;
	listaDisciplina *ponteiroDisciplina = NULL;
	
	do
	{
			system("cls");

			printf ("***********AGENDA DOS ALUNOS DA UEG*************");
			printf ("\n\nDADOS DO ALUNO: ");
			
			printf ("\n\n1. Inserir um novo aluno");
			printf ("\n2. Adicionar novos dados");
			printf ("\n3. Excluir...");
			printf ("\n4. Procurar...");
			printf ("\n5. Listar os alunos existentes");
			printf ("\n6. Sair");
			printf ("\n\nEscolha um n�mero e pressione <ENTER>: ");
			
			
			cin>> Escolha;
			
	/*-----------------------------------------IN�CIO DAS CONDICIONAIS--------------------------------------------*/
		switch(Escolha)
		{
			case 1:
				system("cls");
				printf ("*************INSERIR NOVO ALUNO*************\n\n");
				
				printf ("Nome: ");
				cin>>Nome;
				
				fflush(stdin);
				printf ("Matr�cula: ");
				cin>>Matricula;
				
				printf ("Telefone: ");
				fflush(stdin);
				cin>>Telefone;
				
				addLista(ponteiroEncadeada, Nome, Matricula, Telefone);//, Email, Curso);
				addTel(ponteiroTelefone,Telefone);
				//addDiscp(ponteiroDisciplina, Disciplina);
				break;
		/*-----------------------------------------------------------------------------------------*/
			case 2:
				printf ("*************ADICIONAR NOVOS DADOS*************\n\n");
				
				/**Aqui eu quero fazer a adi��o de novos dados como telefone e disciplina
					Mas j� tentei de tudo quanto � inser��o, uma delas sobre escreveu por cima**/
					
				system("cls");
				break;
	/*-----------------------------------------------------------------------------------------*/			
							/**O case 3 � para excluir est� funcionando**/
			case 3:
				system("cls");
				printf ("*************EXCLUIR MATR�CULA*************\n\n");
				
				if(ponteiroEncadeada== NULL)
				{	
					printf ("LISTA VAZIA!\n\n");
					system ("pause");
					
					break;
				}
				
				printf("Digite o n�mero da matr�cula que deseja procurar:\n\nMatr�cula: ");
				cin>>Matricula;
				
				remove(ponteiroEncadeada, Matricula);
				break;
		/*-----------------------------------------------------------------------------------------*/		
			case 4:
				/**O case 4 � para procurar algum registro atrav�s da matr�cula, est� funcionando
					Mas at� agora ela s� imprime um n�mero de telefone 							**/
				
				system("cls");
				printf ("*************PROCURAR MATR�CULA*************\n\n");
				
				printf ("Digite o n�mero da matr�cula: ");
				cin>>Matricula;
				
				procuraMatricula(ponteiroEncadeada, Matricula, ponteiroTelefone);
				system ("pause");
				break;

			case 5:
				/**O case 5 imprime todos os registros feitos, est� funcionando
					Mas at� agora ela s� imprime um n�mero de telefone 			**/
				
				system("cls");
				printf ("*************LISTA DE ALUNOS*************\n\n");
				
				imprimeLista(ponteiroEncadeada, ponteiroTelefone);
				
				system ("pause");
				
				break;

			case 6:
				/**Este � o case 6, ele far� o usu�rio sair do sistema**/
				
				printf ("\nPrograma encerrado com Sucesso!\n\n\n");
				
				system ("pause");
				system("cls");
				break;
			default: 
				printf ("\n\nOp��o inv�lida! digite novamente.\n\n");
				system("pause");
		}
	}while (Escolha!=6);
	
	return 0;
}
