#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook,int sort)                // fun. to list contacts in sorted order 
{
    Contact temp[1];                                                // to temporarily store one contact details
    int choice, flag = 0;                                           // to get sort choice from user
    if (sort) {
    do
    {
    printf("\n\033[32mSort by :\033[0m\n1. Name \n2. Number\n3. Email\n\n\033[33mEnter your choice: \033[0m"); // display choices to user
    while ( 1 != scanf(" %d",&choice)) {                            // if entered invalid choice 
        while (getchar() != '\n');                                  // to clear i/p buffer
        printf("\033[31mInvalid Choice: Please enter valid choice.\033[0m\n");

        printf("\n\033[32mSort by :\033[0m\n1. Name\n2. Number\n3. Email\n\n\033[33mEnter your choice: \033[0m");
    }
    while (getchar() != '\n');                                      // to clear i/p buffer
    printf("\n");
    switch (choice){
        case 1:                                                     // for sort by name
        for(int i = 0; i < addressBook->contactCount; i++) {        // for sorting name in alphabetic order
            for (int j = i+1; j < addressBook->contactCount; j++) {
                if(strcasecmp(addressBook->contacts[i].name,addressBook->contacts[j].name) > 0) { // if i index string is less than j index string cmp will return a +ve value
                    temp[0] = addressBook->contacts[i];               
                    addressBook->contacts[i] = addressBook->contacts[j];        // swap logic
                    addressBook->contacts[j] = temp[0];
                }
            }
        }
        flag = 1;                                                   // update flag to come out of do while loop
        break;                                                      // come out of switch case 

        case 2:                                                     // for sort by number
        for(int i = 0; i < addressBook->contactCount; i++) {
            for (int j = i+1; j < addressBook->contactCount; j++) {
                if(strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone) > 0) {   // if i index string is less than j index string cmp will return a +ve value
                    temp[0] = addressBook->contacts[i];
                    addressBook->contacts[i] = addressBook->contacts[j];        // swap logic      
                    addressBook->contacts[j] = temp[0];
                }
            }
        }
        flag = 1;                                                   // update flag to come out of do while loop
        break;                                                      // come out of switch case 

        case 3:                                                     // for sort by email
        for(int i = 0; i < addressBook->contactCount; i++) {
            for (int j = i+1; j < addressBook->contactCount; j++) {
                if(strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email) > 0) {   // if i index string is less than j index string cmp will return a +ve value
                    temp[0] = addressBook->contacts[i];
                    addressBook->contacts[i] = addressBook->contacts[j];        // swap logic
                    addressBook->contacts[j] = temp[0];
                }
            }
        }
        flag = 1;                                                   // update flag to come out of do while loop
        break;                                                      // come out of switch case 

        default:
        printf("\033[31mInvalid choice. Please enter valid choice...\033[0m\n");
        }
    }while (!flag);
    }

        printf("\033[1;32m%45s\033[0m","CONTACT LIST");               // display contact list... 
        printf("\n------+----------------------------------------------------------------------------+\n");
        printf("\033[1mSI.NO |\t%-25s%-25s%-25s\033[0m|","NAME","PHONE NUMBER","EMAIL ADDRESS");
        printf("\n------+----------------------------------------------------------------------------+");
        for(int i = 0; i < addressBook->contactCount; i++) {
            printf("\n%4d] |\t%-26s%-24s%-25s|\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            printf("      |                                                                            |"); 
        }  
        printf("\n------+----------------------------------------------------------------------------+\n");
        if(sort)
        printf("\033[1;32m%48s\033[0m\n","BACK TO MAIN MENU");
}

void initialize(AddressBook *addressBook) {                           // to load contact details from contact.csv to structure
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);  
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);                                // loadinng contacts to structure
}

