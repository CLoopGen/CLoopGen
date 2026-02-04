#include <stdio.h>

#include <inttypes.h>

extern char *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled check (simulating wider access pattern)
    const char *whitespace = " \t\n\r\f";
    while (*w) {
        int found = 0;
        for (int i = 0; i < 5; ++i) {
            if (*w == whitespace[i]) {
                found = 1;
                break;
            }
        }
        if (!found) break;
        w++;
    }
}
