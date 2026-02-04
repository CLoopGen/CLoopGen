#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (forward skipping)
    // This variant processes every second character, simulating a strided access pattern.
    // It still checks for null terminator and '=' but skips elements to demonstrate stride.
    char *base = key;
    ptrdiff_t i = 0;
    for (; base[i] != '\x00'; i += 2) {
        if (base[i] == '=') {
            p = &base[i];
            return;
        }
    }
    // If no '=' found, set p to first null (mimic original behavior)
    for (p = key; *p != '\x00'; p++);
}
