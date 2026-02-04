#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int c;
extern int shift;
extern int tmp;
extern  int *src;
extern unsigned int *dest;
extern  int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len <= 0) return;
    int prev_tmp = 0;
    for (i = 0; i < len; i++) {
        tmp = (int)(((int64_t)src[i] * c + (int64_t)68719476736L) >> 37);
        tmp += prev_tmp; // Introduce WAW and RAW dependency: current tmp depends on previous iteration's tmp
        dest[i] += tmp * (1U << shift);
        prev_tmp = tmp; // Carry value across iterations (loop-carried dependency)
    }
}
