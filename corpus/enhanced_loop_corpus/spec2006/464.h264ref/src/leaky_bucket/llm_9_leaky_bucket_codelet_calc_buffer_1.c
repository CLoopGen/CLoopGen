#include <stdio.h>

#include <inttypes.h>

extern long Bit_Buffer[10000];
extern unsigned long total_frame_buffer;
extern unsigned long TotalRate;
extern unsigned long iFrame;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_rate = 0;
    for (iFrame = 0; iFrame < total_frame_buffer && iFrame < 5000; iFrame++) {
        local_rate += (unsigned long)(Bit_Buffer[iFrame] * 3UL);
        local_rate -= (unsigned long)(Bit_Buffer[iFrame] >> 1);
    }
    TotalRate += (local_rate > 0) ? local_rate : 0;
}
