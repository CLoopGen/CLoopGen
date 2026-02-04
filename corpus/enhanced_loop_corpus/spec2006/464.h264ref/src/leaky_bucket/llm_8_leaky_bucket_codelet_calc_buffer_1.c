#include <stdio.h>

#include <inttypes.h>

extern long Bit_Buffer[10000];
extern unsigned long total_frame_buffer;
extern unsigned long TotalRate;
extern unsigned long iFrame;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (iFrame = 0; iFrame < total_frame_buffer; iFrame += 2) {
        if (iFrame + 1 < total_frame_buffer) {
            TotalRate += (unsigned long)(Bit_Buffer[iFrame] + Bit_Buffer[iFrame + 1]);
        } else {
            TotalRate += (unsigned long)Bit_Buffer[iFrame];
        }
    }
}
