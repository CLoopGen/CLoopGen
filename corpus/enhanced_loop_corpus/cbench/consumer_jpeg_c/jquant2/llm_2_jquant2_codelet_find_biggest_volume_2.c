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
    // Variant 1: Strided memory access with step size of 2, unrolled to handle odd numboxes
    maxv = -1;
    which = NULL;
    int stride = 2;
    for (i = 0; i < numboxes; i += stride) {
        boxptr current = &boxlist[i];
        if (current->volume > maxv) {
            which = current;
            maxv = current->volume;
        }
        // Handle odd index if exists
        if ((i + 1) < numboxes) {
            boxptr next = &boxlist[i + 1];
            if (next->volume > maxv) {
                which = next;
                maxv = next->volume;
            }
        }
    }
}
