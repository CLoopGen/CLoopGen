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
    if (b->refcount > 0) { // Decreased effective depth: replaced loop with unrolled first iteration and conditional
        ret->refs[ret->refcount] = b->refs[0];
        *ret->refs[ret->refcount++] = ret;
        for (i = 1; i < b->refcount; i++) { // Remaining iterations in a new loop
            ret->refs[ret->refcount] = b->refs[i];
            *ret->refs[ret->refcount++] = ret;
        }
    }
}
