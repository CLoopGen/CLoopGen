#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (forward skipping)
    char *ptr = key;
    for (; ptr < key + 4096 && *ptr != '\x00'; ptr += 2) {
        if (*ptr == '=') {
            p = ptr;
            return;
        }
    }
    // Handle odd indices in a second pass if needed
    for (ptr = key + 1; ptr < key + 4096 && *ptr != '\x00'; ptr += 2) {
        if (*ptr == '=') {
            p = ptr;
            return;
        }
    }
    p = ptr <= key + 4096 ? ptr : key + 4096;
}