void createContact(AddressBook *addressBook)                    // fun. to create contact
{
    char name[50], num[15], mail[50]; // temporary variables to store contact details from user
    int n=0;                          // n is the number of contacts user entering at a time
    printf("\033[34mEnter the number of contacts to add: \033[0m");
    while (1 != scanf("%d",&n)){      // to check user is giving valid choice
        while (getchar() != '\n');    // to clear i/p buffer
        printf("\033[31mInvalid input: Please enter digits\033[0m\n");
        
        printf("\033[34mEnter the number of contacts to add: \033[0m");
    }
    while (getchar() != '\n');                                  // to clear i/p buffer

    if((addressBook->contactCount + n) <= 100) {
        int num_contact = 0;                                    // to run loop for no. of contacts to add 
        while(num_contact<n)
        {
            printf("\n\033[1;33mCREATING CONTACT %d \033[0m\n\n",addressBook->contactCount+1);

            strcpy(name, enter_name(name));                     // fun. call to enter name and copy to name variable
            strcpy(num, enter_number(addressBook, num, 1));     // fun. call to enter number and check number is unique after that copy to num variable
            strcpy(mail, enter_email(addressBook, mail, 1));    // fun. call to enter email address and check email is unique after that copy to mail variable

            printf("\n\033[34mEntered contact details: \033[0m\n---> Name: %-20s\tPhone number: %-15s\tEmail: %s\n",name,num,mail);

            strcpy(addressBook->contacts[addressBook->contactCount].name, name);   // copy entered name to structure name
            strcpy(addressBook->contacts[addressBook->contactCount].phone, num);   // copy entered phone number to structure phone
            strcpy(addressBook->contacts[addressBook->contactCount].email, mail);  // copy entered email address to structure email
            printf("\n\033[1;32mCONTACT CREATED SUCCESSFULLY!\033[0m\n");
            addressBook->contactCount++;                        // after adding contact details in structure increment contactcount
            num_contact++;
        }
    }
    else {
        if(addressBook->contactCount == 100)
        printf("\033[1;32mYou have reached the maximum contact limit!\033[0m");
        else
        printf("\n\033[31mMaximum Number of Contact is 100!\033[0m You can enter \033[1;32m%d\033[0m more contacts\n",100-addressBook->contactCount);
    }

}

void searchContact(AddressBook *addressBook)                      // fun to search contact
{
    int n;                                                        // n is the choice variable for search contact
    do
    {
        printf("\n\033[1;32mSearch by :\033[0m\n1. Name\n2. Number\n3. Email\n4. Exit\n\n\033[33mEnter your choice:\033[0m "); // display choices for user
        while ( 1 != scanf(" %d",&n)) {                           // if entered invalid choice 
            while (getchar() != '\n');                            // to clear i/p buffer
            printf("\033[31mInvalid Choice: Please enter valid choice.\033[0m\n");

            printf("\n\033[32mSearch by :\033[0m\n1. Name\n2. Number\n3. Email\n4. Exit\n\n\033[33mEnter your choice: \033[0m");
        }
        while (getchar() != '\n');                                // to clear i/p buffer
        printf("\n");
        switch (n)
        {
            case 1:                                               // search by name
                char name[50];                                    // declare name var to get name to search from user
                strcpy(name, enter_name(name));                   // fun. call to enter name and copy to name variable
                search_name(addressBook,name,0,0);                // fun. call to search the name is present in the contact list
                break;

            case 2:                                               // search by phone number
                char numb[50];                                    // declare numb var to get phone number from user
                strcpy(numb, enter_number(addressBook, numb, 0)); // fun. call to enter phone number and copy to numb variable
                search_number(addressBook, numb, 0, 0);           // fun. call to search the phone number is present in the contact list
                break;
            
            case 3:                                               // search by email address
                char mail[50];                                    // declare mail var to get email address from user
                strcpy(mail,enter_email(addressBook, mail, 0));   // fun. call to enter email address and copy to mail variable 
                search_mail(addressBook, mail, 0, 0);             // fun. call to search the email address is present in the contact list
                break;
            
            case 4:                                               // exit from search contact
                printf("\033[36mEXIT FROM SEARCH CONTACT\033[0m\n");
                break;

            default:                                              // if user entered any invalid choice
                printf("\033[31mInvalid choice. Please enter valid choice...\033[0m\n");
        }
    } while(n  !=4);                                              // till user enter 4 as choice search menu will be displayed
}

