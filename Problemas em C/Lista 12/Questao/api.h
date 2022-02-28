#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List Lista;

struct dados {
    int chave;

    char*  nome;
    float  pf;
    int    integer;
    char   c;
    int    tipo;
};

struct List {
    struct dados data;
    struct List *prox, *ante;
};

void   inicializar(Lista** list, int chave);
int    inserir_inteiro(Lista** list, int chave, int val);
int    inserir_p_flutuante(Lista** list, int chave, float val);
int    inserir_c_caracteres (Lista** list, int chave, char *val);
int    inserir_caractere(Lista **list, int chave, char val);

int    obter_tipo(Lista* list, int chave);
int    obter_inteiro(Lista* list, int chave);
float  obter_p_flutuante(Lista* list, int chave);
char*  obter_c_caracteres(Lista* list, int chave);
char   obter_caractere(Lista* list, int chave);
void   listar_elementos(Lista* list);

void   trocar(struct dados* a, struct dados* b);

char   menu();
void   await();