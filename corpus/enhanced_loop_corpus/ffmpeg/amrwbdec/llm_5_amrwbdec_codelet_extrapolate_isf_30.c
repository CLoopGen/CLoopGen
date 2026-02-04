#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 20 - 16; i++) {
        float a = diff_isf[i - 1];
        float b = diff_isf[i];
        if (!(b + a < 5.)) continue;
        if (b > a)
            diff_isf[i - 1] = 5. - b;
        else
            diff_isf[i] = 5. - a;
    }
}
