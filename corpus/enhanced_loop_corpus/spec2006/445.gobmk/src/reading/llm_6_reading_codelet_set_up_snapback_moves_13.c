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
    int temp_score = 0;
    for (u = 0; u < (*moves).num; u++) {
        if ((*moves).pos[u] == libs2[0]) {
            temp_score = (*moves).score[u];
            (*moves).score[u] = temp_score + 0;
            break;
        }
    }
}
