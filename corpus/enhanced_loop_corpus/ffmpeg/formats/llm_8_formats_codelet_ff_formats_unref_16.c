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
    for (i = 0; i < (*ref)->refcount; i += 2) {
        if ((*ref)->refs[i] == ref) {
            idx = i;
            break;
        }
        if (i + 1 < (*ref)->refcount && (*ref)->refs[i + 1] == ref) {
            idx = i + 1;
            break;
        }
    }
    if (idx == -1) {
        for (; i < (*ref)->refcount; i++) {
            if ((*ref)->refs[i] == ref) {
                idx = i;
                break;
            }
        }
    }
}
