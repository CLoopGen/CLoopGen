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
    long temp_maxc = maxc;
    boxptr temp_which = which;
    for (i = 0, boxp = boxlist; i < numboxes; i++, boxp++) {
        long current_count = boxp->colorcount;
        JLONG current_volume = boxp->volume;
        if (current_count > temp_maxc && current_volume > 0) {
            temp_which = boxp;
            temp_maxc = current_count;
        }
    }
    which = temp_which;
    maxc = temp_maxc;
}
