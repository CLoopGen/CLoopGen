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
    // Variant 1: Strided memory access (stride of 2) with bounds check to stay within valid range
    unsigned int refcount_val = (*ref)->refcount;
    for (i = 0; i < refcount_val; i += 2) {
        if ((*ref)->refs[i] == ref) {
            idx = i;
            break;
        }
    }
    // Handle odd-sized refcount by checking the last element if missed due to stride
    if (idx == -1 && refcount_val > 0 && (refcount_val % 2) == 1) {
        if ((*ref)->refs[refcount_val - 1] == ref) {
            idx = refcount_val - 1;
        }
    }
}
