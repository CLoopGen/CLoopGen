#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and reduced trip count
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos += 2) {
        float index_scaled = (float)(pos * 3 + 5);
        moyo_sizes[pos] = index_scaled * 0.5f + 1.5f;
        moyo_values[pos] = index_scaled * index_scaled * 0.1f;
        if (pos + 1 < (19 + 1) * (19 + 1)) {
            moyo_sizes[pos + 1] = index_scaled * 0.25f;
            moyo_values[pos + 1] = -index_scaled * 0.1f;
        }
    }
}
