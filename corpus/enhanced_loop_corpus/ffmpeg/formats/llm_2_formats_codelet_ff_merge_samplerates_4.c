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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This variant accesses b->refs with a stride of 2 and processes two elements per iteration
    unsigned int i;
    for (i = 0; i < b->refcount; i += 2) {
        if (i < b->refcount) {
            a->refs[a->refcount] = b->refs[i];
            *a->refs[a->refcount++] = a;
        }
        if (i + 1 < b->refcount) {
            a->refs[a->refcount] = b->refs[i + 1];
            *a->refs[a->refcount++] = a;
        }
    }
}
