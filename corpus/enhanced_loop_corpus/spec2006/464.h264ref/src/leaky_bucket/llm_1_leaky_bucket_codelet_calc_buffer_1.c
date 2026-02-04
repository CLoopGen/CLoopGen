#include <stdio.h>

#include <inttypes.h>

extern long Bit_Buffer[10000];
extern unsigned long total_frame_buffer;
extern unsigned long TotalRate;
extern unsigned long iFrame;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (total_frame_buffer > 0) {
        iFrame = 0;
        for (unsigned long stride = total_frame_buffer; stride > 0; stride >>= 1) {
            if (iFrame < total_frame_buffer) {
                TotalRate += (unsigned long)Bit_Buffer[iFrame];
                iFrame++;
            }
        }
    }
}
