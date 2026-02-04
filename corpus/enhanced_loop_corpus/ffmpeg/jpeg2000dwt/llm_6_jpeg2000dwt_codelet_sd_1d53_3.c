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
    int temp;
    for (i = ((i0 + 1) >> 1); i < (i1 + 1) >> 1; i++) {
        temp = (p[2 * i - 1] + p[2 * i + 1] + 2) >> 2;
        p[2 * i] += temp;
    }
}
