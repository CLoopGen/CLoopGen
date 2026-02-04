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
for (k = 0; k < moves.num; k++) {
    if (moves.score[k] < 0)
        continue;
    moves.score[k] += 5;
}
}
