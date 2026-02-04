#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int smp;
extern int32_t val;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < smp; i += (val == 0 ? smp : 1))
        *dst++ = val;
}
