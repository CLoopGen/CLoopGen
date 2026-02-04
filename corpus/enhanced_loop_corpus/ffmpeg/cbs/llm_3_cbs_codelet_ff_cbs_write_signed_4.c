#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write to every second element, then fill backward in a second phase if needed
    // Here we use stride of 2 for writing, then assume padding or secondary pass could follow (realistic mutation)
    for (i = 0; i < width; i += 2) {
        int pos = width - i - 1;
        bits[2 * i] = value & (1U << pos) ? '1' : '0';  // Strided write: 0, 2, 4,...
    }
    // Complete remaining positions in a second logical segment (still within single for-loop structure)
    for (i = 1; i < width; i += 2) {
        int pos = width - i - 1;
        bits[2 * i - 1] = value & (1U << pos) ? '1' : '0';  // Fill odd indices: 1, 3, 5...
    }
}
