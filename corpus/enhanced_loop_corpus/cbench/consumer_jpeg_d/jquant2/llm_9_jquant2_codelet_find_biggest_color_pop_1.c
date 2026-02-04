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
    maxc = -1;
    which = NULL;
    for (i = 0; i < numboxes * 2; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        boxptr b1 = &boxlist[idx1];
        if (idx1 < numboxes && b1->colorcount > maxc && b1->volume > 0) {
            which = b1;
            maxc = b1->colorcount;
        }
        if (idx2 < numboxes) {
            boxptr b2 = &boxlist[idx2];
            if (b2->colorcount > maxc && b2->volume > 0) {
                which = b2;
                maxc = b2->colorcount;
            }
        }
    }
}
