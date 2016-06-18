//
//  ClientCollection.h
//  ProjetoC
//
//  Created by Leandro Silva Soares on 09/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#ifndef ClientCollection_h
#define ClientCollection_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Client.h"
#endif /* ClientCollection_h */
typedef struct client_collection * ClientCollection;



ClientCollection * newClientCollection();
ClientCollection * newClientCollectionFromDATA(FILE *file);
void deleteClientCollection(ClientCollection *cc);
int isEmptyClientCollection(ClientCollection *cc);
int lenghtClientCollection(ClientCollection *cc);

int unshift(ClientCollection *li, Client al);

int shift(ClientCollection *li);
int push(ClientCollection *li, Client al);
int pop(ClientCollection *li);

int insertClientOrdered(ClientCollection *li, Client client);
void printAllClients(ClientCollection * cc);
Client getClientByIndex(ClientCollection *cc, int index);
void updateClientByIndex(ClientCollection * cc, int index);
int deleteClientByIndex(ClientCollection *cc, int index);
Client * getClientByNome(ClientCollection *cc, char nome[30]);
void saveCollectionToFile(FILE * file, ClientCollection * cc);