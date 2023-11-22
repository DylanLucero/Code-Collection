//Dylan Lucero
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function that rolls the players dice
int rollDice(){
  return rand() % 6 + 1; // Add 1 otherwise we roll 0's and no 6's
}


// Checks the rolls, returns value
int calcPoints(int firstRoll, int secondRoll){
  if(firstRoll == 1 && secondRoll == 1){ // Check to see if a 1 is rolled. End turn
    return 25;
  } else if(firstRoll == 1 || secondRoll == 1){ // Check for snake eyes roll. +25 pts
    return 0;
  } else if(firstRoll == secondRoll){ // Check for double rolls. Points * 2
    return ((firstRoll + secondRoll) * 2);
  } else{
    return firstRoll + secondRoll;  // Otherwise, return sum of rolls
  }
}

// This function keeps track of a players turn. i.e. points, rolls and adds the point
// values to the address that was passed in from *playerScore parameter.
void playerTurn(int playerNum, int *playerScore){
  int firstRoll, secondRoll, sumRoll, totalRoll;
  char choice;

  // Dice Rolls
  firstRoll = rollDice();
  secondRoll = rollDice();
  sumRoll = calcPoints(firstRoll, secondRoll);
  totalRoll = sumRoll;

  printf("Player%d rolls a ", playerNum);
  printf("%d and a %d. Your total for this turn is: %d\n", firstRoll, secondRoll, sumRoll);

  if (sumRoll == 0) {
    
    printf("You rolled a 1 and therefore earn 0 points\n"); // Set totalRoll to 0 if sumRoll = 0
    printf("------------------------------------------\n"); //   means no points for the turn
    totalRoll = 0;
    return; // Ends turn if a 1 is rolled
   }

  while(sumRoll != 0) {
    printf("Do you want to roll again (Y/N)? "); // Loop if player chooses to roll again
    scanf(" %c", &choice);

    if(choice == 'Y' || choice == 'y') {
      firstRoll = rollDice(); // Recalculating dice rolls
      secondRoll = rollDice();
      sumRoll = calcPoints(firstRoll, secondRoll);
      totalRoll += sumRoll; // totalRoll keeps track of turn score
     
      printf("Player%d rolls a ", playerNum);
      printf("%d and a %d. Your total for this turn is: %d\n", firstRoll, secondRoll, totalRoll);

      if(sumRoll == 0){ // If a 1 is rolled, set turn total to 0 and end turntotalRollprintf
        printf("You rolled a 1 and therefore earn 0 points\n"); // Set totalRoll to 0 if sumRoll = 0
        printf("------------------------------------------\n"); //   means no points for the turn
        totalRoll = 0;
        return;
      }

    }else if (choice == 'N' || choice == 'n') {
      *playerScore += totalRoll; // If player chooses n, add totalRoll
      return;                    //         to playerScore.
    }
  }
}


// Main Function
int main(){
  srand((unsigned)time(NULL));
  
  // Initialize scores as 0
  int p1Score = 0;
  int p2Score = 0;


  // Main loop
  while(p1Score < 100 || p2Score < 100){
    printf("Player 1 Score: %d\nPlayer 2 Score: %d\n", p1Score, p2Score);
    printf("-----------------------------------\n");

    playerTurn(1, &p1Score);
    if(p1Score >= 100){ // Check to see if player 1 has scored 100 or above
      printf("Player 1 wins!");
      break;
    }

    printf("Player 1 Score: %d\nPlayer 2 Score: %d\n", p1Score, p2Score);
    printf("-----------------------------------\n");
    playerTurn(2, &p2Score);
    if(p2Score >= 100){ // Check to see if player 2 has scored 100 or above
      printf("Player 2 wins!");
      break;
    }

  }
  return 0;
}
