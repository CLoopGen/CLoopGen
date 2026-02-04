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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing keys sequentially, write to every other element first, then fill the gaps.
    // This creates a strided access pattern with stride 2.

    int n = num;
    for (i = 0; i < n; i += 2) {
        keys[i].pos = firstKeyOfs + (i * keyStep);
        keys[i].flags = 0;
    }
    for (i = 1; i < n; i += 2) {
        keys[i].pos = firstKeyOfs + (i * keyStep);
        keys[i].flags = 0;
    }
}
