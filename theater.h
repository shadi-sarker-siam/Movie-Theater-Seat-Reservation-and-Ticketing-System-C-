#ifndef THEATER_H_INCLUDED
#define THEATER_H_INCLUDED

struct Movie{
    int id;
    char title[50];
    char date[15];
    char time[15];
    float price;
    int seats[20];
};

struct Booking{
    char username[50];
    int movieId;
    char movieTitle[50];
    int seatNumber;
    float price;
};

void addMovie();
void viewMovies();
void searchMovie();
void updateMovie();
void deleteMovie();
void viewAllBookings();

void bookTicket(char username[]);
void viewUserBookings(char username[]);
void cancelBooking(char username[]);

void adminMenu();
void userMenu(char loggedUser[]);

#endif // THEATER_H_INCLUDED
