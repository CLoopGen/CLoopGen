#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern  char *src;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive dual-element write per iteration (unrolled-like pattern)
    for (; size > 2 && src[0] && src[1]; size -= 2, l += 2) {
        *dst++ = *src++;
        *dst++ = *src++;
    }
}
