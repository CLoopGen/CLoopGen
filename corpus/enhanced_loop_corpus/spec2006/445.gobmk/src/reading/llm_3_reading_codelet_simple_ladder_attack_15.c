#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern int libs[2];
extern int k;
extern struct reading_moves moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 2; k++) {
        int u;
        int matched = 0;
        // Modify access pattern to indirect via pointer arithmetic
        int *pos_ptr = moves.pos;
        int *score_ptr = moves.score;
        for (u = 0; u < moves.num; u++) {
            if (*(pos_ptr + u) == libs[k]) {
                *(score_ptr + u) += 0;
                matched = 1;
                break;
            }
        }
        if (!matched && moves.num < 50) {
            *(pos_ptr + moves.num) = libs[k];
            *(score_ptr + moves.num) = 0;
            moves.num++;
        }
    }
}
