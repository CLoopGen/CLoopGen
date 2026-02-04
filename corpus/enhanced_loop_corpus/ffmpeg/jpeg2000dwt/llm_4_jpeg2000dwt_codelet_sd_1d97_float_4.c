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
    int start = (i0 >> 1) - 2;
    int end = (i1 >> 1) + 1;
    for (i = start; i < end; i++) {
        if ((p[2 * i] + p[2 * i + 2]) > 0.0f)
            p[2 * i + 1] -= 1.5861339999999999 * (p[2 * i] + p[2 * i + 2]);
    }
}
