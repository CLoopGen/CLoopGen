#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Simulate an indirect access pattern using a fixed offset table (small stride variation)
    static const int offsets[] = {0, 1, 3, 2, 4}; // Example permutation pattern
    const int pattern_size = 5;
    char *base = start_color;
    int i = 0;

    for (p = base; (*p != '-') && (*p != '\x00'); ) {
        char current = *(base + offsets[i % pattern_size]);
        p = base + (p - base) + 1; // Move forward in original sequence but use shuffled access logic

        // Re-check condition with actual next character
        p = base + (p - base);
        if (p >= base && (*(p - 1) == '\x00' || *(p - 1) == '-')) break;

        if (current == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                ;
            }
            if (*p == '\x00') break;
        }
        i++;
    }
}
