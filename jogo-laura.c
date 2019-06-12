#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int setarPalavra(char palavra[], char secreta[]);
void gameOver(bool vitoria, char palavra[], int pontuacao, char tam);
void printarSecreta(char secreta[], char tam);

struct palavras{
	char nome[20];
	char tema[20];
};

int main() {
	struct palavras word[30];
	strcpy(word[0].nome, "ABACAXI");
	strcpy(word[0].tema, "FRUTA");
	strcpy(word[1].nome, "ACEROLA");
	strcpy(word[1].tema, "FRUTA");
	strcpy(word[2].nome, "BANANA");
	strcpy(word[2].tema, "FRUTA");
	strcpy(word[3].nome, "CARANBOLA");
	strcpy(word[3].tema, "FRUTA");
	strcpy(word[4].nome, "CAJU");
	strcpy(word[4].tema, "FRUTA");
	strcpy(word[5].nome, "JACA");
	strcpy(word[5].tema, "FRUTA");
	strcpy(word[6].nome, "MELAO");
	strcpy(word[6].tema, "FRUTA");
	strcpy(word[7].nome, "PERA");
	strcpy(word[7].tema, "FRUTA");
	strcpy(word[8].nome, "MANGA");
	strcpy(word[8].tema, "FRUTA");
	strcpy(word[9].nome, "GRAVIOLA");
	strcpy(word[9].tema, "FRUTA");
	// --------------------
	strcpy(word[10].nome, "GAIVOTA");
	strcpy(word[10].tema, "ANIMAL");
	strcpy(word[11].nome, "BALEIA");
	strcpy(word[11].tema, "ANIMAL");
	strcpy(word[12].nome, "ELEFANTE");
	strcpy(word[12].tema, "ANIMAL");
	strcpy(word[13].nome, "JUMENTO");
	strcpy(word[13].tema, "ANIMAL");
	strcpy(word[14].nome, "JABUTI");
	strcpy(word[14].tema, "ANIMAL");
	strcpy(word[15].nome, "PANTERA");
	strcpy(word[15].tema, "ANIMAL");
	strcpy(word[16].nome, "SAPO");
	strcpy(word[16].tema, "ANIMAL");
	strcpy(word[17].nome, "PATO");
	strcpy(word[17].tema, "ANIMAL");
	strcpy(word[18].nome, "URUBU");
	strcpy(word[18].tema, "ANIMAL");
	strcpy(word[19].nome, "OVELHA");
	strcpy(word[19].tema, "ANIMAL");
	// --------------------
	strcpy(word[20].nome, "AGULHA");
	strcpy(word[20].tema, "OBJETO");
	strcpy(word[21].nome, "ABAJUR");
	strcpy(word[21].tema, "OBJETO");
	strcpy(word[22].nome, "GARRAFA");
	strcpy(word[22].tema, "OBJETO");
	strcpy(word[23].nome, "VASSOURA");
	strcpy(word[23].tema, "OBJETO");
	strcpy(word[24].nome, "VENTILADOR");
	strcpy(word[24].tema, "OBJETO");
	strcpy(word[25].nome, "PENEIRA");
	strcpy(word[25].tema, "OBJETO");
	strcpy(word[26].nome, "JANELA");
	strcpy(word[26].tema, "OBJETO");
	strcpy(word[27].nome, "COLHER");
	strcpy(word[27].tema, "OBJETO");
	strcpy(word[28].nome, "ENXADA");
	strcpy(word[28].tema, "OBJETO");
	strcpy(word[29].nome, "CANETA");
	strcpy(word[29].tema, "OBJETO");
	/// -----------
	srand(time(NULL));
	char tam, letra, acertos = 0, erros = 3, palavra[20], secreta[20], tema[20], r = rand()%30;
	int valor = 300, pontuacao = 0;
	bool acerto = false;

	strcpy(palavra, word[r].nome);
	strcpy(tema, word[r].tema);

	tam = setarPalavra(palavra, secreta);
	
	while(acertos != tam && erros != 0){
		
		valor = (rand()%10+1)*100;
		
		printf("PONTOS: %d TAMANHHO: %d CHANCES: %d\n\n\n", pontuacao, tam, erros);
		
		printarSecreta(secreta, tam);
		
		printf("\n\n\nTEMA: %s VALOR: %d\nDIGITE UMA LETRA: ", tema,valor);
		scanf("%c%*c", &letra);
		letra = toupper(letra);
		
		for (int i = 0; i < tam; i++) {
			if (palavra[i] == toupper(letra)) {
				if(palavra[i] != secreta[i]){
					secreta[i] = letra;
					acertos++;
					pontuacao += valor;
				}
				acerto = true;
			}
		}
		if(!acerto){
			erros--;
		}
		acerto = false;
		system("cls");
	}
	
	if(acertos == tam) {
		gameOver(true, palavra, pontuacao, tam);	
	} else {
		gameOver(false, palavra,pontuacao, tam);	
	}
	
	return 0;
}

int setarPalavra(char palavra[], char secreta[]) {
	strcpy(secreta, palavra);
	char tam = strlen(palavra);
	for(int i = 0; i < tam; i++) {
		secreta[i] = '_';
	}
	return tam;
}

void gameOver(bool vitoria, char palavra[], int pontuacao, char tam) {
	//system("cls");
	if(vitoria) {
		printf("Pontos: %d\nVoce ganhou! a palavra era:\n\n", pontuacao);
		for(int i = 0; i < tam; i++) {
			printf("| %c |", palavra[i]);
		}
	} else {
		printf("Pontos: %d\nVoce perdeu! a palavra era:\n\n", pontuacao);
		for(int i = 0; i < tam; i++) {
			printf("| %c |", palavra[i]);
		}
	}
}

void printarSecreta(char secreta[], char tam){
	for(int i = 0; i < tam; i++){
		printf("| %c |", secreta[i]);
	}
}
