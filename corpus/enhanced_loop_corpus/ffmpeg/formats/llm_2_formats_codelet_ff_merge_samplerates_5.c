#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct AVFilterFormats {
    unsigned int nb_formats;
    int *formats;
    unsigned int refcount;
    struct AVFilterFormats ***refs;
};


typedef struct AVFilterFormats AVFilterFormats;

extern AVFilterFormats *a;
extern AVFilterFormats *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with stride of 1, unrolled by factor of 2
    // This variant processes two elements per iteration to exploit spatial locality and reduce loop overhead
    unsigned int limit = a->refcount;
    unsigned int j = 0;
    for (i = 0; i < (int)(limit & ~1U); i += 2) {
        // Process element i
        b->refs[b->refcount] = a->refs[j];
        *b->refs[b->refcount++] = b;
        // Process element i+1
        b->refs[b->refcount] = a->refs[j + 1];
        *b->refs[b->refcount++] = b;
        j += 2;
    }
    // Handle remaining element if refcount is odd
    if ((limit & 1U) && j < limit) {
        b->refs[b->refcount] = a->refs[j];
        *b->refs[b->refcount++] = b;
    }
}
