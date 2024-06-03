
    #include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Structure to represent a contact
struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

// Array to store contacts
struct Contact contacts[MAX_CONTACTS];

// Number of contacts currently stored
int numContacts = 0;

// Function prototypes
void addContact();
void searchContact();

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to add a contact
void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[numContacts].name);
    printf("Enter contact phone number: ");
    scanf("%s", contacts[numContacts].phone);

    printf("Contact added successfully.\n");
    numContacts++;
}

// Function to search for a contact
void searchContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}
