#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern int32_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element access with pointer offset
    int32_t *end = p + size;
    for (; p < end; p++) {
        int32_t val = *p;
        a = (a + (unsigned int)(val + 2147483648U)) % 65521;
        b = (b + a) % 65521;
    }
}
