#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < length; i += step) {
        int16_t val1 = vector[i];
        int16_t abs_val1 = (val1 >= 0) ? val1 : -val1;
        max |= abs_val1;

        if (i + 1 < length) {
            int16_t val2 = vector[i + 1];
            int16_t abs_val2 = (val2 >= 0) ? val2 : -val2;
            max |= abs_val2;
        }
    }
}
