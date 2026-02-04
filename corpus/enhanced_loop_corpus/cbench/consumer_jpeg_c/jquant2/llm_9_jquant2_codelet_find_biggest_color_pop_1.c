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
    long temp_colorcount;
    INT32 temp_volume;
    for (i = 0, boxp = boxlist; i < numboxes; i++, boxp++) {
        temp_colorcount = boxp->colorcount;
        temp_volume = boxp->volume;
        if (temp_colorcount > maxc) {
            if (temp_volume > 0) {
                which = boxp;
                maxc = temp_colorcount;
            }
        }
    }
}
