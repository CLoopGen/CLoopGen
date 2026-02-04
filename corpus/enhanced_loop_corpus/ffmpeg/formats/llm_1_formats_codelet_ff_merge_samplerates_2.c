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
    if (a->refcount > 0) { // Decreased effective nesting depth by replacing loop with conditional and unrolled logic
        ret->refs[ret->refcount] = a->refs[0];
        *ret->refs[ret->refcount++] = ret;
        for (i = 1; i < a->refcount; i++) {
            ret->refs[ret->refcount] = a->refs[i];
            *ret->refs[ret->refcount++] = ret;
        }
    }
}
