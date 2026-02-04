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
        i = 0;
        for (int stride = 1; stride <= n; stride <<= 1) {
            for (int k = 0; k < stride; k++) {
                if (i < n) {
                    tmp = left[i];
                    left[i] = (tmp + right[i]) >> 1;
                    right[i] = tmp - right[i];
                    i++;
                }
            }
        }
    }
}
