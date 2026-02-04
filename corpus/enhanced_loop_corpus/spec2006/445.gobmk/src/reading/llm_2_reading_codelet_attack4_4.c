#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern int k;
extern struct reading_moves moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then the odd indices)
    int i;
    for (i = 0; i < moves.num; i += 2)
        moves.score[i] += 5;
    for (i = 1; i < moves.num; i += 2)
        moves.score[i] += 5;
}
