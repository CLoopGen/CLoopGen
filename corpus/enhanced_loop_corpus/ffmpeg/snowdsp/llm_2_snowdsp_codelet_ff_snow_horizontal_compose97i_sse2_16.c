#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering and using sequential indices
    int idx = i & ~1; // Align to even index
    for (; (idx & 62) != 62; idx -= 2) {
        int half_idx = idx >> 1;
        b[idx]     = b[half_idx];
        b[idx + 1] = temp[half_idx];
    }
    i = idx; // Update original index if needed
}
