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
    for (i = 0; i < n * 2; i++) {
        int idx = i / 2;
        if (idx < n) {
            if (i % 2 == 0) {
                right[idx] = left[idx] - right[idx];
            } else {
                right[idx] = right[idx] * 2;
            }
        }
    }
}
