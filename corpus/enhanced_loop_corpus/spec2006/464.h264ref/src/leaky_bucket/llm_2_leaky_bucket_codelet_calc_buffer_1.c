#include <stdio.h>

#include <inttypes.h>

extern long Bit_Buffer[10000];
extern unsigned long total_frame_buffer;
extern unsigned long TotalRate;
extern unsigned long iFrame;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (iFrame = 0; iFrame < total_frame_buffer; iFrame += 2) {
        TotalRate += (unsigned long)Bit_Buffer[iFrame];
    }
}
