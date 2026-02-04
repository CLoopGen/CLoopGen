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
    cmax = 0.0;
    icmax = 0;
    for (j = 1; j <= 8; ++j) {
        integer idx = (j - 1) % 4;
        doublereal temp = equiv_1[idx];
        doublereal abs_temp = temp >= 0 ? temp : -temp;
        if (abs_temp > cmax) {
            cmax = abs_temp;
            icmax = idx + 1;
        }
    }
}
