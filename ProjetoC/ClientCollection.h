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
#include "Client.h"
#endif /* ClientCollection_h */
typedef struct client_collection * ClientCollection;



ClientCollection * newClientCollection();
void deleteClientCollection(ClientCollection *cc);
int isEmptyClientCollection(ClientCollection *cc);
int lenghtClientCollection(ClientCollection *cc);

int unshift(ClientCollection *li, Client al);

int shift(ClientCollection *li);
int push(ClientCollection *li, Client al);
int pop(ClientCollection *li);

int insertClientOrdered(ClientCollection *li, Client al);
void printAllClients(ClientCollection * cc);
Client getClientByCod(ClientCollection *cc, int cod);
void updateClientByCod(ClientCollection * cc, int cod);