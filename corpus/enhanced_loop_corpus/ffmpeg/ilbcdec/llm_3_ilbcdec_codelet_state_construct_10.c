#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t len;
extern int k;
extern int16_t *tmp1;
extern int16_t *tmp2;
extern int16_t *tmp3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *indices = (int16_t*)malloc(len * sizeof(int16_t));
    for (int i = 0; i < len; i++) {
        indices[i] = i;
    }
    for (k = 0; k < len; k++) {
        int idx = indices[k];
        *(tmp3 + idx) = *(tmp1 - idx) + *(tmp2 - idx);
    }
    free(indices);
}
