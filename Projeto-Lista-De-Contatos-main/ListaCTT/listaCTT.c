#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCTT.h"

typedef struct elemento{
    CTT dados;
    struct elemento *prox;
}EL;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void abortaPrograma(){
    printf("Erro! Lista nao alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("pause");
    exit(1);
}

int listaVazia(Lista * li){
    if(li == NULL){
        abortaPrograma();
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int tamanhoLista(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    int ac = 0;
    EL *no = *li;
    while(no != NULL){
        ac++;
        no = no->prox;
    }
    return ac;
}

int insereOrdenado(Lista *li, CTT ct){
    if(li == NULL){
        abortaPrograma();
    }
    EL *no = (EL*) malloc(sizeof(EL));
    if(no == NULL){
        return 0;
    }
    no->dados = ct;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return ct.id;
    }else{
        EL *ant, *atual = *li;
        while(atual != NULL && atual->dados.id < ct.id){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return ct.id;
    }
}

int removeOrdenado(Lista *li, int cod){
    int id;
    if(li == NULL){
        abortaPrograma();
    }
    EL *ant, *no = *li;
    while(no != NULL && no->dados.id != cod){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    id = no->dados.id;
    free(no);
    return id;
}

int consultaMat(Lista *li, int cod, CTT *ct){
    if(li == NULL){
        abortaPrograma();
    }
    EL *no = *li;
    while(no != NULL && no->dados.id != cod){
        no = no->prox;
    }
    if(no != NULL){
        *ct = no->dados;
        return 1;
    }
    return 0;
}

void printConsulta(int a, CTT *ct){
        printf("\nCodigo: %d", ct->id);
        printf("\nNome:    %s", ct->nome);
        printf("\nEmpresa:    %s", ct->empresa);
        printf("\nDepartamento:    %s", ct->departamento);
        printf("\nTelefone:    %s", ct->telefone);
        printf("\nCelular:    %s", ct->celular);
        printf("\nE-mail:    %s", ct->email);
}

CTT coletaDados(){
    CTT c;
    printf("Insira os dados do cliente: \n\n");
    printf("Codigo: ");
    scanf("%d", &c.id);
    getchar();
    printf("Nome: ");
    fgets(c.nome, sizeof(c.nome), stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0';
    printf("Empresa: ");
    fgets(c.empresa, sizeof(c.empresa), stdin);
    c.empresa[strcspn(c.empresa, "\n")] = '\0';
    printf("Telefone: ");
    fgets(c.telefone, sizeof(c.telefone), stdin);
    c.telefone[strcspn(c.telefone, "\n")] = '\0';
    printf("Celular: ");
    fgets(c.celular, sizeof(c.celular), stdin);
    c.celular[strcspn(c.celular, "\n")] = '\0';
    printf("Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';


    return c;
}


void mostraLista(Lista *li) {
    if (li == NULL) {
        abortaPrograma();
    }
    else if ((*li) == NULL) {
        printf("A lista esta vazia");
    }
    else{
    EL *no = *li;
    printf("========== Lista de Contatos ==========\n");
    while (no != NULL) {
        printf("Codigo: %d\n", no->dados.id);
        printf("Nome: %s\n", no->dados.nome);
        printf("Empresa: %s\n", no->dados.empresa);
        printf("Telefone: %s\n", no->dados.telefone);
        printf("Celular: %s\n", no->dados.celular);
        printf("Email: %s\n\n\n\n", no->dados.email);

        no = no->prox;}
    }
}

void fecharLista(Lista *li) {
    FILE *arquivo = fopen("listasalva.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao salvar a lista\n");
        return;
    }

    EL *no = *li;
    while (no != NULL) {
        fwrite(&no->dados, sizeof(CTT), 1, arquivo);
        no = no->prox;
    }

    fclose(arquivo);
    printf("\nLista salva com sucesso!\n");
}

void abrirLista(Lista *li) {
    FILE *arquivo = fopen("listasalva.dat", "rb");
    if (arquivo == NULL) {
        printf("\nNenhuma lista encontrada, iniciando lista nova\n");
        printf("\n\n\n\n\n\n\n\n\nPressione ENTER para continuar...");
        getchar();
        system("cls");
        return;
    }
    CTT carregar;
    while (fread(&carregar, sizeof(CTT), 1, arquivo)) {
        insereOrdenado(li, carregar);
    }

    fclose(arquivo);
    printf("\nLista carregada com sucesso!\n");
    printf("\n\n\n\n\n\n\n\n\nPressione ENTER para continuar...");
    getchar();
    system("cls");
}


