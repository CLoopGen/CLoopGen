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
    long local_maxc = maxc;
    boxptr local_which = which;
    int step = 1;
    for (i = 0, boxp = boxlist; i < numboxes; i += step, boxp += step) {
        long count = boxp->colorcount;
        JLONG vol = boxp->volume;
        if (count > local_maxc && vol > 0) {
            local_which = boxp;
            local_maxc = count;
        }
    }
    which = local_which;
    maxc = local_maxc;
}
