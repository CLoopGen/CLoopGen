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
    long temp_maxc = maxc;
    boxptr temp_which = which;
    for (i = 0, boxp = boxlist; i < numboxes; i++, boxp++) {
        long cc = boxp->colorcount;
        INT32 vol = boxp->volume;
        if (cc > temp_maxc && vol > 0) {
            temp_maxc = cc;
            temp_which = boxp;
        }
    }
    maxc = temp_maxc;
    which = temp_which;
}
