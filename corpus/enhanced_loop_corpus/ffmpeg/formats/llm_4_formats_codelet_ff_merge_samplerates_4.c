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
extern AVFilterFormats *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (b->refcount > 0) {
        a->refs[a->refcount] = b->refs[0];
        *a->refs[a->refcount] = a;
        for (i = 1; i < b->refcount; i++) {
            a->refs[a->refcount + i] = b->refs[i];
            *a->refs[a->refcount + i] = a;
        }
        a->refcount += b->refcount;
    }
}
