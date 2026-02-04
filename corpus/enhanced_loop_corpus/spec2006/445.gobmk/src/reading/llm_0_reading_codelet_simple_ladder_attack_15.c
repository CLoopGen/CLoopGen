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
        for (u = 0; u < moves.num; u++) {
            if (moves.pos[u] == libs[k]) {
                moves.score[u] += 0;
                goto next_k;
            }
        }
        if (u == moves.num && moves.num < 50) {
            moves.pos[moves.num] = libs[k];
            moves.score[moves.num] = 0;
            moves.num++;
        }
        next_k:;
    }
}
