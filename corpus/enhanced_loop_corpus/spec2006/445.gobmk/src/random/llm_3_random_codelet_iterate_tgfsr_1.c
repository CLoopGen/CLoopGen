#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal
    // Process array from high to low index using consecutive backward access
    for (; i >= 0 && i < 25; i--) {
        int prev_idx = (i + m - 25 + 25) % 25; // Circular wrap-around indexing
        x[i] = x[prev_idx] ^ (x[i] >> 1) ^ ((x[i] & 1) ? a : 0);
        // Ensure loop progresses: start at 24 and go down to 0
        if (i == 0) break; // Prevent underflow after last iteration
    }
    // Reset i to 25 after loop completes, assuming original semantics expect i=25 at end
    i = 25;
}
