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
    int local_i;
    boxptr local_boxp;
    long local_maxc = maxc;
    boxptr local_which = which;
    for (local_i = 0, local_boxp = boxlist; local_i < numboxes; local_i++, local_boxp++) {
        if (local_boxp->colorcount > local_maxc && local_boxp->volume > 0) {
            local_maxc = local_boxp->colorcount;
            local_which = local_boxp;
        }
    }
    maxc = local_maxc;
    which = local_which;
}
