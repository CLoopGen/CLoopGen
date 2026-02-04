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
    for (i = 0; i < n; i++) {
        int32_t diff = left[i] - right[i];
        tmp = right[i];
        right[i] = diff;
        left[i] = tmp + ((diff - tmp) >> 31) + (diff >> 1); 
    }
}
