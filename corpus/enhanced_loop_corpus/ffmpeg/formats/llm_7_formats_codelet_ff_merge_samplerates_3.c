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

extern AVFilterFormats *b;
extern AVFilterFormats *ret;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with increased per-iteration work using indirect indexing
    unsigned int step = (b->refcount > 5) ? b->refcount / 4 : 1;
    for (i = 0; i < b->refcount; i += step) {
        // Use modulo-based indexing to simulate non-linear traversal, adding arithmetic overhead
        int idx = (i * 7 + 3) % b->refcount; // Arbitrary scrambling of index
        ret->refs[ret->refcount] = b->refs[idx];
        *ret->refs[ret->refcount++] = ret;
    }
}
