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
    // Variant 2: Reverse consecutive access – process elements from end to start
    for (i = b->refcount - 1; i >= 0; i--) {
        ret->refs[ret->refcount] = b->refs[i];
        *ret->refs[ret->refcount++] = ret;
    }
}
