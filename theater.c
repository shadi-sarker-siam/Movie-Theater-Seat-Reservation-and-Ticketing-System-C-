#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "theater.h"

//ADD MOVIE
void addMovie(){
    struct Movie m;
    int i;


    FILE *fp;
    int input_id;

    printf("\n--- Add New Movie ---\n");
    printf("Enter Movie ID: ");
    scanf("%d", &input_id);


    fp = fopen("movies.txt", "r");

    if (fp != NULL) {
        struct Movie temp;
        while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%f", &temp.id, temp.title, temp.date, temp.time, &temp.price) == 5) {
            for (int j = 0; j < 20; j++) {
                fscanf(fp, ",%d", &temp.seats[j]);
            }
            fscanf(fp, "\n");

            if (temp.id == input_id) {
                printf("Error: Movie ID already exists!\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }


    m.id = input_id;





    fp=fopen("movies.txt","a");

    if(fp == NULL){
        printf("No File exist!\n");
        return;
    }

    printf("\n--- Add New Movie ---\n");
    printf("Enter Movie ID: ");
    scanf("%d",&m.id);

    printf("Enter Movie's Name: ");
    scanf(" %[^\n]",m.title);

    printf("Enter Date (D-M-Y): ");
    scanf("%s",m.date);

    printf("Enter Time (e.g. 06:30PM): ");
    scanf("%s",m.time);

    printf("Enter Ticket Price : ");
    scanf("%f",&m.price);

    for(i=0; i<20; i++){
        m.seats[i]=0;
    }

    fprintf(fp,"%d,%s,%s,%s,%.2f",m.id,m.title,m.date,m.time,m.price);

    for(i=0; i<20; i++){
        fprintf(fp, ",%d",m.seats[i]);
    }

    fprintf(fp, "\n");

    fclose(fp);

    printf("\nMovie added successfully.\n");

}


//VIEW MOVIE

void viewMovies(){
    struct Movie m;
    int i;

    FILE *fp;
    fp=fopen("movies.txt","r");

    if(fp==NULL){
        printf("\nNo movies found! \n");
        return;
    }

    printf("\n--- MOVIE LIST ---\n");

    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%f", &m.id, m.title, m.date,m.time, &m.price)==5){
        for(int i=0; i<20; i++){
            fscanf(fp, ",%d", &m.seats[i]);
        }
        fscanf(fp,"\n");

        printf("ID: %d \t Title: %s \t Date: %s \t Time: %s \t Price: %.2f TK\n",m.id,m.title,m.date,m.time,m.price);
    }

    fclose(fp);
}


//SEARCH MOVIE

void searchMovie(){
    struct Movie m;
    int searchID;
    int f=0;
    int i;

    FILE *fp;
    fp=fopen("movies.txt","r");

    if(fp==NULL){
        printf("\nNo Movies found in file!\n");
        return;
    }

    printf("\nEnter Movie ID to search: ");
    scanf("%d",&searchID);

    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%f",&m.id, m.title, m.date, m.time, &m.price) == 5){
        for(i=0; i<20; i++){
            fscanf(fp, ",%d", &m.seats[i]);
        }
        fscanf(fp, "\n");

        if(m.id == searchID){
            f=1;

            printf("\n--- MOVIE FOUND ---\n");
            printf("ID: %d\n",m.id);
            printf("Movie's Name : %s\n",m.title);
            printf("Date : %s\n",m.date);
            printf("Time : %s\n",m.time);
            printf("Price : %.2f TK\n",m.price);

            printf("\nSeat status (0 = Avaialble, 1 = Booked) : \n");
            for(i=0; i<20; i++){
            printf("[Seat %d: %d]  ",i+1,m.seats[i]);

            if((i+1)%5==0) printf("\n");
        }
        break;
        }
    }

    fclose(fp);

    if(f==0) printf("\nMovie with ID : %d was not found! \n",searchID);
}


//UPDATE MOVIE
void updateMovie(){
    struct Movie m;
    int updateId;
    int f=0;
    int i;

    FILE *fp;
    fp=fopen("movies.txt","r");
    FILE *temp;
    temp=fopen("temp.txt","w");

    if(fp==NULL || temp==NULL){
        printf("\nFile Error!\n");
        if(fp) fclose(fp);
        if(temp) fclose(temp);
        return;
    }

    printf("\nEnter Movie ID to Update : ");
    scanf("%d", &updateId);

    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%f", &m.id,m.title,m.date,m.time, &m.price)==5){
        for(i=0; i<20; i++){
            fscanf(fp, ",%d",&m.seats[i]);
        }

        fscanf(fp, "\n");

        if(m.id==updateId){
            f=1;
            printf("\n--- Enter New Details for Movie ID %d ---\n", updateId);

            printf("Enter New Name : ");
            scanf(" %[^\n]", m.title);

            printf("Enter New Date (D-M-Y) : ");
            scanf("%s",m.date);

            printf("Enter New Time (e.g. 06:30PM) : ");
            scanf("%s",m.time);

            printf("Enter New Ticket Price : ");
            scanf("%f",&m.price);
        }

        fprintf(temp, "%d,%s,%s,%s,%.2f",m.id,m.title,m.date,m.time,m.price);

        for(i=0; i<20; i++){
            fprintf(temp, ",%d",m.seats[i]);
        }
        fprintf(temp, "\n");
    }

    fclose(fp);
    fclose(temp);

    remove("movies.txt");
    rename("temp.txt","movies.txt");

    if(f==1) printf("\nMovie Updated Successfully!\n");
    else printf("\nMovie with ID: %d was not found!\n",updateId);
}


