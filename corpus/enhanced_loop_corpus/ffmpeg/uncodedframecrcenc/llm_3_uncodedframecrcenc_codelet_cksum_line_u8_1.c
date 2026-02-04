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
    // Variant 2: Consecutive double-element access (process two elements per iteration)
    uint8_t *end = p + size;
    for (; p + 1 < end; p += 2) {
        a = (a + (unsigned int)(*p)) % 65521;
        b = (b + a) % 65521;
        a = (a + (unsigned int)(*(p + 1))) % 65521;
        b = (b + a) % 65521;
    }
    // Handle remaining element if size is odd
    if (p < end) {
        a = (a + (unsigned int)(*p)) % 65521;
        b = (b + a) % 65521;
    }
    size = (end - p); // Update size to reflect processed count if needed externally
}
