#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern double *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_a = a;
    unsigned int local_b = b;
    double offset = 2147483648.0;
    for (; size > 0; size--, p++) {
        local_a = (local_a + (unsigned int)(*p * offset + offset)) % 65521;
        local_b = (local_b + local_a) % 65521;
    }
    a = local_a;
    b = local_b;
}
