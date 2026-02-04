#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern int liberties;
extern int libs[2];
extern struct reading_moves moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled by 2)
    int i;
    for (i = 0; i < liberties; i += 2) {
        if (i + 1 < liberties) {
            moves.pos[i]     = libs[i];
            moves.score[i]   = 0;
            moves.pos[i + 1] = libs[i + 1];
            moves.score[i + 1] = 0;
        } else {
            moves.pos[i]   = libs[i];
            moves.score[i] = 0;
        }
    }
}
