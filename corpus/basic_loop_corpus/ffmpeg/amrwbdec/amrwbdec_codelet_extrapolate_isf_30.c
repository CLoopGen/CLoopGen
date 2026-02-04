#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < 20 - 16; i++)
    if (diff_isf[i] + diff_isf[i - 1] < 5.) {
        if (diff_isf[i] > diff_isf[i - 1]) {
            diff_isf[i - 1] = 5. - diff_isf[i];
        } else
            diff_isf[i] = 5. - diff_isf[i - 1];
    }

}
