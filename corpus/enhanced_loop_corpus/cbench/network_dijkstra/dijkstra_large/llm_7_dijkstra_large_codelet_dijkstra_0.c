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
    // Variant 2: Eliminate parallelism and introduce RAW (read-after-write) loop-carried dependency
    // Make each iteration depend on the previous one using a dummy control variable
    int prev_initialized = 0;
    for (ch = 0; ch < NUM_NODES; ch++) {
        if (ch == 0 || prev_initialized) {
            rgnNodes[ch].iDist = 9999;
            rgnNodes[ch].iPrev = 9999;
            prev_initialized = 1; // Create artificial RAW dependency
        }
    }
}
