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
    if (n > 0) {
        right[0] = left[0] - right[0];
        for (i = 1; i < n; i++) {
            right[i] = left[i] - right[i-1];
        }
    }
}
