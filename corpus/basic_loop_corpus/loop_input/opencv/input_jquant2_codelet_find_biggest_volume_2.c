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
JLONG maxv = 0;
boxptr which = NULL;

void init_vars() {
    numboxes = 2000000; // Approximate size to achieve ~0.01 sec runtime on modern CPU

    boxlist = (boxptr)aligned_alloc(64, numboxes * sizeof(box));
    if (!boxlist) exit(1);

    for (int idx = 0; idx < numboxes; idx++) {
        box* b = &boxlist[idx];
        b->c0min = rand() % 10;
        b->c1min = rand() % 10;
        b->c2min = rand() % 10;
        b->c0max = b->c0min + rand() % 20 + 1;
        b->c1max = b->c1min + rand() % 20 + 1;
        b->c2max = b->c2min + rand() % 20 + 1;
        b->colorcount = rand() % 1000;
        b->volume = (JLONG)(b->c0max - b->c0min) * (b->c1max - b->c1min) * (b->c2max - b->c2min);
    }

    maxv = 0;
    which = NULL;
    i = 0;
    boxp = boxlist;
}