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
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        float left = p[2 * i - 2];
        float right = p[2 * i + 2];
        float center_left = p[2 * i - 1];
        float center_right = p[2 * i + 1];
        p[2 * i] -= 0.052979999999999999 * ((left + right) * 0.5 + (center_left + center_right) * 0.25);
    }
}
