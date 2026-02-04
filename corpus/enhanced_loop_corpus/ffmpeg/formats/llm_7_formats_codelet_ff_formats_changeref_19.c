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

extern AVFilterFormats **oldref;
extern int idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int count = (*oldref)->refcount;
    AVFilterFormats ***refs_ptr = (*oldref)->refs;
    idx = -1;
    for (i = 0; i < count; i++) {
        if (*(refs_ptr + i) == oldref) {
            idx = i;
            break;
        }
    }
}
