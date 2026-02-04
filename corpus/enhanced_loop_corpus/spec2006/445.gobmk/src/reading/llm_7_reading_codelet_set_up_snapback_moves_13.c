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
    int i, found = 0;
    for (i = 0; i < (*moves).num && !found; i++) {
        (*moves).score[i] += ((*moves).pos[i] == libs2[0]) ? 0 : 0;
        if ((*moves).pos[i] == libs2[0]) {
            u = i;
            found = 1;
        }
    }
    if (!found) u = (*moves).num;
}
