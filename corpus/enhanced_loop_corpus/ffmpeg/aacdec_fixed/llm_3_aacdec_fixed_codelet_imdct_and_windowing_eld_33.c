#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc((n/2 + 1) * sizeof(int));
    int idx = 0;
    for (int j = 0; j < n; j += 2) {
        indices[idx++] = j;
    }
    for (int k = 0; k < idx; k++) {
        buf[indices[k]] = -buf[indices[k]];
    }
    free(indices);
}
