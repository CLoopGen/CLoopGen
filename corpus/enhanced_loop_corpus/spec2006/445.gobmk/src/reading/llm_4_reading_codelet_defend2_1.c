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
for (k = 0; k < liberties; k++) {
    if (libs[k] >= 0) {
        moves.pos[k] = libs[k];
        moves.score[k] = 0;
    }
}
}
