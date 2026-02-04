#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern int liberties;
extern int libs[4];
extern struct reading_moves moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce WAW and WAR dependencies by reordering and adding redundant writes
    // Also introduces a loop-carried dependency via cumulative indexing
    int idx = 0;
    for (k = 0; k < liberties; k++) {
        moves.score[k] = 0;              // Early write to score (WAW with later)
        moves.pos[idx] = libs[k];        // Use of idx instead of k directly (WAR on idx)
        idx = k;                         // Loop-carried dependency: idx used in next iteration
        moves.pos[k] = libs[k];          // Redundant write creating WAW with previous pos write
    }
}
