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
    int limit = ni + (h >> 1);
    for (i = 0; i < limit; i += 2) {
        int idx = i % ni;
        left[idx] = ni - (idx >> 1);
        right[idx] = (i < h) ? ni + 1 : ni - ((i - h) >> 1);
    }
}
