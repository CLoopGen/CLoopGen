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
    // Variant 1: Consecutive memory access with reversed indexing (forward fill)
    char *buf = &dbuf[start + 1];
    for (int i = 0, val = dlen; val && i < digits; ++i, val /= 10) {
        buf[i] = "0123456789"[val % 10];
    }
}
