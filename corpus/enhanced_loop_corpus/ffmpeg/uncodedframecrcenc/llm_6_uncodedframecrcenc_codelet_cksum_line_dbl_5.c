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
    unsigned int temp_a;
    for (; size > 0; size--, p++) {
        temp_a = (a + (unsigned int)(*p * 2147483648U + 2147483648U)) % 65521;
        b = (b + temp_a) % 65521;
        a = temp_a;
    }
}
