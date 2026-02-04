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
    for (unsigned int outer = 0; outer < (size + 3) / 4; outer++) {
        for (unsigned int inner = 0; inner < 4 && (outer * 4 + inner) < size; inner++) {
            unsigned int idx = outer * 4 + inner;
            a = (a + (unsigned int)(p[idx] * 2147483648U + 2147483648U)) % 65521;
            b = (b + a) % 65521;
        }
    }
}
