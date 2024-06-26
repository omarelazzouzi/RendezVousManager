#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RENDEZ_VOUS 100
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    int id;
    char nom[NAME_LENGTH];
    char date[11];
    char heure[6];
} RendezVous;

typedef struct {
    int id;
    char nom[NAME_LENGTH];
    char telephone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

RendezVous rendezVous[MAX_RENDEZ_VOUS];
Contact contacts[MAX_CONTACTS];
int rendezVousCount = 0;
int contactCount = 0;

void ajouterRendezVous() {
    if (rendezVousCount >= MAX_RENDEZ_VOUS) {
        printf("Impossible d'ajouter plus de rendez-vous. Maximum atteint.\n");
        return;
    }

    RendezVous nouveauRendezVous;
    nouveauRendezVous.id = rendezVousCount + 1;
    printf("Entrez le nom: ");
    scanf("%s", nouveauRendezVous.nom);
    printf("Entrez la date (AAAA-MM-JJ): ");
    scanf("%s", nouveauRendezVous.date);
    printf("Entrez l'heure (HH:MM): ");
    scanf("%s", nouveauRendezVous.heure);

    rendezVous[rendezVousCount] = nouveauRendezVous;
    rendezVousCount++;
    printf("Rendez-vous ajouté avec succès!\n");
}

void afficherRendezVous() {
    if (rendezVousCount == 0) {
        printf("Aucun rendez-vous à afficher.\n");
        return;
    }

    printf("Rendez-vous:\n");
    for (int i = 0; i < rendezVousCount; i++) {
        printf("ID: %d, Nom: %s, Date: %s, Heure: %s\n",
               rendezVous[i].id, rendezVous[i].nom, rendezVous[i].date, rendezVous[i].heure);
    }
}

void supprimerRendezVous() {
    int id;
    printf("Entrez l'ID du rendez-vous à supprimer: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < rendezVousCount; i++) {
        if (rendezVous[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Rendez-vous avec l'ID %d non trouvé.\n", id);
        return;
    }

    for (int i = index; i < rendezVousCount - 1; i++) {
        rendezVous[i] = rendezVous[i + 1];
    }
    rendezVousCount--;
    printf("Rendez-vous supprimé avec succès!\n");
}

void ajouterContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Impossible d'ajouter plus de contacts. Maximum atteint.\n");
        return;
    }

    Contact nouveauContact;
    nouveauContact.id = contactCount + 1;
    printf("Entrez le nom: ");
    scanf("%s", nouveauContact.nom);
    printf("Entrez le téléphone: ");
    scanf("%s", nouveauContact.telephone);
    printf("Entrez l'email: ");
    scanf("%s", nouveauContact.email);

    contacts[contactCount] = nouveauContact;
    contactCount++;
    printf("Contact ajouté avec succès!\n");
}

void afficherContacts() {
    if (contactCount == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("ID: %d, Nom: %s, Téléphone: %s, Email: %s\n",
               contacts[i].id, contacts[i].nom, contacts[i].telephone, contacts[i].email);
    }
}

void supprimerContact() {
    int id;
    printf("Entrez l'ID du contact à supprimer: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact avec l'ID %d non trouvé.\n", id);
        return;
    }

    for (int i = index; i < contactCount - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contactCount--;
    printf("Contact supprimé avec succès!\n");
}

int main() {
    int choix;

    while (1) {
        system("clear");
        printf("Système de Gestion Hôtelière\n");
        printf("1. Ajouter Rendez-vous\n");
        printf("2. Afficher Rendez-vous\n");
        printf("3. Supprimer Rendez-vous\n");
        printf("4. Ajouter Contact\n");
        printf("5. Afficher Contacts\n");
        printf("6. Supprimer Contact\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        fflush(stdin);  // Pour vider le tampon d'entrée

        switch (choix) {
            case 1:
                ajouterRendezVous();
                break;
            case 2:
                afficherRendezVous();
                break;
            case 3:
                supprimerRendezVous();
                break;
            case 4:
                ajouterContact();
                break;
            case 5:
                afficherContacts();
                break;
            case 6:
                supprimerContact();
                break;
            case 7:
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

        printf("Appuyez sur Entrée pour continuer...");
        getchar(); // Pour attendre l'entrée de l'utilisateur
        getchar();
    }

    return 0;
}
