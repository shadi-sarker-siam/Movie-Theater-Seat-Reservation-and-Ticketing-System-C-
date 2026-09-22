#ifndef AUTH_H_INCLUDED
#define AUTH_H_INCLUDED

struct Account{
    char username[30];
    char password[30];
};


int loginAdmin();

void registerUser();
int loginUser(char loggedUser[]);


#endif // AUTH_H_INCLUDED
