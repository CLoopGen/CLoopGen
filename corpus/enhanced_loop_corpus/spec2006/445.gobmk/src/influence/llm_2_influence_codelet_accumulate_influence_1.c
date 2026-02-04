#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential access, write to every 2nd element first, then fill gaps
    int size = (19 + 1) * (19 + 1);
    for (int stride = 1; stride <= 2; stride++) {
        for (ii = 0; ii < size; ii += 2) {
            int index = ii + (stride == 2 ? 1 : 0);
            if (index < size) {
                working[index] = 0;
            }
        }
    }
}
