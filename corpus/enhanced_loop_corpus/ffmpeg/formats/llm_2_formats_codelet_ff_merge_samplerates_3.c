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
    if (b->refcount > 0) {
        for (i = 0; i < b->refcount; i++) {
            ret->refs[ret->refcount] = b->refs[i];
            *ret->refs[ret->refcount++] = ret;
        }
    }
}
