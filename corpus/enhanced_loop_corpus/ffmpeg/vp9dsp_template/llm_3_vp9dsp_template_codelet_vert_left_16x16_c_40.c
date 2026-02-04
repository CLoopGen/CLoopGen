#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[15];
extern uint8_t vo[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with offset input window
    // Input is accessed consecutively but shifted by a fixed offset (simulating sliding window over top)
    // Outputs are written to contiguous locations in ve[] and vo[]
    size_t offset = 4; // arbitrary offset to change access base
    for (i = 0; i < 16 - 2; i++) {
        size_t idx = offset + i;
        ve[i] = (top[idx] + top[idx + 1] + 1) >> 1;
        vo[i] = (top[idx] + top[idx + 1] * 2 + top[idx + 2] + 2) >> 2;
    }
}
