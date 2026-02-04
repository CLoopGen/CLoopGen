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
    // Variant 1: Strided memory access with step size 2 (unrolled-like pattern)
    unsigned int refcount = (*oldref)->refcount;
    struct AVFilterFormats ***refs = (*oldref)->refs;
    
    // Process two elements per iteration with stride of 2
    for (i = 0; i < refcount; i += 2) {
        if (i < refcount && refs[i] == oldref) {
            idx = i;
            break;
        }
        if (i + 1 < refcount && refs[i + 1] == oldref) {
            idx = i + 1;
            break;
        }
    }
}
