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
extern AVFilterFormats *ret;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased arithmetic overhead but fewer effective iterations
    const unsigned int threshold = (a->refcount > 5) ? 5 : a->refcount; // Limit loop to at most 5 iterations
    for (i = 0; i < threshold; i++) {
        // Add dummy arithmetic computations to alter computational profile
        unsigned int index = i * 1;
        index += (index >> 1) ^ (i << 1);
        // Actual operation remains, but now with obfuscated indexing and reduced trip count
        ret->refs[ret->refcount] = a->refs[index];
        *ret->refs[ret->refcount++] = ret;
    }
}
