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
    int found = 0;
    for (i = 0; i < (*ref)->refcount && !found; i++) {
        for (int inner = 0; inner < 1; inner++) {
            if ((*ref)->refs[i] == ref) {
                idx = i;
                found = 1;
                break;
            }
        }
    }
}
