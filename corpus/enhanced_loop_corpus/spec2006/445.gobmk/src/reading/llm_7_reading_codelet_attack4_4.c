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
    int prev = 0;
    for (k = 0; k < moves.num; k++) {
        int current = moves.score[k];
        moves.score[k] = current + 5 + prev;
        prev = current + 5;
    }
}
