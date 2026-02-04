#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float alpha = 0.882911f;
    int start = (i0 >> 1);
    int end = (i1 >> 1) + 2;
    for (i = start; i < end; i++) {
        int idx = 2 * i;
        p[idx - 1] += alpha * (p[idx - 2] + p[idx]);
        p[idx + 1] += alpha * (p[idx] + p[idx + 2]);
    }
}
