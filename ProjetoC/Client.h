//
//  Client.h
//  ProjetoC
//
//  Created by Leandro Silva Soares on 09/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#ifndef Client_h
#define Client_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct client{
    int index;
    char nome[31];
    char empresa[31];
    char departamento[31];
    char telefone[19];
    char celular[19];
    char email[41];
} Client;
#endif /* Client_h */


Client newClient(
                char nome[30],
                char empresa[30],
                char departamento[30],
                char telefone[18],
                char celular[18],
                char email[40]);

void updateClientData(Client *c,
                      char nome[30],
                      char empresa[30],
                      char departamento[30],
                      char telefone[18],
                      char celular[18],
                      char email[40]);

void getClientFromUser(Client *c);
void getClientFromUserChoice(Client *c);

void printClient(Client current);
int desejaEditar();


void saveClientToFile(FILE *file, Client client);
char * clientEncode(char *data, int length);
Client decodeClientData(char *data);