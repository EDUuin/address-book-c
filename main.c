#include <stdio.h>
#include "contact.h"

int main() {
    int choice;                                                     // to collect choice from user
    AddressBook addressBook;
    initialize(&addressBook);                                       // Initialize the address book

    printf("\033[1;32m\nWELCOME TO ADDRESS BOOK\n\033[0m");

    do {                                                                                                                
        printf("\n\033[1;32mADDRESS BOOK MENU:\033[0m\n");          // display address book menu
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("\033[33m\nEnter your choice: \033[0m");
        while (1 != scanf("%d",&choice)){                           // to get right i/p from user
        
            while (getchar() != '\n');                              // to clear i/p buffer
            printf("\033[31mInvalid input: Please enter digit\n\033[0m");
            
            printf("\033[33m\nEnter your choice: \033[0m");
        }
        
        while (getchar() != '\n');                                  // to clear i/p buffer 
        switch (choice) {                                           // to select choice
            case 1:                                                 // to create contact
                createContact(&addressBook);
                break;
            case 2:                                                 // to search conact
                searchContact(&addressBook);
                break;
            case 3:                                                 // to edit contact
                editContact(&addressBook);
                break;
            case 4:                                                 // to delete contact
                deleteContact(&addressBook);
                break;
            case 5:                                                 // to list contact         
                listContacts(&addressBook,1);
                break;
            case 6:                                                 // to save contact
                saveContactsToFile(&addressBook);
                break;
            case 7:                                                 // to exit from address book menu
                printf("\n\033[36mEXIT FROM ADDRESS BOOK\n\n\033[0m");
                break;
            default:                                                // if user enter any invalid choice
                printf("\033[31mInvalid choice. Please try again.\033[0m\n");
        }
    } while (choice != 7);                                          // exit address book when user enter choice as 7 
    
       return 0;
}