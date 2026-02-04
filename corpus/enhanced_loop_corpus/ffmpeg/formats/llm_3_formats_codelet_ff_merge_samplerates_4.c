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
    // Variant 2: Indirect memory access using an index map (simulated via alternating front and back access)
    // This creates a non-sequential access pattern to b->refs by accessing from both ends
    unsigned int left = 0;
    unsigned int right = b->refcount;
    for (i = 0; i < b->refcount; i++) {
        // Alternate between left and right access
        unsigned int idx = (i % 2 == 0) ? left++ : --right;

        if (idx < b->refcount) {
            a->refs[a->refcount] = b->refs[idx];
            *a->refs[a->refcount++] = a;
        }
    }
}
