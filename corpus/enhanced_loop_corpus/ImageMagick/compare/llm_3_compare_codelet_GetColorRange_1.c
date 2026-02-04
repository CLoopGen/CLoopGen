#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulating gather-style access)
    // We precompute valid indices in a small buffer (stack-allocated, fixed size for safety)
    // and traverse the string indirectly through these indices.
    uint16_t indices[512]; // Simulate indirect access indices
    int count = 0;
    char *temp = start_color;

    // Build list of valid access positions (limited to prevent overflow)
    while (temp - start_color < 4096 && count < 511) {
        ptrdiff_t offset = temp - start_color;
        indices[count++] = (uint16_t)offset;
        if (*temp == '\x00' || *temp == '-') break;
        temp++;
    }

    // Now iterate using indirect addressing through indices
    for (int i = 0; i < count; i++) {
        p = start_color + indices[i];
        if (*p == '\x00' || *p == '-') break;
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00') break;
        }
    }
}
