#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < 128; i += 2) {
        int16_t val1 = block[i];
        int16_t val2 = block[i + 1];
        sum += (val1 >= 0 ? val1 : -val1) + (val2 >= 0 ? val2 : -val2);
    }
}
