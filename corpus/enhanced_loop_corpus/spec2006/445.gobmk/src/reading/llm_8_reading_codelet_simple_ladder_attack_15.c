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
        int u = 0;
        int found = 0;
        while (u < moves.num && !found) {
            if (moves.pos[u] == libs[k]) {
                moves.score[u] += 0;
                found = 1;
            }
            u++;
        }
        if (!found && moves.num < 50) {
            moves.pos[moves.num] = libs[k];
            moves.score[moves.num] = 0;
            moves.num++;
        }
    }
}
