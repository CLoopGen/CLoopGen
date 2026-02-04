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
    int n = (*oldref)->refcount;
    idx = -1;
    for (i = 0; i < n; i += 2) {
        if ((*oldref)->refs[i] == oldref) {
            idx = i;
            break;
        }
        if (i + 1 < n && (*oldref)->refs[i + 1] == oldref) {
            idx = i + 1;
            break;
        }
    }
    if (idx == -1) {
        for (; i < n; i++) {
            if ((*oldref)->refs[i] == oldref) {
                idx = i;
                break;
            }
        }
    }
}
