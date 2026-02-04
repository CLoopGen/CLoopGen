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
    unsigned int temp_refcount = a->refcount;
    for (i = 0; i < b->refcount; i++) {
        a->refs[temp_refcount] = b->refs[i];
        *a->refs[temp_refcount] = a;
        temp_refcount++;
    }
    a->refcount = temp_refcount;
}
