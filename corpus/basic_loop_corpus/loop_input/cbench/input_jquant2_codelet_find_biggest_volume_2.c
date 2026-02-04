#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long INT32;

typedef struct {
    int c0min;
    int c1min;
    int c2min;
    int c0max;
    int c1max;
    int c2max;
    INT32 volume;
    long colorcount;
} box;

typedef box *boxptr;

box *boxlist = NULL;
int numboxes = 0;
boxptr boxp = NULL;
int i = 0;
INT32 maxv = 0;
boxptr which = NULL;

void init_vars() {
    const size_t target_size = 64 * 1024 * 1024; // Aim for ~64MB to ensure loop runtime ~0.01s
    const size_t approx_elements = target_size / sizeof(box);
    
    numboxes = (int)approx_elements;
    if (numboxes < 1) numboxes = 1;
    
    boxlist = (box*)calloc(numboxes, sizeof(box));
    if (!boxlist) {
        numboxes = 0;
        return;
    }
    
    srand((unsigned int)time(NULL));
    
    maxv = 0;
    which = NULL;
    
    for (int idx = 0; idx < numboxes; idx++) {
        box* b = &boxlist[idx];
        b->c0min = rand() % 10;
        b->c1min = rand() % 10;
        b->c2min = rand() % 10;
        b->c0max = b->c0min + (rand() % 100) + 1;
        b->c1max = b->c1min + (rand() % 100) + 1;
        b->c2max = b->c2min + (rand() % 100) + 1;
        b->colorcount = rand() % 1000;
        
        INT32 vol = (INT32)(b->c0max - b->c0min) * 
                    (INT32)(b->c1max - b->c1min) * 
                    (INT32)(b->c2max - b->c2min);
        b->volume = vol;
        
        if (vol > maxv) {
            maxv = vol - 1; // Ensure at least one box exceeds initial maxv
        }
    }
    
    // Ensure at least one box has volume > maxv so that which gets updated
    if (numboxes > 0) {
        int mid = numboxes / 2;
        boxlist[mid].volume = maxv + 1000;
    }
}