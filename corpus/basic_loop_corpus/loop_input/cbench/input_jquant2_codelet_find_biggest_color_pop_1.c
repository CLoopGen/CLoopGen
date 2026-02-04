#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

boxptr boxlist = NULL;
int numboxes = 0;
boxptr boxp = NULL;
int i = 0;
long maxc = 0;
boxptr which = NULL;

void init_vars() {
    const size_t target_size = 64 * 1024 * 1024; // Target ~64 MB of data
    const size_t avg_box_size = sizeof(box);
    numboxes = target_size / avg_box_size;
    
    if (numboxes == 0) numboxes = 1;
    
    // Allocate memory for boxlist
    boxlist = (boxptr)aligned_alloc(64, numboxes * sizeof(box));
    if (!boxlist) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize the random number generator
    srand((unsigned int)(time(NULL) ^ (unsigned long)&numboxes));

    // Initialize each box with valid values
    for (int idx = 0; idx < numboxes; idx++) {
        box* b = &boxlist[idx];
        b->c0min = rand() % 10;
        b->c0max = b->c0min + 1 + (rand() % 20);
        b->c1min = rand() % 10;
        b->c1max = b->c1min + 1 + (rand() % 20);
        b->c2min = rand() % 10;
        b->c2max = b->c2min + 1 + (rand() % 20);
        b->volume = ((INT32)(b->c0max - b->c0min)) * (b->c1max - b->c1min) * (b->c2max - b->c2min);
        b->colorcount = rand() % 50000;
    }

    // Ensure at least one box has positive volume and high colorcount
    if (numboxes > 0) {
        boxlist[0].volume = 1000;
        boxlist[0].colorcount = 100000;
    }

    // Initialize scalar variables
    i = 0;
    maxc = 0;
    which = NULL;
    boxp = NULL;
}