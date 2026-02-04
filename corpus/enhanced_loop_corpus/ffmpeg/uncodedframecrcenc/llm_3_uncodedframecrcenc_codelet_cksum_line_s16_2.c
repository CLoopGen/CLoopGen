#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern int16_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive dual-element prefetch style access
    // Processes two elements per iteration in consecutive order, unrolling the loop manually
    // to modify access pattern and improve spatial locality.
    while (size >= 2) {
        a = (a + (unsigned int)(*p + 32768)) % 65521;
        b = (b + a) % 65521;
        p++;
        a = (a + (unsigned int)(*p + 32768)) % 65521;
        b = (b + a) % 65521;
        p++;
        size -= 2;
    }
    // Handle remaining element if size is odd
    if (size == 1) {
        a = (a + (unsigned int)(*p + 32768)) % 65521;
        b = (b + a) % 65521;
        p++;
        size--;
    }
}
