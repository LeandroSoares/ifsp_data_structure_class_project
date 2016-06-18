//
//  ClientCollection.c
//  ProjetoC
//
//  Created by Leandro Silva Soares on 09/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include "ClientCollection.h"

struct client_collection{
    Client client;
    struct client_collection *next;
};

typedef struct client_collection CC;

ClientCollection * newClientCollection(){
    ClientCollection * cc = (ClientCollection *) malloc(sizeof(ClientCollection));
    if(cc!=NULL) {
        *cc=NULL;
    }
    return cc;
}

ClientCollection * newClientCollectionFromDATA(FILE *file) {
    ClientCollection *collection = newClientCollection();
    char data[170];
    while(fgets(data, sizeof(data), file)) {
        
        Client decoded = decodeClientData(data);
        push(collection, decoded);
    }
    return collection;
}

void deleteClientCollection(ClientCollection *cc) {
    if(cc!=NULL){
        CC * no;
        while ((*cc)!=NULL) {
            no=*cc;
            *cc=(*cc)->next;
            free(no);
        }
        free(cc);
    }
}

int isEmptyClientCollection(ClientCollection *cc) {
    return (cc==NULL || *cc==NULL)?1:0;
}

int lenghtClientCollection(ClientCollection *cc) {
    if(isEmptyClientCollection(cc)){
        return 0;
    }
    int counter=0;

    CC * no = *cc;
    while (no!=NULL) {
        counter++;
        no->client.index = counter;
        no=no->next;
    }
    return counter;
}

int unshift(ClientCollection *li, Client al){
    if (li==NULL) {
        return 0;
    }
    CC * no = (CC*)malloc(sizeof(CC));
    if(no==NULL){
        return 0;
    }
    no->client=al;
    no->next = (*li);
    *li=no;
    lenghtClientCollection(li);
    return 1;
}

int shift(ClientCollection *li){
    if (isEmptyClientCollection(li)) {
        return 0;
    }
    CC * no = *li;
    *li=no->next;
    free(no);
    lenghtClientCollection(li);
    return 1;
}

int push(ClientCollection *li, Client al) {
    if(li==NULL)return 0;
    CC *no = (CC*)malloc(sizeof(CC));
    if (no==NULL) {
        return 0;
    }
    no->client=al;
    no->next=NULL;
    if(isEmptyClientCollection(li)){
        *li=no;
    }else{
        CC *aux=*li;
        while (aux->next!=NULL) {
            aux=aux->next;
        }
        aux->next=no;
    }
    lenghtClientCollection(li);
    return 1;
}
int pop(ClientCollection *li) {
    if(li==NULL)return 0;

    CC *aux=*li;
    CC *last;
    last=aux;
    while (aux->next!=NULL) {
        last=aux;
        aux=aux->next;
    }

    free(aux);
    last->next=NULL;
    lenghtClientCollection(li);
    return 1;
}

int insertClientOrdered(ClientCollection *li, Client client){
    if(li==NULL)return 0;

    CC *no = (CC*)malloc(sizeof(CC));
    if (no==NULL)return 0;
    client.index = lenghtClientCollection(li)+1;
    no->client=client;
    no->next=NULL;
    if(isEmptyClientCollection(li)){
        printf("lista vazia");
        *li=no;

    }
    else{
        CC *ant = NULL,*atual = *li;
        while (atual!=NULL && atual->client.index<client.index) {
            ant=atual;
            atual = atual->next;
        }
        if (atual==*li) {
            no->next =(*li);
            *li=no;
        }
        else{
            no->next=ant->next;
            ant->next=no;
        }
    }

    return 1;
}

void printAllClients(ClientCollection * cc) {
    printf("ClientCollection: [\n");
    
    CC *no =*cc;
    
    while (no!=NULL) {
        Client current = no->client;
        printf("    (cod:%d nome: %s)", current.index, current.nome);
        
        if(no->next!=NULL) {
            printf(",");
        }
        
        printf("\n");
        no = no->next;
    }
    printf("]\n");
}

Client getClientByIndex(ClientCollection *cc, int index){
    CC *no =*cc;
    Client current = no->client;
    while (no!=NULL) {
        if(current.index==index)break;
        no = no->next;
        current = no->client;
    }
    return current;
}

int isEqualString(char a[],char b[]){
    int tamanhoa = (int)strlen(a);
    int tamanhob = (int)strlen(b)-1;
    if(tamanhoa==tamanhob){
        for (; *a; ++a) {
            if(tolower(*a)!=tolower(*b)){
                return 0;
            }
            ++b;
        }
    }else{
        return 0;
    }
    return 1;
}

Client * getClientByNome(ClientCollection *cc, char nome[30]){
    CC *no =*cc;
    Client current = no->client;
    while (no!=NULL) {
        if(isEqualString(current.nome, nome)){
            return &no->client;
        }
        else{
            no = no->next;
            if(no!=NULL){
                current = no->client;
            }else{
                return NULL;
            }
        }
    }
    return NULL;
}


void updateClientByIndex(ClientCollection * cc, int index){
    CC *no =*cc;
    Client current = no->client;
    if(lenghtClientCollection(cc)<index)return;
    while (no!=NULL) {
        if(current.index==index)break;
        no = no->next;
        current = no->client;
    }
    getClientFromUserChoice(&no->client);
    printClient(no->client);
}

int deleteClientByIndex(ClientCollection*list, int index){
    if(list==NULL)return 0;

    CC *aux=*list;
    CC *last;
    last=aux;
    while (aux!=NULL &&aux->client.index!=index) {
        last=aux;
        aux=aux->next;
    }
    if (aux==NULL) {
        return 0;
    }
    if(aux==*list){
        *list=aux->next;
    }else
    {
        last->next=aux->next;
    }
    free(aux);
    lenghtClientCollection(list);
    return 1;
}

void saveCollectionToFile(FILE * file, ClientCollection * cc){
    CC *no =*cc;
    while (no!=NULL) {
        Client current = no->client;
        saveClientToFile(file, current);
        if(no->next!=NULL)
            fputs("\n", file);
        no = no->next;
    }
}
