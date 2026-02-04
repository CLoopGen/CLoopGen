#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (int i = start; i < end; i += 2) {
        moyo_sizes[i] = 0.;
        moyo_values[i] = 0.;
        if (i + 1 < end) {
            moyo_sizes[i + 1] = 0.;
            moyo_values[i + 1] = 0.;
        }
    }
    pos = start; // ensure pos is set appropriately post-loop
}
