#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "theater.h"
#include "auth.h"


int main(){
    int choice;
    char username[50];

    while(1){
        printf("\n--------------------------------------------------\n");
        printf("Movie Theater Seat Reservation and Ticketing System         \n\n");
        printf("1. Admin Login\n");
        printf("2. User Registration\n");
        printf("3. User Login\n");
        printf("4. Exit\n");
        printf("--------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                    if(loginAdmin()){
                        adminMenu();
                    }
                    break;

            case 2:
                    registerUser();
                    break;

            case 3:
                    if(loginUser(username)){
                        userMenu(username);
                    }
                    break;

            case 4:
                    printf("\nThank you for using the system.\n");
                    return 0;

            default :
                    printf("\nInvalid choice! Please try again. \n");
        }
    }

    return 0;
}
