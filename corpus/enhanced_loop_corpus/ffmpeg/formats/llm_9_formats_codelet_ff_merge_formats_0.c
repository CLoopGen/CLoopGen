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
    // Variant 2: Reduced computational intensity with simplified indexing and fixed trip count scaling
    const unsigned int limit = (a->refcount > 10) ? 10 : a->refcount; // Cap the loop iterations
    for (i = 0; i < limit; i++) {
        // Remove indirect complexity: use direct assignment without post-increment in pointer dereference
        struct AVFilterFormats ***temp_ref = &ret->refs[ret->refcount];
        *temp_ref = a->refs[i];
        *(a->refs[i]) = ret; // Simplified update, assuming symmetry in reference update
        ret->refcount += 1;
    }
}
