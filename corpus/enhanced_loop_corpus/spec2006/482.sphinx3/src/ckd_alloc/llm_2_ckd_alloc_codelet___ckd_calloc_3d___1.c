#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern char ***ref1;
extern char **ref2;
extern int32 i;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Reversed Iteration
    // Instead of forward strided access in ref2, traverse i in reverse and compute offset directly.
    // This maintains correctness but changes access pattern to consecutive in reverse order.
    for (i = d1 - 1; i >= 0; i--) {
        offset = i * d2;
        ref1[i] = ref2 + offset;
    }
}
