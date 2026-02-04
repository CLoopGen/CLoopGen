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

extern AVFilterFormats **oldref;
extern int idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array
    // Simulate indirect access via a permutation/index table (conceptual optimization scenario)
    unsigned int refcount = (*oldref)->refcount;
    struct AVFilterFormats ***refs = (*oldref)->refs;

    // Assume we have a precomputed indirect index array (common in data prefetching or reordering optimizations)
    // Here we simulate accessing elements in reverse order (a form of indirect access pattern)
    for (i = 0; i < refcount; i++) {
        int rev_index = refcount - 1 - i;  // Reverse traversal
        if (refs[rev_index] == oldref) {
            idx = rev_index;
            break;
        }
    }
}
