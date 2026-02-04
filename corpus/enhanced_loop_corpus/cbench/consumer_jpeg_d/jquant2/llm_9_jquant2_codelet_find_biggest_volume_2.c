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
    // Unroll the loop by a factor of 2 to reduce trip count and increase per-iteration work
    int limit = (numboxes / 2) * 2; // Round down to nearest even number
    boxptr current = boxlist;
    for (i = 0; i < limit; i += 2, current += 2) {
        // Process two elements per iteration
        if (current->volume > maxv) {
            which = current;
            maxv = current->volume;
        }
        if ((current+1)->volume > maxv) {
            which = current + 1;
            maxv = (current+1)->volume;
        }
    }
    // Handle remaining element if numboxes is odd
    if (numboxes > limit) {
        boxptr last = boxlist + numboxes - 1;
        if (last->volume > maxv) {
            which = last;
            maxv = last->volume;
        }
    }
}
