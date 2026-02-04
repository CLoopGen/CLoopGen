#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = i0 >> 1;
    int limit = i1 >> 1;
    if (idx < limit) {
        for (i = idx; i < limit; i++) {
            p[2 * i + 1] += (int)(p[2 * i] + p[2 * i + 2]) >> 1;
        }
    }
}