//DELTE MOVIE

void deleteMovie(){
    struct Movie m;
    int deleteId;
    int f=0;
    int i;

    FILE *fp;
    fp=fopen("movies.txt","r");
    FILE *temp;
    temp=fopen("temp.txt","w");

    if(fp==NULL || temp==NULL){
        printf("\nFile Error!\n");
        if(fp) fclose(fp);
        if(temp) fclose(temp);
        return;
    }

    printf("\nEnter Movie ID to delete : ");
    scanf("%d",&deleteId);

    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%f", &m.id,m.title,m.date,m.time, &m.price)==5){
        for(i=0; i<20; i++){
            fscanf(fp, ",%d",&m.seats[i]);
        }
        fscanf(fp, "\n");

        if(m.id==deleteId){
            f=1;
        }
        else{
            fprintf(temp, "%d,%s,%s,%s,%.2f",m.id,m.title,m.date,m.time,m.price);
            for(i=0; i<20; i++){
                fprintf(temp, ",%d",m.seats[i]);
            }
            fprintf(temp, "\n");
        }
    }

    fclose(fp);
    fclose(temp);

    remove("movies.txt");
    rename("temp.txt","movies.txt");

    if(f==1) printf("\nMovie with ID : %d deleted successfully!\n",deleteId);
    else printf("\nMovie with ID : %d was not found!\n",deleteId);

}

//BOOK TICKET