void editContact(AddressBook *addressBook)                        // fun. to edit contact
{
    int n;                                                        // n is the choice variable for edit contact
    listContacts(addressBook,0);                                  // to list the saved contacts
    do
    {
        printf("\n\033[1;32mEdit by :\033[0m\n1. Name\n2. Number\n3. Email\n4. Exit\n\n\033[33mEnter your choice:\033[0m "); // display edit choices for user
        while ( 1 != scanf(" %d",&n)) {                           // if entered invalid choice
            while (getchar() != '\n');                            // to clear i/p buffer
            printf("\n\033[31mInvalid Choice: Please enter valid choice.\033[0m\n");

            printf("\n\033[32mEdit by :\033[0m\n1. Name\n2. Number\n3. Email\n4. Exit\n\n\033[33mEnter your choice:\033[0m ");
        }
        while (getchar() != '\n');                                // to clear i/p buffer
        printf("\n");
        switch(n)
        {
            case 1:                                               // edit by name
                char name[50];                                    // declare name var to get an name from user
                strcpy(name, enter_name(name));                   // fun. call to enter name and copy to name variable
                search_name(addressBook,name,1,0);                // fun. call to edit the contact by name search
                break;

            case 2:                                               // edit by phone number
                char numb[50];                                    // declare numb var to get a phone number from user
                strcpy(numb, enter_number(addressBook,numb,0));   // fun. call to enter phone number and copy to numb variable
                search_number(addressBook,numb,1,0);              // fun. call to edit the contact by number search
                break;

            case 3:                                               // edit by mail address
                char mail[50];                                    // declare mail var to get an email from user
                strcpy(mail, enter_email(addressBook,mail,0));    // fun. call to enter email address and copy to mail variable
                search_mail(addressBook,mail,1,0);                // fun. call to edit the contact by email search
                break;      

            case 4:                                               // exit from edit contact
                printf("\033[36mEXIT FROM EDIT CONTACT\033[0m\n");
                break;

            default:                                              // if user entered any invalid choice
                printf("\033[31mInvalid choice. Please enter valid choice...\033[0m\n");
        }
    } while (n != 4);                                             // till user enter 4 as choice edit menu will be displayed
}

void deleteContact(AddressBook *addressBook)                      // fun. to delete contact
{
    int n;                                                        // n is the choice variable for delete contact
    listContacts(addressBook,0);                                  // to list the saved contacts
    do
    {
        printf("\n\033[1;32mDelete by :\033[0m\n1. Name\n2. Number\n3. Email\n4. Exit\n\n\033[33mEnter your choice:\033[0m "); // display delete choices for user
        while ( 1 != scanf(" %d",&n)) {                           // if entered invalid choice
            while (getchar() != '\n');                            // to clear i/p buffer
            printf("\033[31mInvalid Choice: Please enter valid choice.\033[0m\n");

            printf("\n\033[32mDelete by :\033[0m\n1. Name\n2. Number\n3. Email\n4. Exit\n\n\033[33mEnter your choice:\033[0m \n");
        }
        while (getchar() != '\n');                                // to clear i/p buffer 
        printf("\n");
        switch(n)
        {
            case 1:                                               // delete by name
                char name[50];                                    // declare name var to get an name from user
                strcpy(name, enter_name(name));                   // fun. call to enter name and copy to name variable
                search_name(addressBook,name,0,1);                // fun. call to delete the contact by name search
                break;

            case 2:                                               // delete by phone number
                char numb[50];                                    // declare numb var to get a phone number from user 
                strcpy(numb, enter_number(addressBook,numb,0));   // fun. call to enter phone number and copy to numb variable
                search_number(addressBook,numb,0,1);              // fun. call to delete the contact by number search
                break;

            case 3:                                               // delete by mail address
                char mail[50];                                    // declare mail var to get an email from user
                strcpy(mail, enter_email(addressBook,mail,0));    // fun. call to enter email address and copy to mail variable
                search_mail(addressBook,mail,0,1);                // fun. call to delete the contact by email search
                break;

            case 4:                                               // exit from delete contact
                printf("\033[36mEXIT FROM DELETE CONTACT\n\033[0m");
                break;
            
            default:                                              // if user entered any invalid choice
                printf("\033[31mInvalid choice. Please enter valid choice...\033[0m\n");
        }
    } while(n != 4);                                              // till user enter 4 as choice delete menu will be displayed
}

int valname(char str[])                                           // fun. def to validate entered name 
{
    int i = 0;
    while(str[i]) {
        if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')  || str[i] == ' ' ) // only accept any case alphabet and space in name 
        i++;
        else {
            printf("\033[31mInvalid name. Please use only letters and spaces.\033[0m\n");
            return 1;
        }
    }
    return 0;
}

int valnum(int long numb,char arr[])                              // fun. to validate entered number and store in array
{
    int i = 9;                                                    // i is the no. of digits including 0
    if(numb > 999999999 && numb < 10000000000 ) {                 // to validate phone number is a 10 digit number
        while(numb != 0) {                                        
            arr[i]  = (numb % 10) + '0';                          // extract number from last and store to array from 9th to 0th index
            i--;
            numb = numb / 10;                                     // to get next next element
        }
        arr[10] = '\0';                                           // adding null char at end of string
    }
    else {
        printf("\033[31mInvalid number. Please enter exactly 10 digits.\033[0m\n");
        return 1;
    }
    return 0;
}

