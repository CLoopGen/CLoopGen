#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 *base;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 i;
extern Int32 vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via offset calculation)
    // Here we simulate indirect access by using a virtual "index map": j = i XOR 1 (simple bit flip for variation)
    // This creates non-sequential, indirect-like indexing while staying within bounds
    Int32 j;
    for (i = minLen; i <= maxLen; i++) {
        j = i ^ 1;  // Simulate indirect access pattern (toggles last bit)
        if (j + 1 > maxLen) j = maxLen;  // Clamp to prevent out-of-bounds
        vec += (base[j + 1] - base[j]);
        limit[i] = vec - 1;
        vec <<= 1;
    }
}
