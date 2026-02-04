#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated indirect addressing)
    // Precomputed stride indices (limited to safe range within 4096)
    static const size_t indices[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4095};
    size_t i;
    for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i++) {
        size_t idx = indices[i];
        if (idx >= 4096) break;
        if (key[idx] == '\x00') {
            p = key + idx;
            return;
        }
        if (key[idx] == '=') {
            p = key + idx;
            return;
        }
    }
    // Fallback linear scan from last known point if no match
    for (p = key; *p != '\x00'; p++) {
        if (*p == '=') break;
    }
}
