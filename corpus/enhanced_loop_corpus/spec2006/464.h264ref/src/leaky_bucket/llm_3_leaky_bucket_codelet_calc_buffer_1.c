#include <stdio.h>

#include <inttypes.h>

extern long Bit_Buffer[10000];
extern unsigned long total_frame_buffer;
extern unsigned long TotalRate;
extern unsigned long iFrame;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access
    for (iFrame = total_frame_buffer - 1; iFrame >= 0; iFrame--) {
        TotalRate += (unsigned long)Bit_Buffer[iFrame];
    }
}
