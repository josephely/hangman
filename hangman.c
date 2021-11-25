#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string words [10] = {
  "business",
  "hello",
  "president",
  "turkey",
  "thanksgiving",
  "christmas",
  "america",
  "halloween",
  "december",
  "november"
};
string currentWord;
int correctGuesses;
int incorrectGuesses;
bool gameDone;
bool stillPlaying;
char guessedLetters [26];
string printWord();
void startGame();

int main()
{
  stillPlaying = true;
  cout << "Welcome to hangman!" << endl;
  while(stillPlaying) {
    startGame();
    char playAgain;
    cout << "Congratulations! You won in " << correctGuesses + incorrectGuesses << " guesses. Would you like to play again? Enter Y or N" << endl;
    cin >> playAgain;
    if (playAgain == 'N') {
      stillPlaying = false;
    }
  }
  return 0;
}

void startGame() {
  int wordToUse = rand() % 10;
  currentWord = words[wordToUse];
  for (int i = 0; i < 26; i++) {
    guessedLetters[i] = NULL;
  }
  gameDone = false;
  char currentGuess;
  int numberOfGuesses = 0;
  correctGuesses = 0;
  incorrectGuesses = 0;
  string oldWord;
  string newWord;
  while (!gameDone) {
    oldWord = printWord();
    cout << "Correct guesses = " << correctGuesses << endl;
    cout << "Incorrect Guesses = " << incorrectGuesses << endl;
    cout << "Please enter a letter" << endl;
    cin >> currentGuess;
    guessedLetters[numberOfGuesses] = currentGuess;
    numberOfGuesses++;
    newWord = printWord();
    cout << newWord << endl;
    if (newWord.compare(oldWord) == 0) { // this means the guess was incorrect
      incorrectGuesses = incorrectGuesses + 1;
    }
    else {
      correctGuesses = correctGuesses + 1;
    }
  }
}

string printWord() { // prints the word with correctly guessed letters filled in
    char currentLetter;
    string wordToPrint;
    bool lettersStllUnfound = false;
    bool foundMatch = false;
    for (int i = 0; i < currentWord.size(); i++) { // iterate through letters of the word
        bool isMatch;
        currentLetter = currentWord.at(i);
        for (int i = 0; i < sizeof(guessedLetters); i++) { // check letter against all guessed letters
           if (currentLetter == guessedLetters[i]) {
            isMatch = true;
            break;
          }
          else {
            isMatch = false;
          }
        }
        if (isMatch == true) {
          wordToPrint = wordToPrint + currentLetter; // add letter to word
          foundMatch = true;
        }
        else {
          wordToPrint = wordToPrint + "_"; // add underscore to word
          lettersStllUnfound = true;
        }
    }
    //cout << wordToPrint << endl;
    if (!lettersStllUnfound) {
      gameDone = true;
    }
    return wordToPrint;
}
