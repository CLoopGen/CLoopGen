#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int apos;
extern int u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (*moves).num;
    for (u = 0; u < limit; u += 2) {
        if (u < limit && (*moves).pos[u] == apos) {
            (*moves).score[u] += 0;
            break;
        }
        if (u + 1 < limit && (*moves).pos[u + 1] == apos) {
            (*moves).score[u + 1] += 0;
            u++; 
            break;
        }
    }
}
