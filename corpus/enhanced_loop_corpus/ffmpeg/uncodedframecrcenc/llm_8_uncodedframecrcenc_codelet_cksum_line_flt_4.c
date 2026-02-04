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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled operations
    // Unroll by 2x and add extra floating-point operations to increase computation per iteration
    for (; size >= 2; size -= 2, p += 2) {
        float val1 = *p;
        float val2 = *(p + 1);
        
        a = (a + (unsigned int)((val1 * 2147483648U + 2147483648U) * 1.5f)) % 65521;
        b = (b + a) % 65521;

        a = (a + (unsigned int)((val2 * 2147483648U + 2147483648U) * 1.5f)) % 65521;
        b = (b + a) % 65521;
    }
    
    // Handle remaining element if size was odd
    if (size == 1) {
        a = (a + (unsigned int)(*p * 2147483648U + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
