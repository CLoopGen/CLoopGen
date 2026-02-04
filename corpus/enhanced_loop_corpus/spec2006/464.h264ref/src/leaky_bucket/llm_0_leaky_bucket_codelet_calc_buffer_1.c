#include <stdio.h>

#include <inttypes.h>

extern long Bit_Buffer[10000];
extern unsigned long total_frame_buffer;
extern unsigned long TotalRate;
extern unsigned long iFrame;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned long outer = 0; outer < total_frame_buffer; outer += 100) {
        for (iFrame = outer; iFrame < total_frame_buffer && iFrame < outer + 100; iFrame++) {
            TotalRate += (unsigned long)Bit_Buffer[iFrame];
        }
    }
}
