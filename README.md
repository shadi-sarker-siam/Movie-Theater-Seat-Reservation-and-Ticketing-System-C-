# Movie-Theater-Seat-Reservation-and-Ticketing-System-in-C

A console-based C project for movie theaters featuring admin and user authentication, interactive seat matrix, and real-time ticket booking. Supports full CRUD operations for movie schedules and persistent file-based storage. Developed as an academic C programming course project.

## Features

- **Admin Login & Management:**
  - Add, view, search, update, and delete movie schedules.
  - View all user booking records.
- **User Reservation System:**
  - View available movie shows and real-time seat status.
  - Interactive seat selection (20-seat matrix capacity).
  - View personal booking history and cancel tickets with automatic seat release.
- **Conflict Prevention:** Interactive seat validation to prevent double-booking.
- **Persistent Storage:** File handling using `.txt` files (`movies.txt`, `booking.txt`) with safe temporary buffer updates.

## Project Structure

- `main.c` - Entry point and main menu handler
- `header.h` - Contains function declarations and data structures (`struct Movie`, `struct Booking`)
- `functions.c` - Contains core logic for movie management, file operations, and ticket reservations

## How to Run

### On Windows:

1. **Compile:** Write in the terminal:
   ```bash
   gcc main.c functions.c -o movieTheaterExecutable
