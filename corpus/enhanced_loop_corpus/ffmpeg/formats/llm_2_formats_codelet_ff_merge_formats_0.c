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
    // Variant 1: Strided memory access with step size 2, unrolling every two iterations
    for (i = 0; i < a->refcount; i += 2) {
        // First stride
        if (i < a->refcount) {
            ret->refs[ret->refcount] = a->refs[i];
            *ret->refs[ret->refcount++] = ret;
        }
        // Second stride
        if (i + 1 < a->refcount) {
            ret->refs[ret->refcount] = a->refs[i + 1];
            *ret->refs[ret->refcount++] = ret;
        }
    }
}
