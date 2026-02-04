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
    for (i = 0; i < numboxes; i++) {
        boxptr current = &boxlist[i];
        long count = current->colorcount;
        JLONG vol = current->volume;
        int c0_range = current->c0max - current->c0min;
        int c1_range = current->c1max - current->c1min;
        int c2_range = current->c2max - current->c2min;
        JLONG computed_volume = (JLONG)c0_range * c1_range * c2_range;
        if (count > local_maxc && computed_volume > 0) {
            local_which = current;
            local_maxc = count;
        }
    }
    which = local_which;
    maxc = local_maxc;
}
