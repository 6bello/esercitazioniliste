#include <stdio.h>

struct data{
    int giorno;
    int mese;
    int anno;
};

struct Persona{
    char *nome[20];
    char *cognome[20];
    struct data dataDiNascita;
    struct Persona *next;
};

void visualizzaLista(struct Persona *head){
    struct Persona *curr = head;
    while(curr!=NULL){
        printf("%s %s è nat* il %d/%d del %d", curr->nome, curr->cognome, curr->dataDiNascita.giorno, curr->dataDiNascita.mese, curr->dataDiNascita.anno);
        curr = curr->next;
    }
}

void inserisciInCoda(struct Persona *head){
    struct Persona *newPersona = malloc(sizeof(struct Persona));
    fgets(&newPersona->nome, sizeof(newPersona->nome), stdin);
    fgets(&newPersona->cognome, sizeof(newPersona->cognome), stdin);
    scanf("%d %d %d", newPersona->dataDiNascita.giorno, newPersona->dataDiNascita.mese, newPersona->dataDiNascita.anno);
    head->next = newPersona;
}

int main(){}