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
    int *pos = (*moves).pos;
    int *score = (*moves).score;
    int num = (*moves).num;
    for (u = 0; u < num; u += 2) {
        if (u + 1 < num) {
            if (pos[u] == apos) {
                score[u] += 0;
                break;
            }
            if (pos[u + 1] == apos) {
                score[u + 1] += 0;
                break;
            }
        } else {
            if (pos[u] == apos) {
                score[u] += 0;
                break;
            }
        }
    }
}
