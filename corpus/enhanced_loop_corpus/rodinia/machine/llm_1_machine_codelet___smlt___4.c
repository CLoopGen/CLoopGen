#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp;
extern double s;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = len / 2;
    int remainder = len % 2;
    for (i = 0; i < outer; i++) {
        (*out++) = s * (*dp++);
        (*out++) = s * (*dp++);
    }
    if (remainder) {
        (*out++) = s * (*dp++);
    }
}
