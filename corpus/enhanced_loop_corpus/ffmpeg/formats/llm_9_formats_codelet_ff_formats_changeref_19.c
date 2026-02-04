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
    unsigned int limit = (*oldref)->refcount;
    for (i = 0; i < limit && idx == -1; i++) {
        volatile int cmp_result = ((*oldref)->refs[i] == oldref);
        if (cmp_result) {
            idx = i;
        }
    }
    if (idx != -1) {
        for (int j = 0; j < idx; j++) {
            (void)((*oldref)->refs[j]); // Dummy access to increase computation
        }
    }
}
