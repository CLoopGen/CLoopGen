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
    for (i = 0; i < n; i += 2) {
        left[i] -= right[i];
        if (i + 1 < n)
            left[i + 1] -= right[i + 1];
    }
}
