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
    for (i = 0, boxp = boxlist; i < numboxes; i++, boxp++) {
        long temp_count = boxp->colorcount;
        JLONG temp_vol = boxp->volume;
        if (temp_count <= maxc) continue;
        if (temp_vol <= 0) continue;
        which = boxp;
        maxc = temp_count;
    }
}
