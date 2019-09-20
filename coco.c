// Assignment 1 19T1 COMP1511 Coco
//
// This program was written by Patrick(Jinming) Dong (z5211275)
// on 05/09/2019
//

#include <stdio.h>
#include <assert.h>


#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49


// IF YOU NEED MORE #defines ADD THEM HERE


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE

int is_prime(int);
int gcd(int,int);
int is_cocomposite(int,int);
int bestmove(int[],int);
int bestmove1(int[]);

// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    }

    return 0;
}

void print_player_name(void) {

    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME

    printf("Patrick\n");

}

void choose_discards() {

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
  int playercard = 0;
  int myCards[N_CARDS_INITIAL_HAND];
  while(playercard<N_CARDS_INITIAL_HAND){
    scanf("%d", &myCards[playercard]);
    playercard++;
  }
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
  int douglas = 0;
  int first,second,third;
  first = myCards[N_CARDS_INITIAL_HAND-1];
  second = myCards[N_CARDS_INITIAL_HAND-2];
  third = myCards[N_CARDS_INITIAL_HAND-3];
  for(int i = 0;i<N_CARDS_INITIAL_HAND;i++){
    if(myCards[i]==42){
      douglas = 1;
    }
  }
  if(douglas == 1){
    if(first == 42){
      printf("%d %d %d ", myCards[N_CARDS_INITIAL_HAND-3], myCards[N_CARDS_INITIAL_HAND-2], first);
    }
    if(second == 42){
      printf("%d %d %d ", myCards[N_CARDS_INITIAL_HAND-3], second, myCards[N_CARDS_INITIAL_HAND-1]);
    }
    if(third == 42){
      printf("%d %d %d ", third, myCards[N_CARDS_INITIAL_HAND-2], myCards[N_CARDS_INITIAL_HAND-1]);
    }
  }
  else{
    printf("%d %d %d ", myCards[N_CARDS_INITIAL_HAND-3], myCards[N_CARDS_INITIAL_HAND-2], myCards[N_CARDS_INITIAL_HAND-1]);
  }
      
    // NOTE: THE PROVIDED CODE PROBABLY DISCARDS CARDS NOT IN YOUR HAND
    // WHICH IS NOT LEGAL AND WILL RECEIVE PENALTY POINTS
    // YOU MUST CHANGE IT TO DISCARD CARDS FROM YOUR HAND.
  printf("\n");
}


