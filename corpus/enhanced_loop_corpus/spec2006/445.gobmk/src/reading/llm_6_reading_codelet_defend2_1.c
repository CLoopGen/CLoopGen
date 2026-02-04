#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern int liberties;
extern int libs[2];
extern struct reading_moves moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by splitting initialization into two stages
    // First, initialize score array
    for (k = 0; k < liberties; k++) {
        moves.score[k] = 0;
    }
    // Second, assign pos with a write-after-write (WAW) dependency on k from previous loop
    for (k = 0; k < liberties; k++) {
        moves.pos[k] = libs[k];
    }
}
