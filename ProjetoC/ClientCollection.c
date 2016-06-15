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
        no->client.cod = counter;
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

int insertClientOrdered(ClientCollection *li, Client al){
    if(li==NULL)return 0;
    
    CC *no = (CC*)malloc(sizeof(CC));
    if (no==NULL)return 0;
    al.cod = lenghtClientCollection(li)+1;
    no->client=al;
    no->next=NULL;
    if(isEmptyClientCollection(li)){
        printf("lista vazia");
        *li=no;
        
    }else{
        CC *ant = NULL,*atual = *li;
        while (atual!=NULL && atual->client.cod<al.cod) {
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
    printf("Clientes:\n\n");
    CC *no =*cc;
    
    while (no!=NULL) {
        Client current = no->client;
        printf("COD:%d\n Nome: %s", current.cod, current.nome);
        printf("\n Empresa: %s", current.empresa);
        printf("\n Departamento: %s", current.departamento);
        printf("\n Telefone: %s", current.telefone);
        printf("\n Celular: %s", current.celular);
        printf("\n Email: %s\n\n", current.email);
        no = no->next;
    }
}