void choose_card_to_play(void) {

    // ADD CODE TO READ THE FIRST THREE NUMBERS WHICH ARE:
    // NUMBER OF CARDS IN YOUR HAND,  NUMBER OF CARDS PLAYED THIS ROUND, TABLE POSITION
  int numbersandposition[3];
  int counter1 = 0;
  while(counter1<3){
    scanf("%d", &numbersandposition[counter1]);
    counter1++;
  }

  int numberofcardsinhand = numbersandposition[0];
  int numberofcardsinround = numbersandposition[1];
  int tableposition = numbersandposition[2];

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
  int cardsinhand[numberofcardsinhand];
  int counter2 = 0;
  while(counter2<numberofcardsinhand){
    scanf("%d", &cardsinhand[counter2]);
    counter2++;
  }

    // ADD CODE TO READ THE CARDS PREVIOUSLY PLAYED THIS ROUND INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
  int cardsinround[numberofcardsinround];
  int counter3 = 0;
  while(counter3<numberofcardsinround){
    scanf("%d", &cardsinround[counter3]);
    counter3++;
  }

    // ADD CODE TO READ THE CARDS PLAYED IN THE HISTORY OF THE GAME INTO AN ARRAY
    // YOU WILL NEED TO USE A WHILE LOOP AND SCANF
  int round = 10 - numberofcardsinhand;
  int previouslyplayed = round*4+numberofcardsinround;
  int cardshistory[previouslyplayed];
  int counter4 = 0;
  while(counter4<previouslyplayed){
    scanf("%d", &cardshistory[counter4]);
    counter4++;
  }

    // THEN REPLACE THIS PRINTF WITH CODE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
  //first determine if I am the first one in the round to play
  int legalmoves[10];
  int firstplay = 0;
  if(previouslyplayed%4==0){
    firstplay = 1;
  }else{
    firstplay = 0;
  }
  for(int i = 0;i<10;i++){
    legalmoves[i] = 0;
  }
  if(firstplay==0){
    int firstcardinround = cardsinround[0];
    int counter5 = 0;
    int bigplaythisround = 0;
    for(int i = 0;i<numberofcardsinround;i++){
      bigplaythisround = bigplaythisround>cardsinround[i]?bigplaythisround:cardsinround[i];
    }
    if(is_prime(firstcardinround)==1){
      for(int i = 0;i<numberofcardsinhand;i++){
	if(is_prime(cardsinhand[i])==1){
	  legalmoves[counter5] = cardsinhand[i];
	  counter5++;
	}
      }
      if(counter5==0){
	for(int i = 0;i<numberofcardsinhand;i++){
	  legalmoves[i] = cardsinhand[i];
	}
      }
    }
    else if(firstcardinround==42){
      for(int i = 0;i<numberofcardsinhand;i++){
	legalmoves[i] = cardsinhand[i];
      }
    }
    else{
      int counter6 = 0;
      for(int i = 0;i<numberofcardsinhand;i++){
	if(is_cocomposite(firstcardinround,cardsinhand[i])){
	  legalmoves[counter6] = cardsinhand[i];
	  counter6++;
	}
      }
      if(counter6==0){
	for(int i = 0;i<numberofcardsinhand;i++){
	  legalmoves[i] = cardsinhand[i];
	}
      }
    }
    printf("%d\n",bestmove(legalmoves,bigplaythisround));
  }
  else{
    int previousprime = 0;
    for(int i = 0;i<previouslyplayed;i++){
      if(is_prime(cardshistory[i])==1){
	previousprime = 1;
      }
    }
    if(previousprime == 0){
      int counter7 = 0;
      for(int i = 0;i<numberofcardsinhand;i++){
	if(is_prime(cardsinhand[i])==0){
	  legalmoves[counter7] = cardsinhand[i];
	  counter7++;
	}
      }
      if(counter7==0){
	for(int i = 0;i<numberofcardsinhand;i++){
	  legalmoves[i] = cardsinhand[i];
	}
      }
    }
    else{
      int counter8 = 0;
      for(int i = 0;i<numberofcardsinhand;i++){
	if(is_prime(cardsinhand[i])==1){
	  legalmoves[counter8] = cardsinhand[i];
	  counter8++;
	}
      }
      if(counter8==0){
	for(int i = 0;i<numberofcardsinhand;i++){
	  legalmoves[i] = cardsinhand[i];
	}
      }
    }
    printf("%d\n",bestmove1(legalmoves));
  }

}

// ADD YOUR FUNCTIONS HERE
int is_prime(int num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}

 int gcd(int a, int b)
 {
   if(a==0)
     return b;
   return gcd(b%a, a);
 }

 int is_cocomposite(int a, int b){
   if((gcd(a, b)!=a)&&(gcd(a,b)!=b)&&(gcd(a, b)!=1)){
       return 1;
     }
     else{
       return 0;
     }
     }

   int bestmove(int legalmoves[10],int bigplaythisround){
     int max = 0;
     for(int i = 0;i<10;i++){
       if((legalmoves[i]>max)&&(legalmoves[i]<bigplaythisround)){
	   max = legalmoves[i];
	 }
	 }
       return max;
     }

     int bestmove1(int legalmoves[10]){
       int min = 50;
       for(int i = 0;i<10;i++){
	 min = min<legalmoves[i]?min:legalmoves[i];
       }
       return min;
     }
     
