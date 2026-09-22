#include <stdio.h>
#include <stdlib.h>
#include "auth.h"



//LOGIN ADMIN

int loginAdmin(){
    struct Account inputAcc,fileAcc;
    int f=0;

    FILE *fp;
    fp=fopen("admin.txt","r");

    if(fp==NULL){
        printf("No Admin account found! Please register first.\n");
        return 0;
    }

    printf("\n--- ADMIN LOGIN ---\n");
    printf("Enter Username: ");
    scanf("%s",inputAcc.username);
    printf("Enter password: ");
    scanf("%s",inputAcc.password);

    while(fscanf(fp, "%s %s",fileAcc.username,fileAcc.password)==2){
        if(strcmp(fileAcc.username,inputAcc.username)==0 && strcmp(fileAcc.password,inputAcc.password)==0){
            f=1;
            break;

        }
    }

    fclose(fp);

    if(f==1){
        printf("Admin login successful!\n");
        return 1;
    }
    else{
        printf("Invalid Admin username or password!\n");
        return 0;
    }
}


//USER REGISTRATION

void registerUser(){
    struct Account acc,fileAcc;
    int exist=0;

    printf("\n--- User Registration ---\n");

    printf("Enter User's Username (without space): ");
    scanf("%s",acc.username);

    FILE *fpRead;
    fpRead=fopen("user.txt","r");

    if(fpRead != NULL){
        while(fscanf(fpRead, "%s %s",fileAcc.username,fileAcc.password)==2){
            if(strcmp(fileAcc.username,acc.username)==0){
                exist=1;
                break;
            }
        }
        fclose(fpRead);
    }

    if(exist==1){
        printf("Error: Username '%s' is already taken! Try another.\n",acc.username);
        return;
    }


    printf("Enter User Password: ");
    scanf("%s",acc.password);

    FILE *fp;
    fp=fopen("user.txt","a");

    if(fp==NULL){
        printf("Error , File issue \n");
        return;
    }

    fprintf(fp, "%s %s\n",acc.username,acc.password);
    fclose(fp);

    printf("User Registration Successful\n");
}


//USER LOGIN

int loginUser(char loggedUser[]){
    struct Account inputAcc,fileAcc;
    int f=0;

    FILE *fp = fopen("user.txt","r");

    if(fp==NULL){
        printf("No user account found! Please register first.\n");
        return 0;
    }

    printf("\n--- User Login ---\n");
    printf("Enter Username: ");
    scanf("%s",inputAcc.username);

    printf("Enter Password: ");
    scanf("%s",inputAcc.password);

    while(fscanf(fp, "%s %s",fileAcc.username,fileAcc.password)==2){
        if(strcmp(fileAcc.username,inputAcc.username)==0 && strcmp(fileAcc.password,inputAcc.password)==0){
            f=1;
            strcpy(loggedUser,inputAcc.username);
            break;
        }
    }

    fclose(fp);

    if(f==1){
        printf("User Login Successful.\n");
        return 1;
    }
    else{
        printf("Invalid username or password.\n");
        return 0;
    }
}
