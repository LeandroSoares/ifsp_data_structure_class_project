//
//  main.c
//  ProjetoC
//
//  Created by Leandro Silva Soares on 09/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include <stdio.h>
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

    Client c1,c2,c3;
    c1 = newClient(0, "Leandro", "ACME.SA", "RD", "55 11 2222 3333", "55 11 95774 6243", "leandro@acmesa.com");
    c2 = newClient(0, "Leandro", "ACME.SA", "RD", "55 11 2222 3333", "55 11 95774 6243", "leandro@acmesa.com");
    c3 = newClient(0, "Leandro", "ACME.SA", "RD", "55 11 2222 3333", "55 11 95774 6243", "leandro@acmesa.com");
    
    ClientCollection * collection = newClientCollection();
    push(collection, c1);
    push(collection, c2);
    push(collection, c3);
    
    int choice = -1;
    Client cli;
    int cod;
    do {
        s_clear();
        printf("1 - Novo contato\n");
        printf("2 - Ver todos\n");
        printf("3 - Ver contato por cod\n");
        printf("4 - Ver contato nome\n");
        printf("5 - Editar contato nome\n");
        printf("6 - deletar contato\n");
        printf("0 - sair\n");
        
        scanf("%d",&choice);
        s_clear();
        switch (choice) {
            case 1:
                printf("Novo contato\n");
                getClientFromUser(&cli);
                push(collection, cli);
                printf("Cliente adicionado!\n");
                s_pause();
                break;
                
            case 2:
                printAllClients(collection);
                s_pause();
                break;
                
            case 3:
                printf("Procurando client por cod.\nDigite o cod:");
                
                scanf("%d", &cod);
                cli = getClientByCod(collection, cod);
                printClient(cli);
                s_pause();
                break;
            case 4:
                printf("Procurando client por nome.\nDigite o nome:");
                char nome[30];
                scanf("%s", nome);
//                cli = getClientByCod(collection, id);
//                printClient(cli);
                s_pause();
                break;
            case 5:
                printf("Atualizar contato\n");
                printf("Procurando client por cod.\nDigite o cod:");
                
                scanf("%d", &cod);
                updateClientByCod(collection, cod);
                printf("Cliente Atualizado!\n");
                s_pause();
                break;
            default:
                break;
        }
    }while (choice !=0);
    
    
    printf("\n\nSalvando dados...\n\n");
    
    return 0;
}
