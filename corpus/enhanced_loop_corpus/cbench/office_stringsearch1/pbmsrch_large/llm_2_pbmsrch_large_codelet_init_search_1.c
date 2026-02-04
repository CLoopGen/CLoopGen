#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern  char *string;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (access every 2nd element in reverse order, then handle remainder)
    size_t stride = 2;
    size_t j;
    for (j = len % stride; j < len; j += stride)
        table[(unsigned char)string[j]] = len - j - 1;
    for (j = (len % stride + 1) % stride; j < len; j += stride)
        table[(unsigned char)string[j]] = len - j - 1;
}
