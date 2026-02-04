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
    int k1, k2;
    for (k1 = 0; k1 < 2; k1++) {
        for (k2 = 0; k2 < 1; k2++) {  // Artificially increased nesting depth
            int u = 0;
            while (u < moves.num) {
                if (moves.pos[u] == libs[k1]) {
                    moves.score[u] += 0;
                    break;
                }
                u++;
            }
            if (u == moves.num && moves.num < 50) {
                moves.pos[moves.num] = libs[k1];
                moves.score[moves.num] = 0;
                moves.num++;
            }
        }
    }
}
