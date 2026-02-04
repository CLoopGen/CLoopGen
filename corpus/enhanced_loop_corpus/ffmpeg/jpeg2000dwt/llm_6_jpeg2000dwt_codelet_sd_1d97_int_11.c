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
    int temp_load_prev, temp_load_next;
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        temp_load_prev = p[2 * i - 1];
        temp_load_next = p[2 * i + 1];
        p[2 * i] += (29066LL * (temp_load_prev + temp_load_next) + (1 << 15)) >> 16;
    }
}
