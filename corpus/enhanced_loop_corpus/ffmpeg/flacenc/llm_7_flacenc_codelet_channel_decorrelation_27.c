#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *left;
extern int32_t *right;
extern int i;
extern int n;
extern int32_t tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        tmp = left[0];
        left[0] = (tmp + right[0]) >> 1;
        right[0] = tmp - right[0];
    }
    for (i = 1; i < n; i++) {
        int32_t prev_tmp = left[i-1]; 
        tmp = left[i];
        left[i] = (tmp + right[i] + (prev_tmp & 1)) >> 1;
        right[i] = tmp - right[i];
    }
}
