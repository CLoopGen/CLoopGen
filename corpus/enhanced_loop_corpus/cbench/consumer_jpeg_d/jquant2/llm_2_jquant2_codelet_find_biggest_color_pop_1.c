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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    maxc = -1;
    which = NULL;
    for (i = 0; i < numboxes; i += 2) {
        boxptr current = &boxlist[i];
        if (current->colorcount > maxc && current->volume > 0) {
            which = current;
            maxc = current->colorcount;
        }
        // Safe bounds check for second element in the pair
        if (i + 1 < numboxes) {
            boxptr next = &boxlist[i + 1];
            if (next->colorcount > maxc && next->volume > 0) {
                which = next;
                maxc = next->colorcount;
            }
        }
    }
}
