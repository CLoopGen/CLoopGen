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
    unsigned int j;
    for (i = 0; i < a->refcount; i++) {
        j = b->refcount;
        b->refs[j] = a->refs[i];
        *b->refs[j] = b;
        b->refcount++;
    }
}
