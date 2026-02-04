#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int libs[2];
extern int u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    int limit = (*moves).num;
    for (u = 0; u < limit; u += step) {
        if (u + 1 < (*moves).num) {
            (*moves).score[u] += ((*moves).pos[u] == libs[0]) ? 1 : 0;
            (*moves).score[u+1] += ((*moves).pos[u+1] == libs[0]) ? 1 : 0;
        } else {
            (*moves).score[u] += ((*moves).pos[u] == libs[0]) ? 1 : 0;
        }
    }
}
