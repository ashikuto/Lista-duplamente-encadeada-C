#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <locale.h>

//estrutura da lista
struct lista{
	int numero_matricula;
	char nome[80];
	float media;
	struct lista * next;
	struct lista * previous;
};
typedef struct lista Lista;
//estrutura da lista

//funções
bool vazia(Lista * pL);
Lista * inserirComeco(Lista * pL, int elemento1, char elemento2[], float elemento3);
void imprimir(Lista * pL);
Lista * buscar(Lista * pL, int valor);
Lista * remover(Lista * pL, int valor);
Lista * inserirFinalDaLista(Lista * pL, int elemento1, char elemento2[], float elemento3);
Lista * separarLista(Lista * pL, int valor);
Lista * inicializaLista();
//funções


int main(){

setlocale(LC_ALL, "Portuguese");

	Lista * L, *Q;
	Lista * ULTIMO;
	Lista * AUX;
	int valor, mat;
	float valor3;
	char nome[80];
	L = inicializaLista();

do{
		
	printf("\nMenu:\n\n");
	imprimir(L);
	printf("\n");
	printf("\n\t0 - Sair\n\t1 - Inserir_Inicio\n\t2 - inserir_Fim\n\t3 - Remover\n\t4 - Imprimir\n\t5 - Buscar\n\t6 - Verificar_Lista\n\t7 - Separar_Lista\n\n\tOpção:");
	
	scanf("%d", &valor);
	
	switch(valor){
		
	case 1: //inserir no começo da lista
		system("cls");
		printf("Digite o Nome! : ");
		scanf("%s", &nome);
		printf("Digite a matricula : ");
		scanf("%d", &mat);
		printf("Digite a média! : ");
		scanf("%f", &valor3);
		system("cls");
		L = inserirComeco(L, mat,nome, valor3);
	break;	
	
	case 2:// inserir no fim da lista
		system("cls");
		printf("Digite o Nome! : ");
		scanf("%s", &nome);
		printf("Digite a matricula : ");
		scanf("%d", &mat);
		printf("Digite a média! : ");
		scanf("%f", &valor3);
		system("cls");
		L = inserirFinalDaLista(L, mat,nome, valor3);
	break;	
	
	case 3: // remover elemento da lista
		system("cls");
		printf("Digite o Nome! : ");
		scanf("%s", &nome);
		printf("Digite a matricula : ");
		scanf("%d", &mat);
		printf("Digite a média! : ");
		scanf("%f", &valor3);
		system("cls");
		L = remover(L, mat);
	break;	
	
	case 4: // imprimir lista
		system("cls");
		imprimir(L);
	break;	
	
	case 5: //buscar na lista
	system("cls");
	printf("Digite o valor! /n");
		scanf("%d", &mat);
		system("cls");
	Q = buscar(L,mat);
	if(Q != NULL)
		printf("\nElemento %d contido na lista! \n", Q->numero_matricula);
	else
		printf("\nElemento nao encontrado! \n");
	break;	
	
	case 6: // verificar se lista = vazia
		system("cls");
		if(vazia(&L))
		printf("Lista Vazia! \n");
	else
		printf("Lista com elementos! \n");
	break;
	
	case 7: //Separar
		system("cls");
		printf("Digite o valor! /n");
		scanf("%d", &mat);
		AUX = separarLista(L, mat);
	if(AUX != NULL){
		printf("\nImprimindo a Lista Original: " );
		imprimir(L);
		printf("\nImprimindo a Lista Auxiliar: " );
		imprimir(AUX);
	}
	break;	
	
	default:
		if(valor != 0)
		printf("Opção inválida!!\n");
	break;	
		
	}
	
}while(valor !=0);

	return 0;
}

bool vazia(Lista * pL){
	if(pL->numero_matricula == NULL)
		return true;
	else
		return false;
}


Lista * inserirComeco(Lista * pL, int elemento1, char elemento2[], float elemento3){
	Lista * novo;
	novo = (Lista *) malloc(sizeof(Lista));
	
	if(novo != NULL){
		novo->numero_matricula = elemento1;
		strcpy(novo->nome, elemento2);
		novo->media = elemento3;
		novo->next = pL;
		novo->previous = NULL;
		if(pL != NULL)
			pL->previous = novo;
		printf(" Elemento inserido na lista = [%d] ", novo->numero_matricula);
		return novo;
	}
}

void imprimir(Lista * pL){
	printf("\nLista Completa: ");
	while(pL != NULL){
		printf("\n\n");
		printf("|Matricula: %d ", pL->numero_matricula);
		printf("Nome: %s  ", pL->nome);
		printf("Media:%.2f| -> ", pL->media);
		printf("\n");
		pL = pL->next;	
	}
}

Lista * buscar(Lista * pL, int valor){
	while(pL != NULL){
		if(pL->numero_matricula == valor)
			return pL;
		pL = pL->next;
	}
	return NULL;
}

Lista * remover(Lista * pL, int valor){
	Lista * p = pL;
	
	while(p != NULL && p->numero_matricula != valor){
		p = p->next;
	}
	if(p == NULL) // que nao existe na lista o dado
		return pL;
	else
		if(p->previous == NULL){ //é o primeiro da lista a ser removido
			p->next->previous = p->previous;
			pL = p->next;
		}
		else 
			if (p->next != NULL){
				p->next->previous = p->previous; // qualquer outro da lista a ser removido
				p->previous->next = p->next;
			}
			else{
				p->previous->next = p->next;
			}

		free(p);
		printf(" Elemento removida da lista = [%d] ", valor);
		return pL;	
}

Lista * inserirFinalDaLista(Lista * pL, int elemento1, char elemento2[], float elemento3){
	Lista *novo = (Lista *) malloc(sizeof(Lista));
	
	if(novo != NULL){		
		novo->numero_matricula = elemento1;
		strcpy(novo->nome, elemento2);
		novo->media = elemento3;
		novo->next = NULL;
				
		if(pL == NULL){
			pL = novo;
			novo->previous = NULL;
		}
		
		else{
			
			while(pL->next != NULL){
			pL = pL -> next;
		}
		
			pL->next = novo;
			novo->previous = pL;
				while(pL->previous != NULL){
			pL = pL -> previous;		
		}
	}
	return pL;
	
}
}

Lista * separarLista(Lista * pL, int valor){
	Lista * p = pL;
	Lista * aux;

	if(vazia(pL))
		return NULL;
	else{
		while(p != NULL){
			if(p->numero_matricula == valor){
				aux = p->next;
				p->next = NULL;
				return aux;
			}
			p = p->next;
		}
		return NULL;
	}
}

Lista * inicializaLista(){
	return NULL;
}
