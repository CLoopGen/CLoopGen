#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int smp;
extern int32_t val;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_smp = smp;
    for (; temp_smp > 0; temp_smp--)
        if (val != 0)
            *dst++ = val;
}
