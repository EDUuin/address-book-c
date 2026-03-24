#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook,int sort);
void save(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

char *enter_name(char name[]);
char *enter_number(AddressBook *addressBook,char num[], int check);
char *enter_email(AddressBook *addressBook, char mail[], int check);

int valname(char str[]);
int valnum(int long numb,char arr[]);
int valmail(char str[]);

int check_num(AddressBook *addressBook,char num[]);
int check_mail(AddressBook *addressBook,char mail[]);

void search_name(AddressBook *addressBook,char name[],int edit, int delete);
void search_number(AddressBook *addressBook,char num[],int edit,int delete);
void search_mail(AddressBook *addressBook,char mail[],int edit,int delete);

#endif
