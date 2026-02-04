#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef struct {
    int c0min;
    int c0max;
    int c1min;
    int c1max;
    int c2min;
    int c2max;
    JLONG volume;
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
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    maxc = -1;
    which = NULL;
    for (i = 0; i < numboxes; i += 2) {
        boxptr boxp1 = &boxlist[i];
        if (boxp1->colorcount > maxc && boxp1->volume > 0) {
            which = boxp1;
            maxc = boxp1->colorcount;
        }
        if (i + 1 < numboxes) {
            boxptr boxp2 = &boxlist[i + 1];
            if (boxp2->colorcount > maxc && boxp2->volume > 0) {
                which = boxp2;
                maxc = boxp2->colorcount;
            }
        }
    }
}