void bookTicket(char username[]){
    struct Movie movies[100];
    int count=0;
    int bookID,seatNo,f=0;
    int i,j;

    FILE *fp;
    fp=fopen("movies.txt","r");

    if(fp==NULL){
        printf("\nNo movies available for booking!\n");
        return;
    }

    while(fscanf(fp, "%d,%[^,],%[^,],%[^,],%f",&movies[count].id, movies[count].title, movies[count].date, movies[count].time, &movies[count].price) == 5){
        for(j=0; j<20; j++){
            fscanf(fp, ",%d",&movies[count].seats[j]);
        }
        fscanf(fp, "\n");
        count++;
    }

    fclose(fp);

    printf("\nEnter Movie ID to Book Ticket : ");
    scanf("%d",&bookID);

    for(i=0; i<count; i++){
        if(movies[i].id==bookID){
            f=1;

            printf("\n--- Seat Plan for %s ---\n",movies[i].title);
            printf("[0 = Available, 1 = Bookes]\n\n");

            for(j=0; j<20; j++){
                printf("[Seats %d: %d]  ",j+1,movies[i].seats[j]);
                if((j+1) % 5 == 0) printf("\n");
            }

            printf("\nEnter seat number to book (1-20) : ");
            scanf("%d",&seatNo);

            if(seatNo < 1 || seatNo > 20){
                printf("Invalid Seat Number! \n");
                return;
            }

            if(movies[i].seats[seatNo-1] == 1){
                printf("Sorry, this seat is already booked!\n");
                return;
            }

            movies[i].seats[seatNo-1] = 1;

            FILE *fbook;
            fbook=fopen("booking.txt","a");

            if(fbook != NULL){
                fprintf(fbook, "%s,%d,%s,%d,%.2f\n",username,movies[i].id,movies[i].title, seatNo, movies[i].price);
                fclose(fbook);
            }

            printf("\nTicket booked successfully for %s! ", username);
            printf("\nMovie's Name : %s",movies[i].title);
            printf("\nShow Date : %s",movies[i].date);
            printf("\nShow Time : %s",movies[i].time);
            printf("\nSeat No : %d",seatNo);
            printf("\nTicket Price : %.2f TAKA",movies[i].price);

            break;
        }
    }

    if(f==0){
            printf("\nMovie ID not found! \n");
            return;
    }


    fp=fopen("movies.txt","w");
    if(fp != NULL){
        for(i=0; i<count;i++){
            fprintf(fp, "%d,%s,%s,%s,%.2f",movies[i].id,movies[i].title,movies[i].date,movies[i].time,movies[i].price);

            for(j=0; j<20; j++){
                fprintf(fp, ",%d",movies[i].seats[j]);
            }

            fprintf(fp, "\n");

        }
        fclose(fp);
    }
}


//VIEW ALL BOOKINGS (FROM ADMIN SIDE)

void viewAllBookings(){
    struct Booking b;
    FILE *fbook;
    fbook=fopen("booking.txt","r");

    if(fbook==NULL){
        printf("\nNo Booking records found!\n");
        return;
    }

    printf("\n--- ALL USER BOOKING RECORD ---\n");

    while(fscanf(fbook, "%[^,],%d,%[^,],%d,%f\n",b.username,&b.movieId,b.movieTitle,&b.seatNumber,&b.price)==5){
        printf("User : %s \t Movie ID: %d \t Title: %s \t Seat: %d \t Price: %.2f TK\n",b.username,b.movieId,b.movieTitle,b.seatNumber,b.price);

    }

    fclose(fbook);
}


//VIEW USER BOOKINGS(FROM USER SIDE)

void viewUserBookings(char username[]){
    struct Booking b;
    int f=0;

    FILE *fp;
    fp=fopen("booking.txt","r");

    if(fp==NULL){
        printf("\nNo Booking history!\n");
        return;
    }

    printf("\n--- YOUR BOOKING HISTORY (%s) ---\n",username);

    while(fscanf(fp, "%[^,],%d,%[^,],%d,%f\n",b.username, &b.movieId, b.movieTitle, &b.seatNumber, &b.price) == 5){
        if(strcmp(b.username,username)==0){
            f=1;
            printf("Movie ID: %d \t Title: %s \t Seat: %d \t Price: %.2f TK\n",b.movieId,b.movieTitle,b.seatNumber,b.price);

        }
    }

    if(f==0) printf("You have not booked any tickets yet.\n");

    fclose(fp);
}


//Cancel Booking(USER)

