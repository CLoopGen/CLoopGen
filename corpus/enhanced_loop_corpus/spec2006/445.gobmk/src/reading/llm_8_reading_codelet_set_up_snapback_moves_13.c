#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int libs2[2];
extern int u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < (*moves).num * 2; i += 2) {
        int idx = i / 2;
        if ((*moves).pos[idx] == libs2[0]) {
            (*moves).score[idx] += 1;
            break;
        }
        if (i + 1 < (*moves).num * 2 && (*moves).pos[idx + 1] == libs2[0]) {
            (*moves).score[idx + 1] += 1;
            break;
        }
    }
}
