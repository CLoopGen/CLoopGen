#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;

typedef struct {
    int c0min;
    int c1min;
    int c2min;
    int c0max;
    int c1max;
    int c2max;
    JLONG volume;
    long colorcount;
} box;

typedef box *boxptr;

boxptr boxlist = NULL;
int numboxes = 0;
boxptr boxp = NULL;
int i = 0;
long maxc = 0;
boxptr which = NULL;

void init_vars() {
    numboxes = 2000000; // Approximately 2M boxes to target ~0.01 sec runtime

    boxlist = (boxptr)aligned_alloc(64, numboxes * sizeof(box));
    if (!boxlist) {
        exit(1);
    }

    for (int idx = 0; idx < numboxes; idx++) {
        box* b = &boxlist[idx];
        b->c0min = idx % 100;
        b->c1min = (idx + 10) % 100;
        b->c2min = (idx + 20) % 100;
        b->c0max = b->c0min + 50;
        b->c1max = b->c1min + 50;
        b->c2max = b->c2min + 50;
        b->volume = (JLONG)(b->c0max - b->c0min) * (b->c1max - b->c1min) * (b->c2max - b->c2min);
        b->colorcount = rand() % 50000;
    }

    maxc = 25000;
    which = NULL;
    i = 0;
}