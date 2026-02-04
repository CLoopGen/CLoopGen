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
    int32_t * restrict l = left;
    int32_t * restrict r = right;
    for (i = 0; i < n; i++) {
        r[i] = l[i] - r[i];
    }
}
