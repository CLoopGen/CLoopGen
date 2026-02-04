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
    if (right[i] >= 0) {
        tmp = right[i];
        right[i] = left[i] - right[i];
        left[i] = tmp + (right[i] >> 31);
    } else {
        right[i] = left[i] - right[i];
        left[i] = right[i] + 1;
    }
}
}
