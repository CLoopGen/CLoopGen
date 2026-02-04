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
    // Variant 2: Reduced arithmetic and simplified control flow with direct indexing and halved effective iterations
    int step = 2;
    for (i = 0; i < b->refcount; i += step) {
        a->refs[a->refcount] = b->refs[i];
        *a->refs[a->refcount] = a;
        a->refcount++;
    }
}
