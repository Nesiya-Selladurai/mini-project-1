#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define a structure for storing contact information
struct Contact {
    char name[50];
    char phone_number[15];
};

// Function prototypes
void addContact(struct Contact contacts[], int *numContacts);
void displayContacts(struct Contact contacts[], int numContacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    char choice;

    do {
        printf("\nPhone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addContact(contacts, &numContacts);
                break;
            case '2':
                displayContacts(contacts, numContacts);
                break;
            case '3':
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != '3');

    return 0;
}

// Function to add a contact to the phone book
void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts < MAX_CONTACTS) {
        printf("\nEnter name: ");
        scanf(" %[^\n]", contacts[*n
