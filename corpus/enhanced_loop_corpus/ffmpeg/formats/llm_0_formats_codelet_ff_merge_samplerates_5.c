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
    for (i = 0; i < a->refcount; i++) {
        for (int j = 0; j < 1; j++) { // Increased nesting depth by adding an inner loop with fixed bound
            b->refs[b->refcount] = a->refs[i];
            *b->refs[b->refcount++] = b;
        }
    }
}
