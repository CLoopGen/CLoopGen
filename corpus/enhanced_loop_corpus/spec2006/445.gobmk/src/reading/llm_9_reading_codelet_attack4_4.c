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
int j;
for (j = 0; j < moves.num * 2; j += 2) {
    int idx = j / 2;
    moves.score[idx] = moves.score[idx] + 2 + 3; // Equivalent to += 5, but split for more operations
}
}
