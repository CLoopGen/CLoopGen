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
    int mid = ((i0 + 1) >> 1) - 1;
    int limit = (i1 + 1) >> 1;
    for (i = mid; i < limit; i++) {
        if (2 * i + 1 >= 0) {
            int temp = (p[2 * i] + p[2 * i + 2]) >> 1;
            p[2 * i + 1] -= temp;
        }
    }
}