int valmail(char str[])                                           // fun. to validate entered email address
{
    int len = 0, count = 0, j;
    while(str[len])                                               // to find length of entered mail address
    len++;
    if(len < 11) {                                                // mail should atleast have length 11
        printf("\033[31mInvalid email format: Please ensure it contains atleast one lowercase alphabet and ends with @gmail.com'.\033[0m\n");
        return 1;
    }

    if(str[0] >= 'a' && str[0] <= 'z') { }                        // 1st char of mail id should be a lowercase alphabet

    else {
        printf("\033[31mInvalid email: it should start with a lowercase letter.\033[0m\n");
        return 1;
    }

    if(str[len-1]=='m' && str[len-2]=='o' && str[len-3]=='c' && str[len-4]=='.' && str[len-5]=='l' && str[len-6]=='i' && str[len-7]=='a' && str[len-8]=='m' && str[len-9]=='g' && str[len-10]=='@')
    {                                                             // last 10 char should be "@gmail.com"
        for(int i = 1; i < (len - 10); i++) {                     // checking from 1st index element before @ is only lowercase alphabet, digits or underscore
            if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_' ) { }
            else {
                printf("\033[31mInvalid email: only lowercase letters, digits, and '_' allowed before '@'.\033[0m\n");
                return 1;
            }
        }
        return 0;
    }
    else {                                                        // if last 10 char in mail id is not "@gmail.com"
        printf("\033[31mInvalid email format. Please make sure it ends with '@gmail.com'.\033[0m\n");
        return 1;
    }
}

int check_num(AddressBook *addressBook,char num[])                // fun. definition to check phone number is existing in contact list
{
    for(int i = 0; i < addressBook->contactCount; i++) {          // loop for contact count times
        if(!strcmp(num, addressBook->contacts[i].phone)) {        // strcmp will return 0 if number is already existing
            printf("\033[31mThis phone number already exists. Please enter a different number.\033[0m\n");
            return 1;
        }
    }
    return 0;
}

int check_mail(AddressBook *addressBook,char mail[])              // fun. definition to check email address is existing in contact list
{
    for(int i = 0; i < addressBook->contactCount; i++) {          // loop for contact count times
        if(!strcmp(mail, addressBook->contacts[i].email)) {       // strcmp will return 0 if email is already existing
            printf("\033[31mThis email is already saved. Please enter a different email address.\033[0m\n");
            return 1;
        }
    }
    return 0;
}

