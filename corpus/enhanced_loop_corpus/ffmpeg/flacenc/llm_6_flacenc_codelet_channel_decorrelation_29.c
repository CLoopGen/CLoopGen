#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *left;
extern int32_t *right;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp = 0;
    for (i = 0; i < n; i++) {
        temp = left[i] - right[i];
        left[i] = temp;
    }
}
