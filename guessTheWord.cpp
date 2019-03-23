// Manmeet Singh
// Guess the word game... User will choose a letter in mind and computer will try to get it within limited amount of time.....

#include <iostream>
using namespace std;

void playGame();


int main() {
    playGame();
    return 0;
}

void playGame(){
    bool gameOver;
    int guessCount;
    char first, last, center;
    string response; 
    
    gameOver = false;
    guessCount = 5;
    first = 'A';
    last = 'Z';
    
    center = (first + last)/2;
    center++;
    
while(guessCount != 0 and not gameOver){
    
    cout << "==============================================\n";
    cout << "Guess Counts: " << guessCount << "           " << endl;
    cout << "Is letter '" << center << "' you thought of?\n";
    cout << "==============================================\n\n";
        
    getline(cin, response);
        
    if(response == "y" or response == "yes"){
        cout << "I Won!, You lose.\n";
        cout << "Play Again?\n";
        getline(cin, response);
        if(response =="y" or response =="yes"){
            gameOver = false;
            guessCount = 6;
        }else{
            gameOver = true;
        }
    }else{
            
        cout << "The Letter you guess is after the letter '" << center <<"' ? \n\n";
        getline(cin, response);
            
        if(response == "y" or response == "yes"){
            first = center+1;
            center = (first+last)/2;
        }
    
        if(response == "n" or response == "no"){
            last = center;
            center = (first + last)/2;
        }
    }
    guessCount--;
    if(guessCount == 0) {
        cout << "Snap.... Looks like I ran out of guesses... You won! Press P to play again\n";
        getline(cin, response);
        // Reseting the game 
        if(response == "p"){
            guessCount = 5;
            first = 'A';
            last = 'Z';
        }
    }
}
}
