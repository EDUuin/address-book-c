#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {                 // fun. to save contacts to csv file 
    FILE *fptr;                                                     // declare file pointer
    fptr = fopen("contact.csv","w");                                // open contactc.csv file in write mode
    if (fptr == NULL){                                              // check file is opened or not
        printf("\033[31mError: Cannot open source file contact.csv\n\033[0m");
        return ;
    }
    fprintf(fptr,"%d\n",addressBook->contactCount);                 // copy no. of contacts to the csv file

    for(int i = 0; i < addressBook -> contactCount; i++) {          // copy contact details to csv file from structure
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fptr);                                                   // close file
    printf("\n\033[32mCONTACT SUCCESSFULLY COPIED TO CONTACT.CSV FILE!\n\033[0m");
}

void loadContactsFromFile(AddressBook *addressBook) {               // fun. to load contacts in structure from contact.csv file 
    FILE *fp;                                                       // declare file pointer
    if((fp = fopen("contact.csv","r")) == NULL){                    // open contactc.csv file in read mode & check file is opened or not
        printf("\n\033[31mError: Cannot open source file contact.csv\n\033[0m");
        return ;
    }

    fscanf(fp,"%d", &addressBook->contactCount);                    // get contact count from contact.csv file 
    fgetc(fp);                                                      // clear enter(\n)

    for(int i = 0; i < addressBook ->contactCount; i++) {           // to load contact details from csv file to structure
        fscanf(fp,"%[^,],%[^,],%[^\n]",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        fgetc(fp);
    }

    fclose(fp);                                                     // close file
}
