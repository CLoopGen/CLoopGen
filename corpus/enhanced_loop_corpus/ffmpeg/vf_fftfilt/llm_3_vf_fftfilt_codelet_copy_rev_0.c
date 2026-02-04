#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *dest;
extern int w;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using a temporary buffer to batch reads and writes
    // Simulate reordering via local accumulation to modify access pattern
    int start = w;
    int count = (w2 - w) / 2;
    FFTSample temp[count];
    
    // First, read all required source values consecutively (reverse mapping)
    for (i = 0; i < count; i++) {
        temp[i] = dest[2 * w - (start + i) - 1];
    }
    
    // Then write them consecutively to destination
    for (i = 0; i < count; i++) {
        dest[start + i] = temp[i];
    }
}
