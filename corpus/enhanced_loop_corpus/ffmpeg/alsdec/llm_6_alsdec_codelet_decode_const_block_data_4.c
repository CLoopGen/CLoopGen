#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int smp;
extern int32_t val;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp = val;
    for (; smp; smp--) {
        *dst++ = temp;
        temp = temp + 1; // Introduce WAW and RAW dependency: each iteration depends on previous write to temp
    }
}
