#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access
    for (n = 49; n >= 0; n--) {
        t[n] = (n == 0) ? 1.23 : 0.;
    }
}
