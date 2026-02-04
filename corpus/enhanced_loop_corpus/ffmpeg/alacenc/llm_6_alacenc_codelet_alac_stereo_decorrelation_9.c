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
    int32_t temp_left, temp_right;
    for (i = 0; i < n; i++) {
        temp_left = left[i];
        temp_right = right[i];
        left[i] = (temp_left + temp_right) >> 1;
        right[i] = temp_left - temp_right;
    }
}
