#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef int32 tsize_t;

extern tsize_t stride;
extern char *cp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (forward traversal with sequential indexing)
    tsize_t start = stride - 4;
    for (i = 0; i < start; i++) {
        cp[start - i] -= cp[start - i - 1];
    }
}
