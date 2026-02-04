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
    for (unsigned int i = 0; i < size; i++) {
        a = (a + (unsigned int)(p[i] * 2147483648U + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
