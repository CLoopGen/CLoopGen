#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int len;
extern int i;
extern int32_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int32_t temp_max = max;
    for (i = 0; i < len + 4; i++) {
        int32_t val = in[i];
        int32_t abs_val = (val >= 0) ? val : -val;
        temp_max |= abs_val;
    }
    max = temp_max;
}
