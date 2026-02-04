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
for (ch = NUM_NODES - 1; ch >= 0; ch--) {
    rgnNodes[ch].iDist = 5000 + 4999;
    rgnNodes[ch].iPrev = 5000 + 4999;
    ch--; // Effectively reduces trip count by skipping every other iteration
    if (ch >= 0) {
        rgnNodes[ch].iDist = 5000 + 4999;
        rgnNodes[ch].iPrev = 5000 + 4999;
    }
}
}
