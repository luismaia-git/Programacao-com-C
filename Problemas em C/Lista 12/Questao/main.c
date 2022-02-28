#include "api.h"

#define debug(msg) printf(msg)

void inicializar(Lista** list, int chave) {
    (*list)->prox       = (*list);
    (*list)->ante       = (*list);
    (*list)->data.chave = chave;
}

void trocar(struct dados* a, struct dados* b) {
    struct dados temp = *a;
    *a = *b;
    *b = temp;
}

// pointer to pointer scheme:
// ptr -> mem -> mem -> value

int inserir_inteiro(Lista** list, int chave, int val) {
    Lista* ptr = (*list);

    if((*list) == NULL) {
        (*list) = (Lista*)malloc(sizeof(Lista));
        if((*list) == NULL)
            return 0;
        inicializar(list, chave);
        (*list)->data.integer = val;
        (*list)->data.tipo = 1;
        return 1;
    } else {
        Lista* ptr = (*list);

        if(ptr != NULL && ptr->data.chave == chave)
            return 0;

        if(ptr->prox->data.chave > chave) {
            Lista* temp = (Lista*)malloc(sizeof(Lista));
            if(temp == NULL)
                return 0;
            inicializar(&temp, chave);
            temp->data.integer = val;
            temp->prox      = ptr->prox;
            temp->ante      = ptr;
            ptr->prox       = temp;
            temp->data.tipo = 1;
            trocar(&temp->data, &ptr->data);

            return 1;
        }

        while(ptr->prox != (*list)) {
            if(ptr->prox->data.chave > chave) {
                Lista* temp = (Lista*)malloc(sizeof(Lista));
                inicializar(&temp, chave);
                temp->data.integer = val;
                // vou inserir o x
                // ptr -> x -> ptr->prox
                // ptr -> x -> ptr->prox
                temp->prox      = ptr->prox;
                temp->ante      = ptr;
                ptr->prox->ante = temp;
                ptr->prox       = temp;
                temp->data.tipo = 1;

                return 1;
            } else if(ptr->prox->data.chave == chave)
                return 0;
            ptr = ptr->prox;
        }
        // se cheguei aqui então sou o último nó

        Lista* temp = (Lista*)malloc(sizeof(Lista)); // escopo diferente, sem problemas declarar o mesmo nome..
        if(temp == NULL)
            return 0;
        inicializar(&temp, chave);
        temp->data.tipo    = 1;
        ptr->prox          = temp;
        temp->ante         = ptr;
        temp->data.integer = val;
        temp->prox         = (*list); // circular
        return 1;
    }
}

int inserir_p_flutuante(Lista **list, int chave, float val) {
    Lista* ptr = (*list);

    if((*list) == NULL) {
        (*list) = (Lista*)malloc(sizeof(Lista));
        if((*list) == NULL)
            return 0;
        inicializar(list, chave);
        (*list)->data.pf = val;
        (*list)->data.tipo = 2;
        return 1;
    } else {
        Lista* ptr = (*list);

        if(ptr != NULL && ptr->data.chave == chave)
            return 0;

        if(ptr->prox->data.chave > chave) {
            Lista* temp = (Lista*)malloc(sizeof(Lista));
            if(temp == NULL)
                return 0;
            inicializar(&temp, chave);
            temp->data.pf   = val;
            temp->prox      = ptr->prox;
            temp->ante      = ptr;
            ptr->prox       = temp;
            temp->data.tipo = 2;
            trocar(&temp->data, &ptr->data);

            return 1;
        }

        while(ptr->prox != (*list)) {
            if(ptr->prox->data.chave > chave) {
                Lista* temp = (Lista*)malloc(sizeof(Lista));
                inicializar(&temp, chave);
                temp->data.pf      = val;
                temp->prox         = ptr->prox;
                temp->ante         = ptr;
                ptr->prox->ante    = temp;
                ptr->prox          = temp;
                temp->data.tipo    = 2;

                return 1;
            } else if(ptr->prox->data.chave == chave)
                return 0;
            ptr = ptr->prox;
        }

        Lista* temp = (Lista*)malloc(sizeof(Lista));
        if(temp == NULL)
            return 0;
        inicializar(&temp, chave);
        temp->data.tipo    = 2;
        ptr->prox          = temp;
        temp->ante         = ptr;
        temp->data.pf      = val;
        temp->prox         = (*list); // circular
        return 1;
    }

    return 0;
}

