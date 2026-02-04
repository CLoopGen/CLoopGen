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
int i;
for (i = 0; i < moves.num; i += 2) {
    if (i + 1 < moves.num) {
        moves.score[i] += 5;
        moves.score[i+1] += 5;
    } else {
        moves.score[i] += 5;
    }
}
}
