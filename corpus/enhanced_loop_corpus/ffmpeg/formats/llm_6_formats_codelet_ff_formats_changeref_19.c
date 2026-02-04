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
    idx = -1;
    for (i = 0; i < (*oldref)->refcount && idx == -1; i++) {
        int found = ((*oldref)->refs[i] == oldref);
        if (found) {
            idx = i;
        }
    }
}
