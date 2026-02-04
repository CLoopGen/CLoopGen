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
    for (i = 0; i < n; i += 2) {
        tmp = left[i];
        left[i] = (tmp + right[i]) >> 1;
        right[i] = tmp - right[i];

        if (i + 1 < n) {
            tmp = left[i + 1];
            left[i + 1] = (tmp + right[i + 1]) >> 1;
            right[i + 1] = tmp - right[i + 1];
        }
    }
}
}
