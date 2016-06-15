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
    printf("Pressione qualquer tecla para continuar...\n");
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
    
    int choice = -1;
    
    do {
        s_clear();
        printf("1 - Novo contato\n");
        printf("2 - Ver todos\n");
        printf("3 - Ver contato id\n");
        printf("4 - Ver contato nome\n");
        printf("5 - Editar contato nome\n");
        printf("6 - deletar contato\n");
        printf("0 - sair\n");
        
        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                s_clear();
                
                printf("Novo contato\n");
                char nome[30];
                char empresa[30];
                char departamento[30];
                char telefone[18];
                char celular[18];
                char email[40];
                
                printf("Nome:[30 caracteres]\n");
                scanf(" %s",nome);
                
                printf("Empresa:[30 caracteres]\n");
                scanf(" %s",empresa);
                
                printf("Departamento:[30 caracteres]\n");
                scanf(" %s", departamento);
                
                printf("Telefone:[18 caracteres]\n");
                scanf(" %s", telefone);
                
                printf("Celular:[18 caracteres]\n");
                scanf(" %s", celular);
                
                printf("Email:[40 caracteres]\n");
                scanf(" %s", email);
                push(collection, newClient(0, nome, empresa, departamento, telefone, celular, email));
                printf("Cliente adicionado!\n");
                s_pause();
                break;
            case 2:
                system("clear");
                printAllClients(collection);
                s_pause();
            default:
                break;
        }
    }while (choice !=0);
    
    
    printf("\n\nSalvando dados...\n\n");
    
    return 0;
}
