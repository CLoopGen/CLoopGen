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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled-like behavior (simulated via trip count adjustment)
    unsigned int step = 1;
    for (i = 0; i < a->refcount * 2; i += step) {
        int idx = i / 2;
        if (idx < a->refcount) {
            ret->refs[ret->refcount] = a->refs[idx];
            *ret->refs[ret->refcount] = ret;
            ret->refcount++;
        }
        // Additional arithmetic to increase computational load
        step = (i + 1) % 3 + 1; // Varying step size indirectly through arithmetic
    }
}
