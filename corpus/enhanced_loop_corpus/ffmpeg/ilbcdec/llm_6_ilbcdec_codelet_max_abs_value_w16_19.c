#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int i;
extern int absolute;
extern int maximum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_max = maximum;
    for (i = 0; i < length; i++) {
        int16_t val = vector[i];
        int16_t abs_val = (val >= 0) ? val : -val;
        temp_max = (abs_val > temp_max) ? abs_val : temp_max;
    }
    maximum = temp_max;
}
