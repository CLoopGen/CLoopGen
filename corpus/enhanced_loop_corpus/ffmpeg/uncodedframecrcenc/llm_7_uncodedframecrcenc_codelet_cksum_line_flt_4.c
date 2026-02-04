#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern float *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_a = a;
    unsigned int local_b = b;
    for (; size > 0; size--, p++) {
        float adjusted_val = *p * 2147483648U + 2147483648U;
        local_a = (local_a + (unsigned int)adjusted_val) % 65521;
        local_b = (local_b + local_a) % 65521;
    }
    a = local_a;
    b = local_b;
}
