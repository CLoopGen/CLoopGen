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



void loop() {
    // Variant 1: Strided Memory Access (access every second element, then handle remainder)
    maxc = -1;
    which = NULL;
    
    int stride = 2;
    // First pass: strided access
    for (i = 0; i < numboxes; i += stride) {
        boxptr boxp = &boxlist[i];
        if (boxp->colorcount > maxc && boxp->volume > 0) {
            which = boxp;
            maxc = boxp->colorcount;
        }
    }
    // Second pass: handle odd indices if numboxes is odd
    for (i = 1; i < numboxes; i += stride) {
        boxptr boxp = &boxlist[i];
        if (boxp->colorcount > maxc && boxp->volume > 0) {
            which = boxp;
            maxc = boxp->colorcount;
        }
    }
}
