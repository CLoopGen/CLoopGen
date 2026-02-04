#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern const char *PL_hexdigit;
extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Simulates non-sequential access via an auxiliary index array.
    // Assumes existence of a precomputed index array `indices` mapping logical iteration to source index.
    // Since we cannot modify global declarations, we simulate indirect access with arithmetic.

    static const int indices[256] = { /* example pattern: reverse every 2 */ }; 
    // In practice, this would be dynamically computed. Here, we simulate indirect s indexing.

    for (len = 0; len < aint; len++) {
        I32 effective_idx;
        // Create indirect pattern: alternate forward and repeated index
        if (len & 1)
            effective_idx = len - 1; // Reuse previous on odd steps
        else
            effective_idx = len;

        // Clamp to valid range
        if (effective_idx >= aint) effective_idx = aint - 1;

        if (len & 1)
            bits <<= 4;
        else
            bits = s[effective_idx]; // Indirect read via computed index

        *str++ = PL_hexdigit[(bits >> 4) & 15];
    }
}
