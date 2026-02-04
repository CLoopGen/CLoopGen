#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern uint8_t *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    for (; size > 0; size -= 2, p += 2) {
        if (size >= 1) {
            a = (a + (unsigned int)(*p)) % 65521;
            b = (b + a) % 65521;
        }
        if (size > 1) {
            a = (a + (unsigned int)(*(p + 1))) % 65521;
            b = (b + a) % 65521;
        }
    }
}
