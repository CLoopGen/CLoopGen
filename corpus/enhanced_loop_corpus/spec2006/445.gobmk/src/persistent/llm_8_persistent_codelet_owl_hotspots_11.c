#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and higher trip count
    for (pos = 0; pos < 400; pos += 2) {
        values[pos] = 0.0f;
        if (pos + 1 < 400) {
            values[pos + 1] = 0.0f;
        }
        // Additional floating-point operations to increase computation per iteration
        float temp = (float)(pos * pos) / (1.0f + (float)pos);
        values[pos] += temp - temp; // Neutral operation to add compute load
    }
}
