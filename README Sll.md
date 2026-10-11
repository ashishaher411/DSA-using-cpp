 Algorithm: 
 
1. Start.
2. Create a node containing the movie name and next pointer.
3. Initialize `head = NULL`.
4. Display the menu:
   - Add Movie
   - Remove Movie
   - Display Movies
   - Exit
5. Enter the user's choice.
6. If the choice is 1, enter the movie name and add it at the end of the list.
7. If the choice is 2, search for the movie and delete its node.
8. If the choice is 3, display all movie names in the list.
9. If the choice is 4, exit the program.
10. If the choice is invalid, display an error message.
11. Repeat until the user selects Exit.
12. Stop.


Flowchart:
           +-------------+
           |    START    |
           +-------------+
                  |
                  v
           +-------------+
           | head = NULL |
           +-------------+
                  |
                  v
           +-------------+
           | Display Menu|
           +-------------+
                  |
                  v
           +-------------+
           | Enter Choice|
           +-------------+
                  |
                  v
      +-----------+-----------+
      |           |           |
      v           v           v
 +---------+ +---------+ +----------+
 |Add Movie| | Remove  | | Display  |
 |         | |  Movie  | |  Movies  |
 +---------+ +---------+ +----------+
      |           |           |
      v           v           v
 +---------+ +---------+ +----------+
 | Add Node| | Delete  | | Print All|
 | at End  | |  Node   | |  Movies  |
 +---------+ +---------+ +----------+
      |           |           |
      +-----------+-----------+
                  |
                  v
           +-------------+
           | Choice = 4? |
           +-------------+
             |         |
            No        Yes
             |         |
             v         v
       Display Menu +---------+
       Again        |   STOP  |
                    +---------+


output:

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
