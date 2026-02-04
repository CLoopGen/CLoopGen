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
    for (i = ((i0 + 1) >> 1); i < ((i1 + 1) >> 1); i++) {
        int index = 2 * i;
        if (index > 0) {
            int temp = (p[index - 1] + p[index + 1] + 2) >> 2;
            p[index] += temp;
        }
    }
}
