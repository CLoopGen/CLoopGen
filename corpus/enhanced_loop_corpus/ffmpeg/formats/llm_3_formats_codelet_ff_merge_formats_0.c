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
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Simulate indirect access by reversing the iteration order (reverse indexing)
    for (i = 0; i < a->refcount; i++) {
        int mapped_index = a->refcount - 1 - i;  // Reverse access pattern
        ret->refs[ret->refcount] = a->refs[mapped_index];
        *ret->refs[ret->refcount++] = ret;
    }
}
