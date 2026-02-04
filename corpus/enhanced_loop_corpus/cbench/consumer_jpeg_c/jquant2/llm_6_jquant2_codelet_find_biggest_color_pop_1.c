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



void loop(){
    long temp_maxc = maxc;
    boxptr temp_which = which;
    for (i = 0; i < numboxes; i++) {
        boxptr current = &boxlist[i];
        if (current->colorcount > temp_maxc && current->volume > 0) {
            temp_which = current;
            temp_maxc = current->colorcount;
        }
    }
    which = temp_which;
    maxc = temp_maxc;
}
