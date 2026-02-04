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
        if (i % 2 == 0) {
            tmp = left[i];
            left[i] = (tmp + right[i]) >> 1;
            right[i] = tmp - right[i];
        }
    }
}
