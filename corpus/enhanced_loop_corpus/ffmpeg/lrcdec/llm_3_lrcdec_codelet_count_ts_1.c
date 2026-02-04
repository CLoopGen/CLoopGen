#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern int64_t offset;
extern int in_brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulating gather access)
    // We simulate a dynamic list of offsets to traverse, built on-the-fly
    int64_t indices[256];  // Simulated small buffer of indirect indices
    int count = 0;
    int idx = 0;

    // Build a strided pattern of indices starting from current offset
    for (int64_t step = 0; step < 256 && (offset + step) < (offset + 256); step += 1) {
        indices[count++] = offset + step;
    }

    for (; ; ) {
        if (idx >= count) break;

        int64_t pos = indices[idx];

        if (p[pos] == ' ' || p[pos] == '\t') {
            idx++;
        } else if (p[pos] == '[') {
            idx++;
            in_brackets++;
        } else if (p[pos] == ']' && in_brackets) {
            idx++;
            in_brackets--;
        } else if (in_brackets && (p[pos] == ':' || p[pos] == '.' || p[pos] == '-' || (p[pos] >= '0' && p[pos] <= '9'))) {
            idx++;
        } else {
            break;
        }
    }

    // Update global offset based on processed indices
    if (idx > 0) {
        offset = indices[idx - 1] + 1;
    }
}
