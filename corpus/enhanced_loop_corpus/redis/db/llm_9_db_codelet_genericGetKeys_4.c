#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int pos;
    int flags;
} keyReference;

extern int firstKeyOfs;
extern int keyStep;
extern int i;
extern int num;
extern keyReference *keys;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count with increased per-iteration work: unroll by 2x manually
    int stride = 2;
    int limit = (num / stride) * stride;
    for (i = 0; i < limit; i += stride) {
        // Unrolled operations: two iterations combined
        keys[i].pos = firstKeyOfs + (i * keyStep);
        keys[i].flags = 0;
        keys[i+1].pos = firstKeyOfs + ((i+1) * keyStep);
        keys[i+1].flags = 0;
    }
    // Handle remainder
    for (; i < num; i++) {
        keys[i].pos = firstKeyOfs + (i * keyStep);
        keys[i].flags = 0;
    }
}
