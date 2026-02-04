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

extern AVFilterFormats **ref;
extern int idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index remapping table (simulated static permutation)
    unsigned int refcount_val = (*ref)->refcount;
    // Simulated static remapping table (e.g., reverse order traversal)
    for (i = 0; i < refcount_val; i++) {
        unsigned int mapped_index = refcount_val - 1 - i; // Reverse access pattern
        if ((*ref)->refs[mapped_index] == ref) {
            idx = mapped_index;
            break;
        }
    }
}
