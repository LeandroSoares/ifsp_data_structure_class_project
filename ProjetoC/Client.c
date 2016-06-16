//
//  Client.c
//  ProjetoC
//
//  Created by Leandro Silva Soares on 09/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include "Client.h"

Client newClient(
                   char nome[30],
                   char empresa[30],
                   char departamento[30],
                   char telefone[18],
                   char celular[18],
                   char email[40]) {
    Client c;c.index=0;
    strcpy(c.nome,nome);
    strcpy(c.empresa,empresa);
    strcpy(c.departamento,departamento);
    strcpy(c.telefone,telefone);
    strcpy(c.celular,celular);
    strcpy(c.email, email);
    
    return c;
}
void updateClientData(Client *c,
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

//void clearWord(char*word, int size){
//    int i=0;
//    while(i<size){
//        word[i]=' ';
//    }
//    word[size]='\0';
//    return word;
//}

void getClientFromUser(Client *c) {
    
    char nome[30];
    char empresa[30];
    char departamento[30];
    char telefone[18];
    char celular[18];
    char email[40];
    
    printf("Nome:[30 caracteres]\n");
    getchar();
    scanf ("%[^\n]%*c", nome);
    
    printf("Empresa:[30 caracteres]\n");
//    getchar();
    scanf("%[^\n]%*c",empresa);
    
    printf("Departamento:[30 caracteres]\n");
//    getchar();
    scanf("%[^\n]%*c", departamento);
    
    printf("Telefone:[18 caracteres]\n");
//    getchar();
    scanf("%[^\n]%*c", telefone);
    
    printf("Celular:[18 caracteres]\n");
//    getchar();
    scanf("%[^\n]%*c", celular);
    
    printf("Email:[40 caracteres]\n");
//    getchar();
    scanf("%[^\n]%*c", email);
    updateClientData(c, nome, empresa, departamento, telefone, celular, email);
}
void getClientFromUserChoice(Client *c) {
    
    char nome[30];
    char empresa[30];
    char departamento[30];
    char telefone[18];
    char celular[18];
    char email[40];
    
    printf("cod:%d\n",c->index);
    
    if(desejaEditar("Nome", c->nome)){
        printf("Nome:[30 caracteres]\n");
        getchar();
        scanf ("%[^\n]%*c", nome);
    }else{
        strcpy(nome, c->nome);
    }
    if(desejaEditar("Empresa", c->empresa)){
        printf("Empresa:[30 caracteres]\n");
        getchar();
        scanf("%[^\n]%*c",empresa);
    }
    else{
        strcpy(empresa, c->empresa);
    }
    if(desejaEditar("Departamento", c->departamento)){
        printf("Departamento:[30 caracteres]\n");
        getchar();
        scanf("%[^\n]%*c", departamento);
    }
    else{
        strcpy(departamento, c->departamento);
    }
    if(desejaEditar("Telefone", c->telefone)){
        printf("Telefone:[18 caracteres]\n");
        getchar();
        scanf("%[^\n]%*c", telefone);
    }
    else{
        strcpy(telefone, c->telefone);
    }
    if(desejaEditar("Celular", c->celular)){
        printf("Celular:[18 caracteres]\n");
        getchar();
        scanf("%[^\n]%*c", celular);
    }else{
        strcpy(celular, c->celular);
    }
    if(desejaEditar("Email", c->email)){
        printf("Email:[40 caracteres]\n");
        getchar();
        scanf("%[^\n]%*c", email);
    }else{
        strcpy(email, c->email);
    }
    updateClientData(c, nome, empresa, departamento, telefone, celular, email);
}

int desejaEditar(char *field,char *value) {
    printf("%s: %s - Dejesa editar?(s/n):",field,value);
    char choice ='n';
    scanf(" %c",&choice);
    return choice=='s'?1:0;
}

void printClient(Client current) {
    printf("COD:%d\n Nome: %s", current.index, current.nome);
    printf("\n Empresa: %s", current.empresa);
    printf("\n Departamento: %s", current.departamento);
    printf("\n Telefone: %s", current.telefone);
    printf("\n Celular: %s", current.celular);
    printf("\n Email: %s\n\n", current.email);
}

void saveClientToFile(FILE *file, Client client) {
    char clientString[170];
    strcpy(clientString, clientEncode(client.nome, 30));
    strcat(clientString, ",");
    strcat(clientString, clientEncode(client.empresa, 30));
    strcat(clientString, ",");
    strcat(clientString, clientEncode(client.departamento, 30));
    strcat(clientString, ",");
    strcat(clientString, clientEncode(client.telefone, 18));
    strcat(clientString, ",");
    strcat(clientString, clientEncode(client.celular, 18));
    strcat(clientString, ",");
    strcat(clientString, clientEncode(client.email, 40));
    strcat(clientString, ",");
    fputs(clientString, file);
}

char * clientEncode(char *data, int length){
    int diff = (int)length-(int)strlen(data);
    if(diff>0){
        for (int i=diff; i!=0; i--) {
            data[strlen(data)+i]= ' ';
        }
    }
    return data;
}

int getWord(char *data,char *buff,int index){
    int i=0;
    while(data[index]!=',') {
        buff[i]=data[index];
        index++;
        i++;
    }
    buff[i]='\0';
    return index+1;
}

Client decodeClientData(char*data) {
    Client result;
    int index = getWord(data, result.nome,0);
    index = getWord(data, result.empresa,index);
    index = getWord(data, result.departamento,index);
    index = getWord(data, result.telefone,index);
    index = getWord(data, result.celular,index);
    index = getWord(data, result.email,index);
    

    return result;
}
