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
    // Variant 1: Strided memory access with stride of 2
    for (; size > 0; size -= 2, p += 2) {
        if (size >= 1) {
            a = (a + (unsigned int)(*p * 2147483648U + 2147483648U)) % 65521;
            b = (b + a) % 65521;
        }
        if (size > 1) {
            a = (a + (unsigned int)(*(p+1) * 2147483648U + 2147483648U)) % 65521;
            b = (b + a) % 65521;
        }
    }
}
