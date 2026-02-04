#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access by precomputing sequential indices (to avoid malloc)
    size_t idx[512]; // Assuming maximum length is bounded for stack safety
    size_t n = (len < 512) ? len : 512;

    // Initialize indirect index mapping (identity map for simplicity, but enables pattern changes)
    for (size_t j = 0; j < n; j++) {
        idx[j] = j;
    }

    // Traverse using indirect addressing
    for (i = 0; i < n; i++) {
        size_t pos = idx[i]; // Indirect access via index array
        if (pos >= len || !s[pos]) {
            break;
        }
    }
    // Final i corresponds to number of valid accesses; adjust if needed
    // Note: i here is index into idx[], so it reflects count of iterations
}
