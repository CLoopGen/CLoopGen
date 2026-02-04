#include <stdio.h>

#include <inttypes.h>

extern char *source;
extern size_t bytes;
extern long value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2 (process every other byte)
    // Traverse backwards with a stride of 2, handling alignment and bounds carefully.
    // Initialize value only on first valid access to maintain semantic similarity.
    value = 0;
    int start = ((int)bytes - 1) | 1; // Start at last odd index if possible
    for (i = start; i >= 0; i -= 2) {
        int is_highest_byte = (i == ((int)bytes - 1));
        value = value * 256 + (source[i] & (is_highest_byte ? 127 : 255));
    }
}
