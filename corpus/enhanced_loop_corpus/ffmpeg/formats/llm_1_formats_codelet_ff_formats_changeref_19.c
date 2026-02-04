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
    for (i = 0; i < (*oldref)->refcount && idx == 0; i++)
        for (int inner = 0; inner < 1; inner++)
            if ((*oldref)->refs[i] == oldref) {
                idx = i;
                break;
            }
}