int inserir_c_caracteres(Lista** list, int chave, char *val) {
    Lista* ptr = (*list);

    if((*list) == NULL) {
        (*list) = (Lista*)malloc(sizeof(Lista));
        if((*list) == NULL)
            return 0;
        inicializar(list, chave);
        (*list)->data.nome = (char*)malloc(strlen(val));
        strcpy((*list)->data.nome, val);
        (*list)->data.tipo = 3;
        return 1;
    } else {
        Lista* ptr = (*list);

        if(ptr != NULL && ptr->data.chave == chave)
            return 0;

        if(ptr->data.chave > chave) {
            Lista* temp = (Lista*)malloc(sizeof(Lista));
            if(temp == NULL)
                return 0;
            inicializar(&temp, chave);
            temp->data.nome = (char*)malloc(strlen(val));
            strcpy(temp->data.nome, val);
            temp->prox      = ptr->prox;
            temp->ante      = ptr;
            ptr->prox       = temp;
            temp->data.tipo = 3;
            trocar(&temp->data, &ptr->data);
            return 1;
        }

        while(ptr->prox != (*list)) {
            if(ptr->prox->data.chave > chave) {
                Lista* temp = (Lista*)malloc(sizeof(Lista));
                if(temp == NULL)
                    return 0;
                inicializar(&temp, chave);
                temp->data.nome = (char*)malloc(strlen(val));
                strcpy(temp->data.nome, val);
                // vou inserir o x
                // ptr -> x -> ptr->prox
                // ptr -> x -> ptr->prox
                temp->prox      = ptr->prox;
                temp->ante      = ptr;
                ptr->prox->ante = temp;
                ptr->prox       = temp;
                temp->data.tipo = 3;

                return 1;
            } else if(ptr->prox->data.chave == chave)
                return 0;
            ptr = ptr->prox;
        }
        // se cheguei aqui então sou o último nó

        Lista* temp = (Lista*)malloc(sizeof(Lista)); // escopo diferente, sem problemas declarar o mesmo nome..
        if(temp == NULL)
            return 0;
        inicializar(&temp, chave);
        temp->data.nome    = (char*)malloc(strlen(val));
        temp->data.tipo    = 3;
        ptr->prox          = temp;
        temp->ante         = ptr;
        strcpy(temp->data.nome, val);
        temp->prox = (*list); // circular
        return 1;
    }

    return 0;
}

int inserir_caractere(Lista **list, int chave, char val) {
    Lista* ptr = (*list);

    if((*list) == NULL) {
        (*list) = (Lista*)malloc(sizeof(Lista));
        if((*list) == NULL)
            return 0;
        inicializar(list, chave);
        (*list)->data.c       = val;
        (*list)->data.tipo    = 4;
        return 1;
    } else {
        Lista* ptr = (*list);

        if(ptr != NULL && ptr->data.chave == chave)
            return 0;

        if(ptr->prox->data.chave > chave) {
            Lista* temp = (Lista*)malloc(sizeof(Lista));
            if(temp == NULL)
                return 0;
            inicializar(&temp, chave);
            temp->data.c    = val;
            temp->prox      = ptr->prox;
            temp->ante      = ptr;
            ptr->prox       = temp;
            temp->data.tipo = 4;
            trocar(&temp->data, &ptr->data);

            return 1;
        }

        while(ptr->prox != (*list)) {
            if(ptr->prox->data.chave > chave) {
                Lista* temp = (Lista*)malloc(sizeof(Lista));
                inicializar(&temp, chave);
                // vou inserir o x
                // ptr -> x -> ptr->prox
                // ptr -> x -> ptr->prox
                temp->data.c    = val;
                temp->prox      = ptr->prox;
                temp->ante      = ptr;
                ptr->prox->ante = temp;
                ptr->prox       = temp;
                temp->data.tipo = 4;

                return 1;
            } else if(ptr->prox->data.chave == chave)
                return 0;
            ptr = ptr->prox;
        }
        // se cheguei aqui então sou o último nó

        Lista* temp = (Lista*)malloc(sizeof(Lista)); // escopo diferente, sem problemas declarar o mesmo nome..
        if(temp == NULL)
            return 0;
        inicializar(&temp, chave);
        temp->data.tipo    = 4;
        ptr->prox          = temp;
        temp->ante         = ptr;
        temp->data.c       = val;
        temp->prox         = (*list); // circular
        return 1;
    }

    return 0;
}

