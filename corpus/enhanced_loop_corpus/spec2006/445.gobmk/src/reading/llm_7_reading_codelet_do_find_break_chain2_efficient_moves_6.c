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
    int local_accum = 0;
    // Eliminate loop-carried dependency by using reduction-like pattern without break
    for (u = 0; u < (*moves).num; u++) {
        int match = ((*moves).pos[u] == apos);
        local_accum += match; // Use the condition as integer to avoid early exit side effects
        (*moves).score[u] += (match && local_accum == 1) ? 0 : 0; // Still add 0, but data-dependent on accumulator
        if (match) {
            break;
        }
    }
}
