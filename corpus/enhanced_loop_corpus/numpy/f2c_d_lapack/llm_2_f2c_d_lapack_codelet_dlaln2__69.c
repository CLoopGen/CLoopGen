#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal d__1;
extern doublereal equiv_1[4];
extern integer j;
extern doublereal cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    cmax = 0.0;
    icmax = 1;
    for (j = 1; j <= 4; ++j) {
        int index = (2 * (j - 1)) % 4; // Stride of 2 over the array indices
        doublereal temp = equiv_1[index];
        doublereal abs_val = temp >= 0 ? temp : -temp;
        if (abs_val > cmax) {
            cmax = abs_val;
            icmax = index + 1; // 1-based index
        }
    }
}
