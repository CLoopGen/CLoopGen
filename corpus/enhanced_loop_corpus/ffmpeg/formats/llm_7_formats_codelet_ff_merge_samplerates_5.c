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
    for (i = 0; i < a->refcount && b->refcount < 1000; i++) {
        struct AVFilterFormats ***temp_ref = &(b->refs[b->refcount]);
        *temp_ref = a->refs[i];
        (*temp_ref)++;
        *b->refs[b->refcount] = b;
        b->refcount += (*temp_ref != NULL) ? 1 : 0;
    }
}
