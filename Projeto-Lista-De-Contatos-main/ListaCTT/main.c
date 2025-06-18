#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCTT.h"

int main()
{
    //MENU
    int opcao, x;

     Lista *li = NULL;
    if ((li = criaLista()) == NULL) {
        abortaPrograma();
    }
    abrirLista(li);

    do{
        printf("MENU: \n\n");
        printf("1 - Inserir novo contato.\n");
        printf("2 - Exibir lista de contatos.\n");
        printf("3 - Buscar contato por codigo.\n");
        printf("4 - Buscar contato por nome.\n");
        printf("5 - Editar contato.\n");
        printf("6 - Remover contato.\n");
        printf("7 - Encerrar programa.\n");

        printf("\nSelecione uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

    switch (opcao){
    case 1: //inserir elemento
        x = insereOrdenado(li, coletaDados());
        system("cls");
            if (x) {
                printf("\nContato %d inserido com sucesso!", x);
            } else {
                printf("\nNao foi possivel inserir");
            }
        printf("\n\n\n\n\n\n\n\n\nPressione ENTER para continuar...");
        getchar();
        system("cls");
        break;
    case 2: //exibir lista de contatos
        x= mostraLista(li);
        printf("\n\n\n\n\n\n\n\n\nPressione ENTER para continuar...");
        getchar();
        getchar();
        system("cls");
        break;
    case 3: //buscar contato por codigo
        break;
    case 4: //buscar por nome
        break;
    case 5: //editar contato
        break;
    case 6: //remover contato
        break;
    case 7: //encerrar
        fecharLista(li);
        exit (0);
    default:
        printf("Opcao invalida!!");
        printf("\n\n\n\n\n\n\n\n\nPressione ENTER para continuar...");
        getchar();
        getchar();
        system("cls");
        break;

    }

    }while(opcao != 7);
}