void search_mail(AddressBook *addressBook, char mail[], int edit, int delete)  // fun. to search email with edit and delete function
{
    int flag = 0, c;                                              // c is the variable to store index position if email address found in contact list
    for(int i = 0; i < addressBook->contactCount; i++) {
        if(!strcmp(mail, addressBook->contacts[i].email)) {       // if found in contact list
            c = i;                                                // copy index value to c
            flag = 1;                                             // updating flag
            printf("\033[32m\nCONTACT FOUND!\033[0m\n");
            printf("\n\033[34mContact details \n--> Name: %-15sPhone Number: %-15sEmail address: %s\033[0m\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            break;
        }
    }
    if(flag==0)                                                   // if mail id not found
        printf("\n\033[1;32mNO MATCHING CONTACT FOUND!\033[0m\n");

    else if (edit) {                                              // if edit fun. is called
        char mail[50];                                            // variable to store new mail address from user
        printf("\033[33m\nNew Email*\n\033[0m");
        strcpy(mail,enter_email(addressBook,mail,1));             // fun. call to enter new email address and copy to mail variable
        strcpy(addressBook->contacts[c].email,mail);              // copy the new email address to the index where the mail address is found
        printf("\n\033[34mUpdated contact details \n--> Name: %-18sPhone Number: %-15sEmail address: %s\033[0m\n",addressBook->contacts[c].name,addressBook->contacts[c].phone,addressBook->contacts[c].email);
        printf("\n\033[1;32mEMAIL SUCCESSFULLY EDITED\033[0m\n");
    }
    else if(delete) {                                                 // if delete fun. is called
        for(int i = c; i < (addressBook->contactCount) - 1; i++)      // loop to swap values of c+1 index to previous index till contact count 
            addressBook->contacts[i] = addressBook->contacts[i + 1];

        addressBook->contactCount--;                                  // decrement contact count by 1
        printf("\n\033[1;32mCONTACT SUCCESSFULLY DELETED\033[0m\n");
    }
}

void search_number(AddressBook *addressBook, char num[], int edit, int delete)  // fun. to search number with edit and delete feature
{
    int flag = 0, c;                                              // c is the variable to store index position if phonr number found in contact list
    for(int i = 0; i < addressBook->contactCount; i++) {
        if(!strcmp(num, addressBook->contacts[i].phone)) {        // if found in contact list
            c = i;                                                // copy index value to c
            flag = 1;                                             // updating flag
            printf("\033[32m\nCONTACT FOUND!\033[0m\n");
            printf("\n\033[34mContact details \n--> Name: %-15sPhone Number: %-15sEmail address: %s\033[0m\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            break;
        }
    }
    if(flag == 0)                                                 // if number id not found
        printf("\n\033[1;32mNO MATCHING CONTACT FOUND!\033[0m\n");

    else if (edit) {                                              // if edit fun. is called
        int long number;                                          // variable to store new phone number from user
        char numb[15];                                            // array to store phone number        
        printf("\033[33m\nNew Phone Number*\n\033[0m");
        strcpy(numb, enter_number(addressBook, numb, 1));         // fun. call to enter new phone number and copy to numb string
        strcpy(addressBook->contacts[c].phone, numb);             // copy the new phone number to the index where the number is found
        printf("\n\033[34mUpdated contact details \n--> Name: %-15sPhone Number: %-15sEmail address: %s\033[0m\n",addressBook->contacts[c].name,addressBook->contacts[c].phone,addressBook->contacts[c].email);
        printf("\n\033[1;32mNUMBER SUCCESSFULLY EDITED\033[0m\n");
    }
    else if (delete) {                                                // if delete fun. is called
        for(int i = c; i < (addressBook->contactCount) - 1; i++)      // loop to swap values of c+1 index to previous index till contact count
            addressBook->contacts[i] = addressBook->contacts[i + 1];

        addressBook->contactCount--;                                  // decrement contact count by 1
        printf("\n\033[1;32mCONTACT SUCCESSFULLY DELETED\033[0m\n");
    }
}

void search_name(AddressBook *addressBook, char name[], int edit, int delete)           // fun. to search name and edit or delete the name if name is found        
{
    int count = 0, arr[100], flag = 0, x;                                               // arr-> to store index value of name , x update the index value
    for(int i = 0; i < addressBook->contactCount; i++) {                                // compare the name entered with every name in list
        if(strcmp(name, addressBook->contacts[i].name) == 0) {                          
            arr[count++] = i;                                                           // add the index of the name found from contact list in array
            printf("\n\033[34mContact %d \n---> Name: %-15sPhone Number: %-15sEmail address: %s\033[0m",count,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            x = i;
        }
    }
    printf("\n");
    if (count == 0) {                                                                       // if name is not found in list
        printf("\033[1;32mNO MATCHING CONTACT FOUND!\033[0m\n");
        return ;
    }
        if (count >= 1) {                                                                   // if name found more than one time in list
            int n;
            printf("\n\033[32m%d MATCHING CONTACTS FOUND WITH THE ENTERED NAME!\033[0m\n",count);
            if (count > 1) {
                do {
                printf("\n\033[32mIdentify contact by:\033[0m\n1. Number\n2. Email\n3. Exit\n\n\033[33mEnter your choice:\033[0m ");
    
                while (scanf("%d", &n) != 1) {                                              // check scanf is reading or not
                    while (getchar() != '\n');                                              // to clear input buffer
                    printf("\033[31mInvalid input. Please enter valid choice.\033[0m\n");

                    printf("\n\033[32mIdentify contact by:\033[0m\n1. Number\n2. Email\n3. Exit\n\n\033[33mEnter your choice:\033[0m ");
                }
                while (getchar() != '\n');                                                  // to clear input buffer
                
                printf("\n");
                switch (n) {
                    case 1:                                                                 // search contact by number
                        char numb[15];                                                      // string to store phone no. to search
                        enter_number(addressBook, numb, 0);                                 // enter number and store in numb string
                        for (int i = 0; i < count; i++) {
                            if (strcmp(numb, addressBook->contacts[arr[i]].phone) == 0) {   // compare no. with the phone number of same contact name
                                printf("\n\033[32mCONTACT FOUND!\n\033[0m");
                                x = arr[i];
                                printf("\n\033[34mContact details \n--> Name: %-15sPhone Number: %-15sEmail address: %s\n\033[0m",addressBook->contacts[x].name,addressBook->contacts[x].phone,addressBook->contacts[x].email);
                                flag = 1;                                                   // no. found then update flag as 1
                                break;
                            }
                        }
                        if (flag == 0) {                                                    // if number not found
                            printf("\n\033[1;32mNO MATCHING CONTACT FOUND!\033[0m\n");
                            return; 
                        }
                        break;

                    case 2:                                                                 // search contact by email 
                        char mail[50];                                                      // string to store email address to search
                        enter_email(addressBook, mail, 0);                                  // enter email address and store in mail string
                        for (int i = 0; i < count; i++) {
                            if (strcmp(mail, addressBook->contacts[arr[i]].email) == 0) {   // compare email with the email address of same contact name
                                printf("\n\033[32mCONTACT FOUND!\033[0m");
                                x = arr[i];
                                printf("\n\033[34mContact details \n--> Name: %-15sPhone Number: %-15sEmail address: %s\n\033[0m",addressBook->contacts[x].name,addressBook->contacts[x].phone,addressBook->contacts[x].email);
                                flag = 1;                                                   // email found then update flag as 1
                                break;
                            }
                        }
                        if (flag == 0) {                                                    // if email not found
                            printf("\033[1;32m\nNO MATCHING CONTACT FOUND!\033[0m\n");
                            return; 
                        }
                        break;

                    case 3:                                                                 // exit from delete contact
                        printf("\033[1;32mEXIT FROM IDENTIFY CONTACT\033[0m\n");
                        return;

                    default:                                                                // if user enter invalid choice
                        printf("\033[31mInvalid choice. Please enter valid choice...\033[0m\n");
                        break;
                    }
                } while (!flag);
            }
        }

        if (edit) {                                                                     // if edit is enabled
            char newname[50];                                                           // to  get name from user                      
            printf("\033[33m\nNew Name*\n\033[0m");
            strcpy(newname, enter_name(newname));                                       // fun. call to enter name and copy to name variable
            strcpy(addressBook->contacts[x].name, newname);                             // copy the new name to the index where the name is found
            printf("\n\033[34mUpdated contact details \n--> Name: %-15sPhone Number: %-15sEmail address: %s\n\033[0m",addressBook->contacts[x].name,addressBook->contacts[x].phone,addressBook->contacts[x].email);
            printf("\n\033[1;32mNAME SUCCESSFULLY EDITED!\033[0m\n");
        } 
        else if (delete) {                                                              // if delete is enabled
            for (int j = x; j < addressBook->contactCount - 1; j++)                     // loop to swap values of x+1 index to previous index till contact count
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contactCount--;                                            // decrement contact count after swapping
            printf("\n\033[1;32mCONTACT DELETED SUCCESSFULLY!\033[0m\n");
        }
    }

char *enter_name(char name[]) {                                         // fun. definition to read name from user
    do {
        printf("Enter the name: ");
        scanf(" %[^\n]",name);
    } while(valname(name));                                             // fun. call for validation of name is validation success then come out of loop
    return name;                                                        // return name address
}

char *enter_number(AddressBook *addressBook, char num[], int check) {   // fun. definition to read phone number from user and check no. is existing or not
    int a;
        do {
            long int numb;                                              // variable to read phone number from user
            printf("Enter 10-digits phone number: ");
            scanf("%ld",&numb);
            while (getchar() != '\n');                                  // to clear i/p buffer
            a = valnum(numb,num);                                       // a holds return value of number validation 
            if(!a && check) {                                           // if validation is successful and check fun.(enabled) 
                a = check_num(addressBook, num);                        // check entered number is already existing or not and holds return value of number check fun
            }
        } while(a);                                                     // loop execute till a become 0
    return num;                                                         // return num address
}

char *enter_email(AddressBook *addressBook, char mail[], int check) {   // fun. definition to read email address from user and check mail is existing or not
    int a;
        do {
            printf("Enter mail address: ");
            scanf(" %[^\n]",mail);
            a = valmail(mail);                                          // a holds return value of mail validation
            if(!a && check) {                                           // if validation is successful and check fun.(enabled) 
                a = check_mail(addressBook, mail);                      // check entered mail is already existing or not and holds return value of mail check fun
            }
        } while(a);                                                     // loop execute till a become 0
    return mail;                                                        // return mail address
}