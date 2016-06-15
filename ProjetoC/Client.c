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


char* clientToString(Client c) {
    
    char *txt = (char *) malloc(sizeof(char) * 241);
    
    char cod = c.cod+' ';
    strcpy(txt, "\nNome:\n    ");
    strcat(txt, c.nome);
    strcat(txt, &cod);
    strcat(txt, "\nEmpresa:\n    ");
    strcat(txt, c.empresa);
    strcat(txt, "\nDepartamento:\n    ");
    strcat(txt, c.departamento);
    strcat(txt, "\nTelefone:\n    ");
    strcat(txt, c.telefone);
    strcat(txt, "\nCelular:\n    ");
    strcat(txt, c.celular);
    strcat(txt, "\nE-mail:\n    ");
    strcat(txt, c.email);
    return txt;
}