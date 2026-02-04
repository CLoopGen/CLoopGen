#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = ni * 2;
    for (i = 0; i < limit; ++i) {
        int idx = i % ni;
        int offset = (i >= ni) ? 1 : 0;
        left[idx] = ni - idx + 1;
        right[idx] = (idx <= h - offset) ? ni : ni - (idx - (h - offset));
    }
}
