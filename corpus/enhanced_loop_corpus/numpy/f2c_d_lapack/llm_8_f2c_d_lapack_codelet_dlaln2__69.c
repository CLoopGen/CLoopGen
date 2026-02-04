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
    for (j = 1; j <= 4; ++j) {
        doublereal temp = equiv_1[j - 1];
        doublereal abs_temp = temp >= 0 ? temp : -temp;
        if (abs_temp > cmax) {
            cmax = abs_temp;
            icmax = j;
        }
    }
}
