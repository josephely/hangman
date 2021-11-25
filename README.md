# Hangman Project
### Joseph Ely
This project took me roughly 3 and a half hours.   

For this project, I used C++, as it is the language that I have spent the most time using during my time in school, and I am the most familiar with it. The basic idea behind my code was to create a driver function within main that plays the game, and then include all of the code needed to run the game within that function. I include a boolean variable that updates if the user decides to stop playing after one round, which results in the termination of the program. A large part of the game code resides in the printWord() function which, when called, references a set of global variables to return the current word, replacing letters that have not yet been guessed with underscores. Each time the user inputs a new letter, this function is called, and the number of correct and incorrect guesses is updated accordingly. 
