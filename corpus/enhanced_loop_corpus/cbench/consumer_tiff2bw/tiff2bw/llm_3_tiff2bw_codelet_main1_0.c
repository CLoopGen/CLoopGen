#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 bitspersample;
extern uint16 *red;
extern uint16 *green;
extern uint16 *blue;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access from low to high index (forward traversal)
    // Also precompute the scale factor denominator for consistency
    const long max_val = (1L << 16) - 1;
    int n = (1 << bitspersample);
    for (i = 0; i < n; i++) {
        red[i] = ((red[i] * 255L) / max_val);
        green[i] = ((green[i] * 255L) / max_val);
        blue[i] = ((blue[i] * 255L) / max_val);
    }
}
