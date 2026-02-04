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
    for (unsigned int i = 0; i < size * 3; i++) {
        unsigned int idx = i / 3;
        double val = p[idx];
        a = (a + (unsigned int)(val * 2147483648U + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
