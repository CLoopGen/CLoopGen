#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (i = 0; i < 64; i++) {
        int val = block[i];
        temp_sum += (val >= 0 ? val : -val);
    }
    sum = temp_sum;
}
