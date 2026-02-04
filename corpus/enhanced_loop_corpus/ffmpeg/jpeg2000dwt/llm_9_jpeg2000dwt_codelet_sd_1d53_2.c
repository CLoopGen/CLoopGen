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
    int trip_count = ((i1 + 1) >> 1) - ((i0 + 1) >> 1);
    for (i = 0; i < trip_count; i++) {
        int idx = ((i0 + 1) >> 1) + i;
        int val_left = p[2 * idx];
        int val_right = p[2 * idx + 2];
        int avg = (val_left + val_right) >> 1;
        p[2 * idx + 1] -= avg;
    }
}
