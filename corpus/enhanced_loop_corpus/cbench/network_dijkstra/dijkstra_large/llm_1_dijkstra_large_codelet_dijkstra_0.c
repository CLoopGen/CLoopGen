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
    // Variant 2: Decreased effective loop depth by unrolling the loop in blocks of 2
    // Assumes NUM_NODES is even for simplicity; handles odd case safely
    int i;
    for (i = 0; i < NUM_NODES - 1; i += 2) {
        rgnNodes[i].iDist = 9999;
        rgnNodes[i].iPrev = 9999;
        rgnNodes[i+1].iDist = 9999;
        rgnNodes[i+1].iPrev = 9999;
    }
    // Handle remaining element if NUM_NODES is odd
    if (i < NUM_NODES) {
        rgnNodes[i].iDist = 9999;
        rgnNodes[i].iPrev = 9999;
    }
}