int obter_tipo(Lista* list, int chave) {
    Lista* ptr = list;
    if(list == NULL)
        return -99999;
    if(list->data.chave == chave)
        return list->data.tipo;
    list = list->prox;    
    while(list != ptr) {
        if(list->data.chave == chave)
            return list->data.tipo;
        list = list->prox; 
    }

    return -99999;
}

int obter_inteiro(Lista* list, int chave) {
    Lista* ptr = list;
    if(list == NULL)
        return -99999;
    if(list->data.chave == chave) {
        if(list->data.tipo == 1)
            return list->data.integer;
        return -99999;
    }
    list = list->prox;    
    while(list != ptr) {
        if(list->data.chave == chave) {
            if(list->data.tipo == 1)
                return list->data.integer;
            return -99999;
        }
        list = list->prox; 
    }

    return -99999;
}

float obter_p_flutuante(Lista* list, int chave) {
    Lista* ptr = list;
    if(list == NULL)
        return -99999.f;
    if(list->data.chave == chave) {
        if(list->data.tipo == 2)
            return list->data.pf;
        return -99999.f;
    }
    list = list->prox;    
    while(list != ptr) {
        if(list->data.chave == chave) {
            if(list->data.tipo == 2)
                return list->data.pf;
            return -99999.f;
        }
        list = list->prox; 
    }

    return -99999.f;
}

char* obter_c_caracteres(Lista* list, int chave) {
    Lista* ptr = list;
    if(list == NULL)
        return NULL;
    if(list->data.chave == chave) {
        if(list->data.tipo == 3)
            return list->data.nome;
        return NULL;
    }
    list = list->prox;    
    while(list != ptr) {
        if(list->data.chave == chave) {
            if(list->data.tipo == 3)
                return list->data.nome;
            return NULL;
        }
        list = list->prox; 
    }

    return NULL;
}

char obter_caractere(Lista* list, int chave) {
    Lista* ptr = list;
    if(list == NULL)
        return 0;
    if(list->data.chave == chave) {
        if(list->data.tipo == 4)
            return list->data.c;
        return 0;
    }
    list = list->prox;    
    while(list != ptr) {
        if(list->data.chave == chave) {
            if(list->data.tipo == 4)
                return list->data.c;
            return 0;
        }
        list = list->prox; 
    }

    return 0;
}

void mostrar_elemento(struct dados data) {
    switch (data.tipo) {
    case 1:
        printf("Chave: %d Inteiro: %d\n", data.chave, data.integer);
        break;
    case 2:
        printf("Chave: %d Ponto Flutuante: %f\n", data.chave, data.pf);
        break;
    case 3:
        printf("Chave: %d Cadeia de caracteres: %s\n", data.chave, data.nome);
        break;
    case 4:
        printf("Chave: %d Caractere: %c\n", data.chave, data.c);
        break;
    }
}

void listar_elementos(Lista* list) {
    if(list == NULL)
        return;

    Lista* ptr = list;

    do {
        mostrar_elemento(list->data);
        list = list->prox;
    } while(list != ptr);
}

void await() {
    printf("\nAperte Enter:\n");
    char c;
    while((c = getchar()))
        if(c == '\n')
            return;
}

