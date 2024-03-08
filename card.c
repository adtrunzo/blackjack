#include <stdio.h>
#include <stdlib.h> // for drand48
#include "card.h"

/* counts the number of cards in the list headed by "deck" */
int countPile(cardT *pile) {
    int count=0;
    /* When "deck" is NULL (zero), it's at the end. Otherwise,
     * move to the next card and increment the count.
     */
    for(count=0; pile; pile=pile->next)
    {
        count++;
    }
    return count;
}

/* just shows the top card right now */
void showPile(cardT *pile) {
    while (pile != NULL){
    printf("%d%c\n",pile->rank,pile->suit);
    pile  = pile -> next;
}
}
/* Emulates a "riffle shuffle" of "deck". */
cardT *shuffle(cardT *deck) {
    int size = countPile(deck);
    cardT *cut=deck;
    for(int i=0; i<size/2; i++){
        cut=cut->next;
    }
    /* cut is now the card 1/2 way through the deck */
    cardT *riffle=cut->next;
    cut->next = 0; /* deck and riffle now head separate lists */
    /* Shuffle the deck by randomly pulling a card from the head of "deck" or "riffle"
       and make it the new head of "retdeck" */
    cardT *retdeck=0;
    for(;deck || riffle;) { /* just like a while loop */
        cardT *temp;
        if(deck && (!riffle || drand48()<0.5)) {
            /* next card comes from the top of 'deck' */
            temp=deck;
            deck=deck->next;
        } else if(riffle) {
            /* next card comes from the top of 'riffle' */
            temp=riffle;
            riffle=riffle->next;
        }
        /* put the card at the top of the "retdeck" */
        temp->next=retdeck;
        retdeck=temp;
    }
    return retdeck;
}
