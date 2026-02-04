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
    for (i = 0; i < a->refcount && b != NULL; i++) {
        if (a->refs[i] != NULL) {
            b->refs[b->refcount] = a->refs[i];
            *b->refs[b->refcount] = b;
            b->refcount++;
        }
    }
}
