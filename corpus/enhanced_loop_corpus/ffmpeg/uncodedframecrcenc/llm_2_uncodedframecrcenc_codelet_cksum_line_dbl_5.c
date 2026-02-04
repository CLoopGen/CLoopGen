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
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element of the array pointed to by p
    // It adjusts the loop bound accordingly to prevent out-of-bounds access
    unsigned int i;
    double *p_local = p;
    for (i = 0; i < size / 2; i++, p_local += 2) {
        a = (a + (unsigned int)(*p_local * 2147483648U + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
    // Handle remaining element if size is odd
    if (size % 2 == 1) {
        a = (a + (unsigned int)(*p_local * 2147483648U + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
