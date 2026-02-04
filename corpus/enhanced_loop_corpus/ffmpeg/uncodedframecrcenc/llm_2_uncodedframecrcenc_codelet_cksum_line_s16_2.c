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
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element in the array, reducing total iterations by half
    // but still processing within bounds as long as size is adjusted accordingly.
    for (; size > 0; size -= 2, p += 2) {
        if (size >= 1) {
            a = (a + (unsigned int)(*(p) + 32768)) % 65521;
            b = (b + a) % 65521;
        }
        if (size > 1) {
            a = (a + (unsigned int)(*(p + 1) + 32768)) % 65521;
            b = (b + a) % 65521;
        }
    }
}
