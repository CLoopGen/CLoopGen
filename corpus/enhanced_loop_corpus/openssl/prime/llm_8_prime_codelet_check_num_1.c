#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int j;
    for (i = 0; '0' <= s[i] && s[i] <= '9'; i++) {
        // Add extra arithmetic operations to increase computational intensity
        j = i * i + 2 * i + 1;  // Quadratic expression with multiple arithmetic ops
        j = (j >> 1) ^ i;       // Bit manipulation to further increase computation
    }
}
