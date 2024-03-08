#include "card.h"
#include <stdlib.h> // for drand48
#include <stdio.h>
 
/* This main() is constructed just for testing purposes. See
 * play_game() below for actually connecting together the pieces */
void play_game(void);
// Don't be afraid of writing "scaffolding code" like this: yes, it will be
// removed at the end, but that doesn't make it a waste of effort!
int main(int argc, char *argv[]) {
    // the below "seeds" the random number generator with the first argument
    // given to the program. I.e. "./game 5" will always play with the same
    // shuffle, and "./game 99" will play with a different shuffle. Leave this
    // in your final code for testing.
    if(argc>1) {
        srand48(atol(argv[1]));
    }
    cardT card3={4,'C',NULL}, card2={1,'H',NULL}, card1={12,'S',NULL};
    card1.next=&card2; card2.next=&card3; // Why &card2 and &card3?
    cardT *deck=&card1;
    play_game();
    //printf("Cards in deck: %d\n",countPile(deck));
    //showPile(deck);
    return 0;
 }

// organize all the helper functions to play a complete game
void play_game(void) {
    cardT *deck = makeDeck();
    //showPile(deck);
    deck = shuffle(deck);
    deck = shuffle(deck);
    deck = shuffle(deck);
    deck = shuffle(deck);
    deck = shuffle(deck);
    deck = shuffle(deck);
    deck = shuffle(deck);
    cardT *playerhand = NULL;
    cardT *dealerhand = NULL;
    dealerhand = deal(deck);
    playerhand = deal(deck);
    playerhand->next = deal(deck);
    //showPile(deck);
    printf("Your Hand: ");
    showPile(playerhand);
    printf("Dealer's Hand: ");
    showPile(dealerhand);
    char choice[6];
    int check = 0;
    int count = 0;
    while(check == 0){  
        printf("Hit or Stand?");
        scanf("%s", choice);
        if(choice[0] == 'h' || choice[0] == 'H' || choice [0] == 's' || choice[0] == 'S'){
            if(choice[1] == '\0'){
                if(choice[0] == 'h' || choice[0] == 'H'){
                    cardT *current = playerhand;
                    cardT *next = playerhand->next;
                    while(next->next != NULL){
                        next = next->next;
                    }
                    if(next->next == NULL){
                        next = deal(deck);
                        next->next = current;
                        playerhand = next;
                    
                }
                    printf("Your Hand: ");
                    showPile(playerhand);
                    if(totalPile(playerhand) > 21){
                        //printf("Your Hand (total %d): ", totalPile(playerhand));
                        //showPile(playerhand);
                        //printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                        //showPile(dealerhand);
                        printf("Bust! You Lose!");
                        printf("\n");
                        check = 1;
                    }else if(totalPile(playerhand) == 21){

                        printf("Blackjack!\n");
                        while(totalPile(dealerhand) < 17){
                            cardT *currentd = dealerhand;
                            cardT *nextd = dealerhand->next;
                            while(nextd != NULL){
                                nextd = nextd->next;
                            }
                            if(nextd == NULL){
                                nextd = deal(deck);
                                printf("Dealer Hits: ");
                                showPile(nextd);
                                nextd ->next = currentd;
                                dealerhand = nextd;
                            }
                        }
                            if(totalPile(dealerhand) == 21){
                                printf("Your Hand (total %d): ", totalPile(playerhand));
                                showPile(playerhand);
                                printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                showPile(dealerhand);
                                printf("Dealer Also Has Blackjack! Dealer Wins!");
                                check = 1;
                            }else{
                                if(totalPile(dealerhand) > 21){
                                    printf("Your Hand (total %d): ", totalPile(playerhand));
                                    showPile(playerhand);
                                    printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                    showPile(dealerhand);
                                    printf("Dealer Bust! You Win!");
                                    check = 1;
                                }else{
                                    printf("Your Hand (total %d): ", totalPile(playerhand));
                                    showPile(playerhand);
                                    printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                    showPile(dealerhand);
                                    printf("Blackjack! You Win!\n");
                                    check = 1;
                            }
                           }

                        }
                }else{ //stand
                    int playerscore = totalPile(playerhand);
                    int dealerscore = totalPile(dealerhand);
                    
                        while(dealerscore < 17){
                            cardT *currentd = dealerhand;
                            cardT *nextd = dealerhand->next;
                            while(nextd != NULL){
                                nextd = nextd->next;
                            }
                            if(nextd == NULL){
                                nextd = deal(deck);
                                printf("Dealer Hits: ");
                                showPile(nextd);
                                nextd ->next = currentd;
                                dealerhand = nextd;
                                dealerscore = totalPile(dealerhand);
                            }
                        }
                        if(dealerscore > 21){
                            printf("Your Hand (total %d): ", totalPile(playerhand));
                            showPile(playerhand);
                            printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                            showPile(dealerhand);
                            printf("Dealer Bust! You Win! \n");
                            check = 1;
                            }
                        if(playerscore > dealerscore){
                            printf("Your Hand (total %d): ", totalPile(playerhand));
                            showPile(playerhand);
                            printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                            showPile(dealerhand);
                            printf("You Win \n");
                            check = 1;
                        }else{
                            if(dealerscore == 21){    
                                printf("Your Hand (total %d): ", totalPile(playerhand));
                                showPile(playerhand);
                                printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                showPile(dealerhand);
                                printf("Dealer Has Blackjack! You Lost!\n");
                                check = 1;
                            }else{
                                printf("Your Hand (total %d): ", totalPile(playerhand));
                                showPile(playerhand);
                                printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                showPile(dealerhand);
                                printf("You Lost!\n");
                                check = 1;
                            }
                        }
                            check=1;
                }
              
            } else{
                if(choice[0] == 'h' && choice[1] == 'i' && choice [2] == 't'){ 
                    cardT *current = playerhand;
                    cardT *next = playerhand->next;
                    while(next->next != NULL){
                        next = next->next;
                    }
                    if(next->next == NULL){
                        next = deal(deck);
                        next->next = current;
                        playerhand = next;
                    
                
                    }

                    printf("Your Hand: ");
                    showPile(playerhand);
                    if(totalPile(playerhand) > 21){
                        //printf("Your Hand (total %d): ", totalPile(playerhand));
                        //showPile(playerhand);
                        //printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                        //showPile(dealerhand);
                        printf("Bust! You Lose!\n");
                        check = 1;
                    }else if(totalPile(playerhand) == 21){
                        printf("Blackjack!\n");
                        while(totalPile(dealerhand) < 17){
                            cardT *currentd = dealerhand;
                            cardT *nextd = dealerhand->next;
                            while(nextd != NULL){
                                nextd = nextd->next;
                            }
                            if(nextd == NULL){
                                nextd = deal(deck);
                                nextd ->next = currentd;
                                dealerhand = nextd;
                            }
                        }
                            if(totalPile(dealerhand) == 21){
                                printf("Your Hand (total %d): ", totalPile(playerhand));
                                showPile(playerhand);
                                printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                showPile(dealerhand);
                                printf("Dealer Also Has Blackjack! Dealer Wins!");
                                check = 1;
                            }else{
                                if(totalPile(dealerhand) > 21){
                                    printf("Your Hand (total %d): ", totalPile(playerhand));
                                    showPile(playerhand);
                                    printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                    showPile(dealerhand);
                                    printf("Dealer Bust! You Win!");
                                    check = 1;
                                }
                                else{
                                    printf("Your Hand (total %d): ", totalPile(playerhand));
                                    showPile(playerhand);
                                    printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                    showPile(dealerhand);
                                    printf("Blackjack! You Win!");
                                    check = 1;
                            }
                           
                    
                            }}
                    
                }else{
                    if(choice[0] == 's' && choice[1] == 't' && choice[2] == 'a' && choice[3] == 'n' && choice[4] == 'd'){
                        //stand
                    int playerscores = totalPile(playerhand);
                    int dealerscores = totalPile(dealerhand);
                    while(dealerscores < 17){
                        //add cards
                            cardT *currentd = dealerhand;
                            cardT *nextd = dealerhand->next;
                            while(nextd != NULL){
                                nextd = nextd->next;
                            }
                            if(nextd == NULL){
                                nextd = deal(deck);
                                printf("Dealer Hits: ");
                                showPile(nextd);
                                nextd ->next = currentd;
                                dealerhand = nextd;
                                dealerscores=totalPile(dealerhand);
                            }
                        
                     }
                    if(dealerscores > 21){
                        printf("Your Hand (total %d): ", totalPile(playerhand));
                        showPile(playerhand);
                        printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                        showPile(dealerhand);
                        printf("Dealer Bust! You Win!\n");
                        check = 1;
                    }else{
                        if(playerscores > dealerscores){
                            printf("Your Hand (total %d): ", totalPile(playerhand));
                            showPile(playerhand);
                            printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                            showPile(dealerhand);
                            printf("You Win!\n");
                            check = 1;
                        }else{
                            if(dealerscores == 21){
                                printf("Your Hand (total %d): ", totalPile(playerhand));
                                showPile(playerhand);
                                printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                showPile(dealerhand);
                                printf("Dealer has Blackjack! You Lost!\n");
                                check = 1;
                            }else{
                                printf("Your Hand (total %d): ", totalPile(playerhand));
                                showPile(playerhand);
                                printf("Dealer Hand (total %d): ", totalPile(dealerhand));
                                showPile(dealerhand);
                                printf("You Lose!\n");
                                check = 1;
                            }
                        }
                    }
          
                    }else{
                        check = 0;
                    }
        }
        
            }
        }else{
         check = 0;
        }
}
}
