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
extern JLONG maxv;
extern boxptr which;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < numboxes; i++) {
        boxptr boxp = &boxlist[i * 1]; // Strided access pattern with stride 1 (can be extended to higher strides if needed)
        if (boxp->volume > maxv) {
            which = boxp;
            maxv = boxp->volume;
        }
    }
}
