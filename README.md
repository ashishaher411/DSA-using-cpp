Algorithm

1) Start.
2) Create a node containing movie name and next pointer.
3) Initialize head = NULL.
4) Display the menu:
    Add Movie
    Remove Movie
    Display Movies
    Exit
5) For Add Movie, create a new node and add it at the end of the linked list.
6) For Remove Movie, search for the movie and delete its node.
7) For Display Movies, traverse the linked list and display all movie names.
8) Repeat the operations until the user selects Exit.
9) Stop.

   
Flowchart
        ┌─────────┐
        │  START  │
        └────┬────┘
             ↓
     ┌───────────────┐
     │  head = NULL  │
     └───────┬───────┘
             ↓
     ┌───────────────┐
     │  Display Menu │
     └───────┬───────┘
             ↓
     ┌───────────────┐
     │ Enter Choice  │
     └───────┬───────┘
             ↓
    ┌────────┼─────────┐
    ↓        ↓         ↓
  Add      Remove    Display
 Movie      Movie     Movies
    ↓        ↓         ↓
 Add Node  Delete    Traverse
    │       Node       List
    └────────┼─────────┘
             ↓
       ┌────────────┐
       │ Choice = 4?│
       └─────┬──────┘
          No │ Yes
             ↓
       ┌─────────┐
       │  STOP   │
       └─────────┘

Output
--- Movie Watchlist Manager ---
1. Add Movie
2. Remove Movie
3. Display Movies
4. Exit

Enter choice: 1
Enter movie name: Avengers
Movie added successfully.

Enter choice: 1
Enter movie name: Interstellar
Movie added successfully.

Enter choice: 1
Enter movie name: Inception
Movie added successfully.

Enter choice: 3

Movie Watchlist:
Avengers -> Interstellar -> Inception -> NULL

Enter choice: 2
Enter movie name to remove: Interstellar
Movie removed successfully.

Enter choice: 3

Movie Watchlist:
Avengers -> Inception -> NULL

Enter choice: 4
Program ended.
