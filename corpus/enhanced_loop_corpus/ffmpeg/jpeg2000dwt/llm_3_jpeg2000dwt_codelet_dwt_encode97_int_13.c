#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *t;
extern int w;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc((w * h) * sizeof(int));
    for (int j = 0; j < w * h; j++) {
        indices[j] = j;
    }
    for (i = 0; i < w * h; i++) {
        int idx = indices[i];
        t[idx] = (t[idx] + ((1 << 8) >> 1)) >> 8;
    }
    free(indices);
}
