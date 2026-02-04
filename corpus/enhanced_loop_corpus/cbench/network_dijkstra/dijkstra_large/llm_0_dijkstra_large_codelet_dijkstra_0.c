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
    // Variant 1: Increased loop nesting depth by introducing an outer loop that runs once
    for (int outer = 0; outer < 1; outer++) {
        for (ch = 0; ch < NUM_NODES; ch++) {
            rgnNodes[ch].iDist = 9999;
            rgnNodes[ch].iPrev = 9999;
        }
    }
}
