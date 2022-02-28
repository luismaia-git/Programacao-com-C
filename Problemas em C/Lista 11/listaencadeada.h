typedef struct _agenda {
    int matricula;
    char nome[20];
    int ddd;
    int telefone;
    char tipo[1];
    struct _agenda *prox;
} Agenda;


void ordenar(Agenda **);


Agenda *agd_inicializar();
Agenda receber_dados();
void receber_dados_arquivo(Agenda **);
void enviar_dados_arquivo(Agenda **);
int agd_inserir(Agenda **);
void agd_percorrer(Agenda *);
