//
//  main.c
//  ProjetoC
//
//  Created by Leandro Silva Soares on 09/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Client.h"
#include "ClientCollection.h"

#ifdef _WIN32
//define something for Windows (32-bit and 64-bit, this part is common)
void s_pause(){ system("pause");}
void s_exit() { system("exit");}
void s_clear() { system("cls");}
#ifdef _WIN64
//define something for Windows (64-bit only)
#endif
#elif __APPLE__
void s_pause(){
    printf("Pressione enter para continuar...\n");
    getchar();
    getchar();
}
void s_exit() { system("kill -9 $(ps -p $(ps -p $PPID -o ppid=) -o ppid=)");}
void s_clear() { system("clear");}
#else
#   error "Unknown compiler"
#endif


int main(int argc, const char * argv[]) {

    ClientCollection * collection;
    FILE *save;

    printf("Carregando arquivo de save...\n");

    save = fopen("save.txt", "r");

    collection = newClientCollectionFromDATA(save);

    fclose(save);

    printf("Arquivo arquivo carregado!\n");

    //inicia programa

    int choice = -1;
    Client cli;

    int index;

    do {
        s_clear();
        printf("1 - Novo contato\n");
        printf("2 - Ver todos\n");
        printf("3 - Ver contato por index\n");
        printf("4 - Ver contato por nome completo\n");
        printf("5 - Editar contato\n");
        printf("6 - Deletar contato\n");
        printf("0 - Sair\n");

        scanf("%d",&choice);

        s_clear();

        switch (choice) {
            case 1:
                printf("Novo contato\n");
                getClientFromUser(&cli);
                push(collection, cli);
                printf("Cliente adicionado!\n");
                break;

            case 2:
                printAllClients(collection);
                break;

            case 3:
                printf("Procurando client por index.\nDigite o index: ");
                scanf("%d", &index);
                cli = getClientByIndex(collection, index);
                printClient(cli);
                break;

            case 4:
                printf("Procurando client por nome completo.\nDigite o nome: ");
                char nome[30];
                getchar();
                fgets(nome, 30, stdin);
                Client *ccc;
                ccc = getClientByNome(collection, nome);
                if (ccc!=NULL) {
                    printClient((*ccc));
                }
                break;

            case 5:
                printf("Atualizar contato\n");
                printf("Procurando client por index.\nDigite o index: ");
                scanf("%d", &index);
                updateClientByIndex(collection, index);
                printf("Cliente Atualizado!\n");
                break;

            case 6:
                printf("Deletando cliente por index.\nDigite o index: ");
                scanf("%d", &index);
                deleteClientByIndex(collection, index);
                break;

            case 0:
                save = fopen("save.txt", "w");
                printf("\n\nSalvando dados...\n\n");
                saveCollectionToFile(save, collection);
                fclose(save);
                printf("\n\nDados salvos com sucesso...\n\n");

                break;

            default:
                printf("Opção %d invalida\n", choice);
                break;
        }
        s_pause();
    } while (choice !=0);



    return 0;
}
