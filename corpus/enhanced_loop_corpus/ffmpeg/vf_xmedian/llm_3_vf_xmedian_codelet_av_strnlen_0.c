#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Simulate indirect access by using an auxiliary index array conceptually, but avoid extra storage
    // Instead, emulate irregular access pattern with alternating offset jumps
    size_t indices[2] = {0, 1}; // Example pattern buffer for alternating access
    size_t phase = 0;
    i = 0;
    for (; i < len;) {
        size_t idx = i + indices[phase]; // synthesized indirect-like access
        if (idx >= len || !s[idx]) break;
        i = idx + 1; // update loop progress
        phase = (phase + 1) % 2; // alternate stride pattern
    }
    // Finalize i to match original semantics: first index where s[i] is null or out of bounds
    for (i = 0; i < len && s[i]; i++);
}
