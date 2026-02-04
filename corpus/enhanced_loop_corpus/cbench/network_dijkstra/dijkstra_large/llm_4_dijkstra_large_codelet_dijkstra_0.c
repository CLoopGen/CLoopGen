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
for (ch = 0; ch < NUM_NODES; ch++) {
    if (ch % 2 == 0) {
        rgnNodes[ch].iDist = 9999;
        rgnNodes[ch].iPrev = 9999;
    } else {
        continue;
    }
}
}
