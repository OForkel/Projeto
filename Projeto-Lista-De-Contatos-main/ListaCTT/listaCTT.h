typedef struct Cliente{
    int id;
    char nome[100];
    char empresa[50];
    char departamento[50];
    char telefone[15];
    char celular[15];
    char email[50];
}CTT;

//funcoes lista dinamica

typedef struct elemento* Lista;

Lista *criaLista();

void abortaPrograma();

int tamanhoLista(Lista *li);

int listaVazia(Lista *li);

int insereOrdnado(Lista *li, CTT ct);

int removeOrdenado(Lista *li, int cod);

int consultaMat(Lista *li, int mat, CTT *ct);

void printConsulta(int a, CTT *ct);

CTT coletaDados();

//

