#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dbuf[5152];
extern  int dlen;
extern int digits;
extern int start;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access (simulate stride of 2 by writing to every other position, within bounds)
    int stride = 2;
    int base = start + digits * stride;
    for (int i = digits, val = dlen; val && i > 0; --i, val /= 10) {
        dbuf[base - i * stride] = "0123456789"[val % 10];
    }
}