char menu() {
    system("clear");
    printf("------------- MENU -------------\n");
    printf("Inserir inteiro: 1\n");
    printf("Inserir ponto-flutuante: 2\n");
    printf("Inserir cadeia de caracteres: 3\n");
    printf("Inserir caractere: 4\n");
    printf("Obter inteiro: 5\n");
    printf("Obter ponto-flutuante: 6\n");
    printf("Obter cadeia de caracteres: 7\n");
    printf("Obter caractere: 8\n");
    printf("Listar elementos: 9\n");
    printf("Sair: quit\n\n");

    char command[100];
    fgets(command, 100, stdin);

    if(command[strlen(command)-1] == '\n')
        command[strlen(command)-1] = 0;

    if(strcmp(command, "quit") == 0)
        return -1;
    return command[0];
}

int main() {
    Lista* list = NULL;

    int running = 1;

    while(running) {
        switch (menu()) {

        case '1': {
            int chave, valor;
            printf("Digite uma chave e um inteiro:\n");
            scanf("%d", &chave);
            scanf("%d", &valor);
            getchar();
            if(inserir_inteiro(&list, chave, valor) == 0)
                printf("o valor não foi inserido com sucesso!\n");
            else
                printf("valor inserido com sucesso!\n");
            await();
            break;
        }
        
        case '2': {
            int   chave;
            float value;
            printf("Digite uma chave e um ponto-flutuante:\n");
            scanf("%d", &chave);
            scanf("%f", &value);
            getchar();
            if(inserir_p_flutuante(&list, chave, value) == 0)
                printf("o valor não foi inserido com sucesso!\n");
            else
                printf("valor inserido com sucesso!\n");
            await();
            break;
        }

        case '3': {
            int  chave;
            char valor[100];
            printf("Digite uma chave e uma cadeia de caracteres:\n");
            scanf("%d", &chave);
            getchar();
            fgets(valor, 100, stdin);
            if(valor[strlen(valor)-1] == '\n') {
                valor[strlen(valor)-1] = 0;
            }
            if(inserir_c_caracteres(&list, chave, valor) == NULL)
                printf("o valor não foi inserido com sucesso!\n");
            else
                printf("valor inserido com sucesso!\n");
            await();
            break;
        }

        case '4': {
            int   chave;
            char value;
            printf("Digite uma chave e um caractere:\n");
            scanf("%d", &chave);
            scanf(" %c", &value);
            getchar();
            if(inserir_caractere(&list, chave, value) == 0)
                printf("o valor não foi inserido com sucesso!\n");
            else
                printf("valor inserido com sucesso!\n");
            await();
            break;
        }

        case '5': {
            int chave;
            printf("Digite a chave:\n");
            scanf("%d", &chave);
            getchar();
            int aux;
            if((aux = obter_inteiro(list, chave)) == -99999)
                printf("valor não encontrado!\n");
            else
                printf("valor encontrado: %d\n", aux);
            await();
            break;
        }

        case '6': {
            int chave;
            printf("Digite a chave:\n");
            scanf("%d", &chave);
            getchar();
            float aux;
            if((aux = obter_p_flutuante(list, chave)) == -99999.f)
                printf("valor não encontrado!\n");
            else
                printf("valor encontrado: %f\n", aux);
            await();
            break;
        }
        
        case '7': {
            int chave;
            printf("Digite a chave:\n");
            scanf("%d", &chave);
            getchar();
            char *aux;
            if((aux = obter_c_caracteres(list, chave)) == NULL)
                printf("valor não encontrado!\n");
            else
                printf("valor encontrado: %s\n", aux);
            await();
            break;
        }

        case '8': {
            int chave;
            printf("Digite a chave:\n");
            scanf("%d", &chave);
            getchar();
            char aux;
            if((aux = obter_caractere(list, chave)) == 0)
                printf("valor não encontrado!\n");
            else
                printf("valor encontrado: %c\n", aux);
            await();
            break;
        }

        case '9': {
            printf("\n");
            listar_elementos(list);
            printf("\n");
            await();
            break;
        }

        case -1: {
            running = 0;
            break;
        }
        
        }
    }

    return 0;
}