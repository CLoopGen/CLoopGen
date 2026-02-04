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
    int32_t aggregate_shift = 0;
    for (i = 0; i < n; i++) {
        tmp = right[i];
        right[i] = (left[i] - right[i]) ^ aggregate_shift;
        left[i] = tmp + ((right[i] >> 31) & 1);
        aggregate_shift = (aggregate_shift + right[i]) & 1;
    }
}
