// Manmeet Singh
// Guess the word game... User will choose a letter in mind and computer will try to get it within limited amount of time.....

#include <iostream>
using namespace std;

// function prototypes
void playGame();
char userResponse();
void gameReset();

// game declarations
bool gameOver;
int guessCount;
char first, last, center, response; 
    
// Main thread
int main() {
  playGame();
  cout << endl;
  return 0;
}

// Main game function 
void playGame(){
 
  // Setting up the game
  gameReset();

  // While conditions are false game will be running 
  while(guessCount != 0 and not gameOver){
 
    cout << "==============================================\n";
    cout << "Guess Counts: " << guessCount << "           " << endl;
    cout << "Is letter '" << center << "' you thought of?\n";
    cout << "==============================================\n\n";

   // If user wins
    if(userResponse()  == 'Y'){
        cout << "I Won!, You lose.\n";
        cout << "Play Again?\n";
      if(userResponse() == 'Y'){
        gameReset();
        guessCount+=1;
      }else gameOver = true;

    // if user does not win
    }else{
         cout << "The Letter you guess is after the letter '" << center <<"' ? \n\n";
         userResponse();
         if(response == 'Y'){
            first = center+1;
            center = (first+last)/2;
        }else if(response == 'N'){
            last = center;
            center = (first + last)/2;
        }
    }
    // decreasing the guess counts each time user takes a turn
    guessCount-=1;
    if(guessCount == 0) {
        cout << "Snap.... Looks like I ran out of guesses... You won! Press P to play again\n";
        // Reseting the game 
        if(userResponse() == 'P')
          gameReset();
    }
  }
}

// this function set's up the game settings 
void gameReset(){
    gameOver = false;
    guessCount = 5;
    first = 'A';
    last = 'Z';
    center = (first + last)/2;
    center++;      
}

// This functions gets the user response 
char userResponse(){
  // clears the input before using it
  cin.clear();
  response = cin.get();
  cin.ignore(999, '\n');
  response = toupper(response);
  return response;
}
