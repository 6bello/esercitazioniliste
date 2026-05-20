#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
    int giorno;
    int mese;
    int anno;
};

struct Persona{
    char nome[20];
    char cognome[20];
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

void inserisciInCoda(struct Persona **head){
    struct Persona *newPersona = malloc(sizeof(struct Persona));
    struct Persona *curr = *head;
    newPersona->next == NULL;
    fgets(newPersona->nome, sizeof(newPersona->nome), stdin);
    fgets(newPersona->cognome, sizeof(newPersona->cognome), stdin);
    scanf("%d %d %d", &newPersona->dataDiNascita.giorno, &newPersona->dataDiNascita.mese, &newPersona->dataDiNascita.anno);
    if(*head==NULL){
        *head = newPersona;
    } else {
        while(curr->next!=NULL) curr = curr->next;
        curr->next = newPersona;
    }
    printf("ls%s %s", (curr)->next->nome, (curr)->next->cognome);
}

void eliminaGiovanni(struct Persona *head){
    struct Persona *prev = head;
    while(head!=NULL){
        if(head->nome == "Giovanni"){
            prev->next = head->next;
            prev = head;
            free(prev);
        }
        prev = head;
        head = head->next;
    }
}

int main() {
    
    int numero=-1;	 		// per la scelta dell'utente

	/* inizializza la lista */

	/* ciclo di interazione con l'utente */
	while(numero!=0) {
		printf("\nCiao utente! Puoi svolgere le seguenti operazioni:\n");
		printf("Introduci 1 -> Immetti una persona\n");
		printf("Introduci 2 -> Cancella Giovanni\n");
		printf("Introduci 3 -> Visualizza la lista\n");
		printf("Introduci 0 -> Termina il programma\n");
		scanf("%d%*c", &numero);

        struct Persona *head = malloc(sizeof(struct Persona));
		/* immetti una persona */
		if(numero==1) inserisciInCoda(&head);
			//....
		/* cancella una persona */
		else  if(numero==2) eliminaGiovanni(head);
			//....
		/* visualizza tutta la lista */
		else  if(numero==3) visualizzaLista(head);
			//....
		/* numero sbagliato? */
		else  if(numero!=0)
			printf("Questo numero non vuol dire niente. Riproviamo!\n");
		/* fine programma */
		else {
			printf("Adios!\n");
		/* salva la lista su file*/
		}
	}
}

/*{
    "explorer.confirmDelete": false,
    "debug.onTaskErrors": "showErrors",
    "workbench.colorTheme": "Dracula Theme",
    "debug.breakpointsView.presentation": "tree",
    "better-comments.tags": [


        {
            "tag": "!",
            "color": "#FF2D00",
            "strikethrough": false,
            "underline": false,
            "backgroundColor": "transparent",
            "bold": false,
            "italic": false
        },
        {
            "tag": "+",
            "color": "#00FF00",
            "strikethrough": false,
            "underline": false,
            "backgroundColor": "transparent",
            "bold": false,
            "italic": false
        },
        {
            "tag": "-",
            "color": "#70757f",
            "strikethrough": false,
            "underline": false,
            "backgroundColor": "transparent",
            "bold": false,
            "italic": false
        },
        {
            "tag": "?",
            "color": "#3498DB",
            "strikethrough": false,
            "underline": false,
            "backgroundColor": "transparent",
            "bold": false,
            "italic": false
        },
        {
            "tag": "//",
            "color": "#474747",
            "strikethrough": true,
            "underline": false,
            "backgroundColor": "transparent",
            "bold": false,
            "italic": false
        },
        {
            "tag": "todo",
            "color": "#FF8C00",
            "strikethrough": false,
            "underline": false,
            "backgroundColor": "transparent",
            "bold": false,
            "italic": false
        },
        {
            "tag": "*",
            "color": "#98C379",
            "strikethrough": false,
            "underline": true,
            "backgroundColor": "transparent",
            "bold": true,
            "italic": true
        }
    ]
}*/