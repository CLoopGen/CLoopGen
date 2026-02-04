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
    int found = -1;
    // Eliminate loop-carried dependency by separating search and update
    for (u = 0; u < (*moves).num; u++) {
        if ((*moves).pos[u] == libs[0]) {
            found = u;
            break;
        }
    }
    // Data update is now independent — no RAW within the loop
    if (found != -1) {
        (*moves).score[found] += 1;
    }
}
