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
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse the array in reverse order to change spatial locality.
    // This modifies the memory access pattern to be consecutive but in descending index order.

    for (i = num - 1; i >= 0; i--) {
        keys[i].pos = firstKeyOfs + (i * keyStep);
        keys[i].flags = 0;
    }
}
