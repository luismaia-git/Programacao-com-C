#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXNOME 100

struct _agenda {
    int matricula;
    char nome[MAXNOME];
    int DDD;
    int tel_num;
    char tipo;
};

typedef struct _agenda Agenda;
#define MAXREGISTRO 1000

Agenda* tab[MAXREGISTRO];


void inicializa(int n, Agenda* tab[MAXREGISTRO]){
  int i;
  for(i=0; i<n; i++){
    tab[i] = NULL;
  }
}

void preencher (Agenda* tab[MAXREGISTRO], int i){
  
  tab[i] = (Agenda*) malloc(sizeof(Agenda));

  printf("Entre com a matricula: ");
  scanf("%d", &tab[i]->matricula);
  
  printf("Entre com o nome: ");
  scanf("%s", tab[i]->nome);

  printf("Entre com o DDD: ");
  scanf("%d", &tab[i]->DDD);

  printf("Entre com o telefone: ");
  scanf("%d", &tab[i]->tel_num);
  
  printf("Entre com o tipo ('C' ou 'F'): ");
  scanf(" %c", &tab[i]->tipo);
  getchar();
}




void imprime(int n , Agenda* tab[MAXREGISTRO], int i ){
  if(i< 0 || i>=n) {
    printf("Indice fora do limite do vetor\n");
    exit(1);
  }
  if (tab[i] != NULL){
    printf("Matricula: %d\n", tab[i]-> matricula);
    printf("Nome: %s\n", tab[i]-> nome);
    printf("DDD: %d\n", tab[i]-> DDD);
    printf("Telefone: %d\n", tab[i]-> tel_num);
    printf("Tipo: %c\n", tab[i]-> tipo);
  }
}
void imprimeTudo(int n, Agenda* tab[MAXREGISTRO]){
  for(int i=0; i < n; i++) {
    imprime(n, tab, i);
    printf("\n");
  }
}

void ler_arquivo(char arq[]){
  FILE *fp = fopen(arq, "r");

  if (fp == NULL) { 
    printf("Erro na abertura do arquivo.\n"); 
    return; // Aborta o programa 
  } // Abre o arquivo de texto entrada.txt para leitura 

  int i= 0;
  tab[i] = (Agenda*) malloc(sizeof(Agenda));
  while(fscanf(fp, "%d", &tab[i]->matricula) != EOF) {
      fscanf(fp, "%s", tab[i]->nome);
      fscanf(fp, "%d", &tab[i]->DDD);
      fscanf(fp, "%d", &tab[i]->tel_num);
      fscanf(fp, " %c", &tab[i]->tipo);
      i++;
      tab[i] = (Agenda*) malloc(sizeof(Agenda));
  };

}

int menu(){
  char c;
  system("clear||cls");
  printf("Digite A para apagar registro pelo nome\n");
  printf("Digite B para buscar telefone pelo nome\n");
  printf("Digite I para inserir novo registro\n");
  printf("Digite L para listar nomes na agenda\n");
  scanf(" %c", &c);
  getchar();
  return c;
}

void retira(Agenda* tab[MAXREGISTRO], int i){
  free(tab[i]);
  tab[i] = NULL; 
}

int busca(char* entrada_nome, Agenda* tab[MAXREGISTRO]){
    for (int i=0; i<MAXREGISTRO; i++) {
      if(tab[i] != NULL && strcmp(tab[i]->nome, entrada_nome) == 0){ /*strcmp eh o mesmo que usar o for para comparar strings*/
        return i;
      }
    }
    return -1;
}

int busca_telefone(char* entrada_nome, Agenda* tab[MAXREGISTRO]){
  for(int i=0; i<MAXREGISTRO; i++){
    if(tab[i] != NULL && strcmp(tab[i]->nome, entrada_nome) == 0) {
      return i;
    }
  }
  return -1;
}
  
  
void inserir(Agenda* tab[MAXREGISTRO]){
  for(int i=0; i<MAXREGISTRO; i++){
  
    if (tab[i] == NULL) {
      preencher(tab,i);
      break;
    } 

  }
}


//./main olamundo.txt
int main (int argc, char *argv[]) {

  if (argc >= 2 ) {
    printf("Nome do programa: %s\n", argv[0]);
    printf("Primeiro argumento: %s\n", argv[1]);
    printf("\n");
    ler_arquivo(argv[1]);
  }

  int i=1;
  char entrada_nome[100];
  while(i){
  
    switch(menu()){
      case 'A': {
        printf("Digite o nome referente ao registro que voce deseja apagar\n");
        scanf("%s", entrada_nome);
        int aux = busca(entrada_nome, tab);
        if (aux != -1) {
          retira(tab,aux);
        }
        else
          printf("Nao existe");
        getchar();
        break;
      }
      case 'B': {
        printf("Digite o nome referente ao telefone que voce deseja encontrar\n");
        scanf("%s", entrada_nome);
        getchar();
        int i = busca_telefone(entrada_nome,tab);
        if (i != -1){
          
          if (tab[i]-> tipo == 'C'){
            printf("%s - (%d) %d (celular)\n", tab[i]->nome, tab[i]->DDD, tab[i]-> tel_num);
          }
          else
            printf("%s - (%d) %d (fixo)\n", tab[i]->nome, tab[i]->DDD, tab[i]-> tel_num);

        }
        else
          printf("nao existe");
        
        getchar();
        break;
      }
      case 'I': {
        inserir(tab);
        printf("Registro inserido com sucesso\n");
        getchar();
        break;
      }
      case 'L': {
        for(int i = 0; i < MAXREGISTRO; i++){
          if (tab[i] != NULL)
          printf("%s\n\n", tab[i]->nome);
        }
        getchar();
        break;
      }
    }
  }

  return EXIT_SUCCESS;
}




