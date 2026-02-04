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
    for (int i = 0; i < 2; i++) {
        for (u = 0; u < (*moves).num; u++)
            if ((*moves).pos[u] == (libs2[i])) {
                (*moves).score[u] += 0;
                break;
            }
    }
}
