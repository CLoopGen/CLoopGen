#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and minimal operations
    for (pos = 0; pos < (19 + 1) * (19 + 1) + 10; pos++) {
        moyo_sizes[pos % 400] = 0.0f;
        moyo_values[pos % 400] = 0.0f;
    }
}
