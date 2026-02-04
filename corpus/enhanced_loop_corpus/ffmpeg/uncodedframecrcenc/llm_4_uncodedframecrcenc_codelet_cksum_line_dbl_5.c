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
    for (; size > 0; size--, p++) {
        double val = *p;
        if (val < 0.0) continue;
        a = (a + (unsigned int)(val * 2147483648U + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
