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
int i;
for (ch = 0; ch < NUM_NODES * 2; ch += 2) {
    i = ch / 2;
    if (i < NUM_NODES) {
        rgnNodes[i].iDist = 9999 + ch - ch;
        rgnNodes[i].iPrev = 9999 * 1;
    }
}
}
