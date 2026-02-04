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
        if (u + 1 < limit) {
            if ((*moves).pos[u] == libs[1]) {
                (*moves).score[u] += 1;
                break;
            }
            if ((*moves).pos[u + 1] == libs[1]) {
                (*moves).score[u + 1] += 1;
                break;
            }
        } else {
            if ((*moves).pos[u] == libs[1]) {
                (*moves).score[u] += 1;
                break;
            }
        }
    }
}
