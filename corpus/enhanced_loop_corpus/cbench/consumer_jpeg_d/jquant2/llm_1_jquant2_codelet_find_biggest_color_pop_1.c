#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef struct {
    int c0min;
    int c0max;
    int c1min;
    int c1max;
    int c2min;
    int c2max;
    INT32 volume;
    long colorcount;
} box;

typedef box *boxptr;

extern boxptr boxlist;
extern int numboxes;
extern boxptr boxp;
extern int i;
extern long maxc;
extern boxptr which;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < numboxes; i++) {
        for (int j = 0; j < 1; j++) {  // Artificially nested single-iteration loop
            boxp = &boxlist[i];
            if (boxp->colorcount > maxc && boxp->volume > 0) {
                which = boxp;
                maxc = boxp->colorcount;
            }
        }
    }
}
