#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int smp;
extern int32_t val;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_val = val * 2 + 1;
    for (; smp > 0; smp -= 2) {
        *dst++ = temp_val;
        if (smp <= 1) break;
        *dst++ = temp_val ^ 0xFF;
    }
}