void cancelBooking(char username[]){
    struct Booking b;
    struct Movie movies[100];
    int count=0;
    int cancelMovieId,cancelSeatNo,f=0;
    int i,j;

    FILE *fbook;
    fbook=fopen("booking.txt","r");

    FILE *tempbook;
    tempbook=fopen("temp_booking.txt","w");

    if(fbook==NULL){
        printf("\nNo booking records found!\n");
        if(tempbook) fclose(tempbook);
        return;
    }

    printf("\n--- YOUR CURRENT BOOKINGS (%s) ---\n",username);

    while(fscanf(fbook, "%[^,],%d,%[^,],%d,%f\n",b.username, &b.movieId, b.movieTitle, &b.seatNumber, &b.price)==5){
        if(strcmp(b.username,username)==0){
            f=1;
            printf("Movie ID: %d \t Title: %s \t Seat: %d \t Price: %.2f TK\n", b.movieId, b.movieTitle, b.seatNumber, b.price);

        }

    }
    fclose(fbook);

    if(f ==0 ){
        printf("You have no bookings to cancel.\n");
        fclose(tempbook);
        remove("temp_booking.txt");
        return;
    }

    printf("\nEnter Movie ID to cancel your booking: ");
    scanf("%d",&cancelMovieId);

    printf("\nEnter seat number to cancel : ");
    scanf("%d",&cancelSeatNo);

    fbook=fopen("booking.txt","r");
    int cancel=0;

    while(fscanf(fbook, "%[^,],%d,%[^,],%d,%f\n",b.username,&b.movieId, b.movieTitle, &b.seatNumber,&b.price)==5){
        if(strcmp(b.username,username)==0 && b.movieId==cancelMovieId && b.seatNumber==cancelSeatNo && !cancel){
            cancel=1;

        }
        else{
            fprintf(tempbook, "%s,%d,%s,%d,%.2f\n", b.username,b.movieId,b.movieTitle,b.seatNumber,b.price);
        }
    }

    fclose(fbook);
    fclose(tempbook);

    remove("booking.txt");
    rename("temp_booking.txt","booking.txt");

    if(cancel==0){
        printf("\nNo matching booking found to cancel!\n");
        return;
    }


    FILE *fmovie;
    fmovie=fopen("movies.txt","r");

    if(fmovie != NULL){
        while(fscanf(fmovie, "%d,%[^,],%[^,],%[^,],%f",&movies[count].id,movies[count].title,movies[count].date,movies[count].time, &movies[count].price)==5){
            for(j=0; j<20; j++){
                fscanf(fmovie, ",%d", &movies[count].seats[j]);
            }
            fscanf(fmovie, "\n");

            if(movies[count].id==cancelMovieId){
                movies[count].seats[cancelSeatNo-1]=0;
            }
            count++;
        }
        fclose(fmovie);

        fmovie= fopen("movies.txt","w");

        if(fmovie != NULL){
            for(i=0; i<count; i++){
                fprintf(fmovie, "%d,%s,%s,%s,%.2f",movies[i].id,movies[i].title,movies[i].date,movies[i].time,movies[i].price);
                for(j=0; j<20; j++){
                    fprintf(fmovie, ",%d",movies[i].seats[j]);
                }
                fprintf(fmovie, "\n");
            }
            fclose(fmovie);
        }

        printf("\nBooking for Movie ID: %d (Seat %d) cancelled successfully!\n",cancelMovieId,cancelSeatNo);
    }



}


//ADMIN DASHBOARD

void adminMenu(){
    int choice;

    while(1){
        printf("\n*********** ADMIN DASHBOARD ***********\n");
        printf("1. Add New Movie\n");
        printf("2. View All Movies\n");
        printf("3. Search Movie\n");
        printf("4. Update Movie\n");
        printf("5. Delete Movie\n");
        printf("6. View All User's Bookings\n");
        printf("7. Logout\n");
        printf("*****************************************\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: addMovie();
                    break;
            case 2: viewMovies();
                    break;
            case 3: searchMovie();
                    break;
            case 4: updateMovie();
                    break;
            case 5: deleteMovie();
                    break;
            case 6: viewAllBookings();
                    break;
            case 7:
                    printf("\nLogged out from Admin Panel.\n");
                    return;
            default:
                    printf("Invalid Choice!\n");
        }

    }
}


//USER DASHOBOARD

void userMenu(char loggedUser[]){
    int choice;
    while(1){
        printf("\n***********  USER DASHBOARD (%s) ***********\n",loggedUser);
        printf("1. View Movies List\n");
        printf("2. Search Movie & Seat Map\n");
        printf("3. Book Movie Ticket\n");
        printf("4. View My Bookings\n");
        printf("5. Cancel Booking\n");
        printf("6. Logout\n");
        printf("\n*******************************************************\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: viewMovies();
                    break;
            case 2: viewMovies();
                    searchMovie();
                    break;
            case 3: viewMovies();
                    bookTicket(loggedUser);
                    break;
            case 4: viewUserBookings(loggedUser);
                    break;
            case 5: cancelBooking(loggedUser);
                    break;
            case 6: printf("\nLogged out successfully\n");
                    return;
            default:
                    printf("Invalid Choice!\n");
        }
    }
}
