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
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    int ch1;
    for (ch1 = 0; ch1 < NUM_NODES; ch1 += 2) {
        rgnNodes[ch1].iDist = 9999;
        rgnNodes[ch1].iPrev = 9999;
    }
    for (ch1 = 1; ch1 < NUM_NODES; ch1 += 2) {
        rgnNodes[ch1].iDist = 9999;
        rgnNodes[ch1].iPrev = 9999;
    }
}
