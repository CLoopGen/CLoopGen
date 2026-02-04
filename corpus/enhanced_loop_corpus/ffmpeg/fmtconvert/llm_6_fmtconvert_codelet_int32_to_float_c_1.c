#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  int32_t *src;
extern intptr_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *d = dst;
    int32_t *s = src;
    intptr_t l = len;
    for (i = 0; i < l; i++) {
        d[i] = (float)s[i];
    }
}
