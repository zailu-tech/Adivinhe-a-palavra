#include <stdio.h> // Incluindo a biblioteca padrão de entrada e saída
#include <string.h> // Incluindo a biblioteca para manipulação de strings
#include <stdlib.h> // Incluindo a biblioteca padrão
#include <ctype.h> // Incluindo a biblioteca para manipulação de caracteres


#define MAX_TENTATIVAS 5 // Definindo o número máximo de tentativas

int main(){

 char *palavras[]= {"Lua", "Sol", "Planeta", "Terra", "gato", "Sapato", "Estrela", "hora"}; // Palavra a ser adivinhada
 char *palavra = palavras[rand() % 8]; // Palavra a ser adivinhada
 char tentativasFeitas[strlen(palavra) +1]; // Vetor para armazenar as tentativas feitas
int tentativas = 0; // Número de tentativas feitas
int acertos = 0; // Número de acertos
int tamanhoPalavra = strlen (palavra); // Tamanho da palavra


for(int i = 0; i < tamanhoPalavra; i++){ // Inicializando o vetor de tentativas feitas
    tentativasFeitas[i] = '-';

}

tentativasFeitas[tamanhoPalavra]= '\0'; // Adicionando o caractere nulo ao final da string

printf("Bem vindo ao jogo da forca!\n");

while(tentativas < MAX_TENTATIVAS){ // Enquanto o número de tentativas for menor que o máximo
    printf("\nPalavra: %s\n", tentativasFeitas); // Exibindo a palavra com as tentativas feitas
    printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas); // Exibindo o número de tentativas restantes
    printf("Digite uma letra: "); // Solicitando uma letra

    char tentativa;      // Lendo a tentativa 
    scanf(" %c", &tentativa); 
    tentativa= tolower(tentativa); // Convertendo a tentativa para minúscula

    int encontrado =0; // Verificando se a letra foi encontrada
    for(int i = 0; i < tamanhoPalavra; i++){ // Verificando se a letra foi encontrada
        if(tolower(palavra[i]) == tentativa && tentativasFeitas[i] == '-'){ 
            tentativasFeitas[i] = tentativa; 
            acertos++;
            encontrado = 1; 
        }
    }
    if(!encontrado){ // Se a letra não foi encontrada
        tentativas++;
    }
    if(acertos == tamanhoPalavra){
        printf("\nParabéns! Você acertou! A palavra secreta era: %s\n", palavra);
        break;
    }
}
if(acertos < tamanhoPalavra){ // Se o número de acertos for menor que o tamanho da palavra
    printf("\nQue pena! Você perdeu! A palavra era: %s\n", palavra);
}

return 0;

}