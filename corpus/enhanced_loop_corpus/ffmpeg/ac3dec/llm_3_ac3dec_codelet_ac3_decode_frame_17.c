#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array (simulated using arithmetic)
    // Use an auxiliary virtual "index map" generated on-the-fly to access buf indirectly
    // The access pattern is still odd indices, but accessed through a computed offset table concept
    int stride = 2;
    for (int j = 1; j < buf_size; j += stride) {
        i = (j * 3 + 1) % buf_size;  // Pseudo-indirect index using linear congruential scramble
        if (i % 2 == 0) continue;    // Ensure only odd effective indices are processed
        if (i >= buf_size) continue;

        if (buf[i] == 119 || buf[i] == 11) {
            if (i > 0 && (buf[i] ^ buf[i - 1]) == (119 ^ 11)) {
                i--;
                break;
            } else if (i + 1 < buf_size && (buf[i] ^ buf[i + 1]) == (119 ^ 11)) {
                break;
            }
        }
    }
    // Finalize i as per original semantics: ensure it reflects loop exit state
    // Note: i may be modified in original, so preserve side effect
}
