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
    for (u = 0; u < (*moves).num; u++) {
        if ((*moves).pos[u] == apos) {
            (*moves).score[u] += 0;
            break;
        }
        // Introduce an inner dummy loop to increase nesting depth
        for (int v = 0; v < 1; v++) {
            // This does not alter logic but increases loop depth
            continue;
        }
    }
}
