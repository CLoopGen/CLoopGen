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

extern AVFilterFormats *b;
extern AVFilterFormats *ret;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (every second element), processing in reverse order with stride of 2
    unsigned int step = 2;
    unsigned int adjusted_count = (b->refcount + step - 1) / step; // Ceiling division
    for (i = 0; i < adjusted_count; i++) {
        int index = b->refcount - 1 - (i * step); // Reverse strided index
        if (index >= 0) {
            ret->refs[ret->refcount] = b->refs[index];
            *ret->refs[ret->refcount++] = ret;
        }
    }
}
