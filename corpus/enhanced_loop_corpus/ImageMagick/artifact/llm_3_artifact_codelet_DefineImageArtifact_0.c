#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index remapping table (simulated with simple arithmetic)
    // Instead of direct sequential access, we use an indirect pattern: accessing indices in scrambled order
    // Here we simulate indirect access by using a virtual "remap" where index j maps to (j*3) % 128, assuming bounded key region
    // We limit search to first 128 bytes to avoid out-of-bounds and ensure termination
    const int N = 128;
    for (int j = 0; j < N; j++) {
        ptrdiff_t idx = (j * 3) % N;  // Simulate non-consecutive, indirect access pattern
        if (key[idx] == '\x00') {
            p = &key[idx];
            return;
        }
        if (key[idx] == '=') {
            p = &key[idx];
            return;
        }
    }
    // Fallback: point to end if not found
    p = key + N;
}
