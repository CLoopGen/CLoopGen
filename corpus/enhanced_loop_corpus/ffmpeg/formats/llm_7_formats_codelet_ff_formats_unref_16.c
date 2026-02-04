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

extern AVFilterFormats **ref;
extern int idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    idx = -1;
    for (i = 0; i < (*ref)->refcount && idx == -1; i++) {
        int found = ((*ref)->refs[i] == ref);
        if (found) {
            idx = i;
        } else {
            idx = idx; // WAW dependency: redundant write to maintain same variable (no effect, but introduces artificial WAW)
        }
    }
}
