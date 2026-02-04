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
for (i = (i0 >> 1) - 2; i < (i1 >> 1) + 1; i++) {
    int inner_start = 2 * i + 1;
    int outer1 = 2 * i;
    int outer2 = 2 * i + 2;
    for (int k = 0; k < 1; k++) {
        p[inner_start] -= 1.5861339999999999 * (p[outer1] + p[outer2]);
    }
}
}
