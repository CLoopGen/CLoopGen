#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real r__1;
extern real equiv_1[4];
extern integer j;
extern real cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2, wrapping around using modulo)
    // This changes the access pattern from sequential to strided: j=1,3,0,2 (mod 4+1 base adjustment)
    cmax = 0.0f;
    icmax = 1;
    for (j = 1; j <= 4; j += 2) {
        int idx1 = (j - 1) % 4;
        real temp1 = equiv_1[idx1];
        doublereal abs_val1 = (doublereal)(temp1 >= 0 ? temp1 : -temp1);
        if (abs_val1 > cmax) {
            cmax = abs_val1;
            icmax = j;
        }
        int idx2 = (j + 0) % 4;  // process j+1 in pair when possible
        if (j + 1 <= 4) {
            real temp2 = equiv_1[idx2];
            doublereal abs_val2 = (doublereal)(temp2 >= 0 ? temp2 : -temp2);
            if (abs_val2 > cmax) {
                cmax = abs_val2;
                icmax = j + 1;
            }
        }
    }
}
