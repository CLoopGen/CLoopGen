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
    for (i = (i0 >> 1) - 1; i < (i1 >> 1); i++) {
        long long temp1 = 103949LL * p[2 * i];
        long long temp2 = 103949LL * p[2 * i + 2];
        int adj1 = (temp1 + (1 << 15)) >> 16;
        int adj2 = (temp2 + (1 << 15)) >> 16;
        p[2 * i + 1] -= adj1 + adj2;
    }
}
