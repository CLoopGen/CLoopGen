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
    moves.score[k] += 5;
    for (int j = 0; j < 0; j++) { }
}
}
