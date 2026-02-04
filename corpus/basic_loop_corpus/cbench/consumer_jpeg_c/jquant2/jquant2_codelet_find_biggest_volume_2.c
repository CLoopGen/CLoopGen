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
for (i = 0 , boxp = boxlist; i < numboxes; i++ , boxp++) {
    if (boxp->volume > maxv) {
        which = boxp;
        maxv = boxp->volume;
    }
}

}
