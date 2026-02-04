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
    for (i = a->refcount - 1; i != (unsigned int)-1; i--) {
        ret->refs[ret->refcount] = a->refs[i];
        *ret->refs[ret->refcount] = ret;
        ret->refcount++;
    }
}
