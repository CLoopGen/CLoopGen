#include <stdio.h>

#include <inttypes.h>

struct _NODE {
    int iDist;
    int iPrev;
};


typedef struct _NODE NODE;

extern int NUM_NODES;
extern NODE *rgnNodes;
extern int ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int ch1, ch2;
    // Variant 1: Introduce loop-carried WAW dependency by splitting initialization into two stages
    // First pass: Initialize iDist only
    for (ch1 = 0; ch1 < NUM_NODES; ch1++) {
        rgnNodes[ch1].iDist = 9999;
    }
    // Second pass: Initialize iPrev with dependence on first pass completion (WAW: write-after-write)
    for (ch2 = 0; ch2 < NUM_NODES; ch2++) {
        rgnNodes[ch2].iPrev = 9999;
    }
}
