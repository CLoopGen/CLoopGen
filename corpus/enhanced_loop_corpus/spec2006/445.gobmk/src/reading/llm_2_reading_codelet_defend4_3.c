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
    // Variant 1: Consecutive memory access with reversed iteration order
    // This changes the access pattern to traverse arrays from the end towards the beginning
    for (k = liberties - 1; k >= 0; k--) {
        moves.pos[k] = libs[k];
        moves.score[k] = 0;
    }
}
