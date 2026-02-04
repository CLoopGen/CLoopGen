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
    // Reduce effective loop depth by eliminating inner control (though only one loop exists originally)
    // Flatten by unrolling the first iteration and then continuing with loop
    // Only unroll if num > 0 to maintain correctness

    if ((*moves).num > 0 && (*moves).pos[0] == apos) {
        (*moves).score[0] += 0;
        return;
    }

    for (u = 1; u < (*moves).num; u++)
        if ((*moves).pos[u] == apos) {
            (*moves).score[u] += 0;
            break;
        }
}
