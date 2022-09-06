#include <iostream>
#include<stdlib.h>
#include<stdio.h>
// constante que define a dimensao da fila
#define DIMENSAO 5

// Criando estrutura da fila
typedef struct{
	int tamanho;
	int item[DIMENSAO];
} FILA;

int menu();
void inicializar(FILA &f2);
void adicionar(FILA &f2, int item);
bool filacheia(FILA &f2);
bool filavazia(FILA &f2);
void mostrarfila(FILA &f2);
int removerfila(FILA &f2);


// funcao principal
int main(int argc, char** argv) {
	FILA f; // f == variavel do tipo fila
	inicializar(f); //inicializar fila (f)
	int opcao;
	do{
		opcao = menu();
		
		switch(opcao){
			case 1:{
				inicializar(f);
				break;
			}
			case 2:{
				int item;
				printf("Digite um numero:\n");
				scanf("%i", &item);
				adicionar (f, item);
				break;
			}
			
			case 3:{
				mostrarfila(f);
				break;
			}
			
			case 4:{
				printf("item removido %i\n", removerfila(f));
				break;
			}
		}
	}while (opcao != 0);
	
	return 0;
}

// inicializar a estrutura de fila

void inicializar(FILA &f2){ // ponteiro que aponta para f, tudo que esta em f2(ponteiro) esta passando para f & == declarou ponteiro * == declarou ponteiro na variavel
	
	f2.tamanho = 0;
	printf("Fila inicializada com sucesso!\n");
	
}

// criar a funcao adicionar
void adicionar( FILA &f2, int item){
	
	if(filacheia(f2)){
		
	printf("A fila esta cheia nao pode adicionar!\n");
	} else {
		
	f2.item[f2.tamanho] = item; // f2 que guarda tamanho fica com o valor de item sendo que f2 acessa item (f2.item)
	f2.tamanho++;
	printf("Adicionado %i a fila!\n", item);
	}
	
	
}
bool filacheia(FILA &f2){
	
		return (f2.tamanho == DIMENSAO); // já retorna um valor bool não precisa declara um if	
}

bool filavazia(FILA &f2){
	
	return (f2.tamanho == 0);
}

// criar a funcao mostrar fila
void mostrarfila(FILA &f2){
	
	if(filavazia(f2)){
		
		printf("A fila esta vazia!\n");
		
	}else{
	
	int i;
	for(i = 0; i < f2.tamanho; i++){
		printf("%i", f2.item[i]);
		printf("\n");
		}
	}
	
}

// criar funcao remover da fila
int removerfila(FILA &f2){
	int item = f2.item[0];
	int i;
	
	for(i = 1; i < f2.tamanho; i++){
		f2.item[i - 1] = f2.item[i];
	}
	
	f2.tamanho--;
	return item;
		
}

// menu de opcoes
int menu(){
	int opcao;
	printf("1-Inicializar Fila\n");
	printf("2-Adicionar na Fila\n");
	printf("3-Mostrar a Fila\n");
	printf("4-Remover da Fila\n");
	printf("0-Sair da Fila\n");
	printf("Digite uma opcao\n");
	scanf("%i", &opcao);
	return opcao;
}

