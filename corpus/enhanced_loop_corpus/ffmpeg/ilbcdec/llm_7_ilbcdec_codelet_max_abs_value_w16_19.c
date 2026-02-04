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
    int local_max = 0;
    int stride = 2;
    for (i = 0; i < length; i += stride) {
        int16_t val1 = vector[i];
        int16_t abs1 = (val1 >= 0) ? val1 : -val1;
        local_max = (abs1 > local_max) ? abs1 : local_max;

        if (i + 1 < length) {
            int16_t val2 = vector[i + 1];
            int16_t abs2 = (val2 >= 0) ? val2 : -val2;
            local_max = (abs2 > local_max) ? abs2 : local_max;
        }
    }
    if (local_max > maximum) {
        maximum = local_max;
    }
}
