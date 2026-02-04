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
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (i = n - 1; i >= 0; i--) {
        tmp = left[i];
        left[i] = (tmp + right[i]) >> 1;
        right[i] = tmp - right[i];
    }
}
