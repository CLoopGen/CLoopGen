#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate indirect access by accessing elements in reverse order (i.e., indirect pattern)
    for (i = 1; i < len; i++) {
        int32 idx = len - 1 - i;  // Reverse indexing as indirect access pattern
        if (idx >= 0 && idx < len && val[idx] < val[bi])
            bi = idx;
    }
}
