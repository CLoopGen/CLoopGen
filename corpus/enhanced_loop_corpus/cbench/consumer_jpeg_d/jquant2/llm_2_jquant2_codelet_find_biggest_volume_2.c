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
extern INT32 maxv;
extern boxptr which;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating sequentially through boxlist, access every second element first, then the others.
    // This creates a strided access pattern to simulate non-unit stride traversal.
    maxv = -1; // Assuming volume is non-negative, initialize to -1 for correctness
    which = NULL;

    // First pass: even indices (0, 2, 4, ...)
    for (i = 0; i < numboxes; i += 2) {
        boxp = &boxlist[i];
        if (boxp->volume > maxv) {
            which = boxp;
            maxv = boxp->volume;
        }
    }

    // Second pass: odd indices (1, 3, 5, ...)
    for (i = 1; i < numboxes; i += 2) {
        boxp = &boxlist[i];
        if (boxp->volume > maxv) {
            which = boxp;
            maxv = boxp->volume;
        }
    }
}
