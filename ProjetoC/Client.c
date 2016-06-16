//
//  Client.c
//  ProjetoC
//
//  Created by Leandro Silva Soares on 09/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include "Client.h"

Client newClient(int cod,
                   char nome[30],
                   char empresa[30],
                   char departamento[30],
                   char telefone[18],
                   char celular[18],
                   char email[40]) {
    Client c;
    strcpy(c.nome,nome);
    strcpy(c.empresa,empresa);
    strcpy(c.departamento,departamento);
    strcpy(c.telefone,telefone);
    strcpy(c.celular,celular);
    strcpy(c.email, email);
    
    return c;
}
void updateClientData(Client *c,
                      int cod,
                      char nome[30],
                      char empresa[30],
                      char departamento[30],
                      char telefone[18],
                      char celular[18],
                      char email[40]) {
    strcpy(c->nome,nome);
    strcpy(c->empresa,empresa);
    strcpy(c->departamento,departamento);
    strcpy(c->telefone,telefone);
    strcpy(c->celular,celular);
    strcpy(c->email, email);
}


void getClientFromUser(Client *c) {
    
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
    updateClientData(c,0, nome, empresa, departamento, telefone, celular, email);
    free(nome);
    free(empresa);
    free(departamento);
    free(telefone);
    free(celular);
    free(email);
}
void getClientFromUserChoice(Client *c) {
    
    char nome[30];
    char empresa[30];
    char departamento[30];
    char telefone[18];
    char celular[18];
    char email[40];
    
    printf("cod:%d\n",c->cod);
    
    if(desejaEditar("Nome", c->nome)){
        printf("Nome:[30 caracteres]\n");
        scanf(" %s",nome);
    }else{
        strcpy(nome, c->nome);
    }
    if(desejaEditar("Empresa", c->empresa)){
        printf("Empresa:[30 caracteres]\n");
        scanf(" %s",empresa);
    }
    else{
        strcpy(empresa, c->empresa);
    }
    if(desejaEditar("Departamento", c->departamento)){
        printf("Departamento:[30 caracteres]\n");
        scanf(" %s", departamento);
    }
    else{
        strcpy(departamento, c->departamento);
    }
    if(desejaEditar("Telefone", c->telefone)){
        printf("Telefone:[18 caracteres]\n");
         scanf(" %s", telefone);
    }
    else{
        strcpy(telefone, c->telefone);
    }
    if(desejaEditar("Celular", c->celular)){
        printf("Celular:[18 caracteres]\n");
        scanf(" %s", celular);
    }else{
        strcpy(celular, c->celular);
    }
    if(desejaEditar("Email", c->email)){
        printf("Email:[40 caracteres]\n");
        scanf(" %s", email);
    }else{
        strcpy(email, c->email);
    }
    updateClientData(c,c->cod||0, nome, empresa, departamento, telefone, celular, email);
}

int desejaEditar(char *field,char *value) {
    printf("%s: %s - Dejesa editar?(s/n):",field,value);
    char choice ='n';
    scanf(" %c",&choice);
    return choice=='s'?1:0;
}

void printClient(Client current) {
    printf("COD:%d\n Nome: %s", current.cod, current.nome);
    printf("\n Empresa: %s", current.empresa);
    printf("\n Departamento: %s", current.departamento);
    printf("\n Telefone: %s", current.telefone);
    printf("\n Celular: %s", current.celular);
    printf("\n Email: %s\n\n", current.email);
}