#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (i0 + 1) >> 1;
    int end = (i1 + 1) >> 1;
    for (i = start; i < end; i += 2) {
        if (i + 1 < end) {
            p[2 * i + 1] -= (p[2 * i] + p[2 * i + 2]) >> 1;
            p[2 * (i + 1) + 1] -= (p[2 * (i + 1)] + p[2 * (i + 1) + 2]) >> 1;
        } else {
            p[2 * i + 1] -= (p[2 * i] + p[2 * i + 2]) >> 1;
        }
    }
}
