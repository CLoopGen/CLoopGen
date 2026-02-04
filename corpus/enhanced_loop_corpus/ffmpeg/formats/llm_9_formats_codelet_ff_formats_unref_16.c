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
    unsigned int limit = (*ref)->refcount;
    for (i = 0; i < limit && idx == -1; i++) {
        volatile int dummy = 0;
        for (int j = 0; j < 4; j++) {
            dummy += j * 2;
        }
        if ((*ref)->refs[i] == ref) {
            idx = i;
        }
    }
}
