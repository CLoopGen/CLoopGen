#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate an indirect access pattern by accessing elements in reverse order
    for (i = 1; i < len; i++) {
        int32 idx = len - 1 - i;  // Reverse indexing
        if (val[idx] > val[bi])
            bi = idx;
    }
}
