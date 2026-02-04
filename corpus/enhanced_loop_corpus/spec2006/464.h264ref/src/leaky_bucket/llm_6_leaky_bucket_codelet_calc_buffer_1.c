#include <stdio.h>

#include <inttypes.h>

extern long Bit_Buffer[10000];
extern unsigned long total_frame_buffer;
extern unsigned long TotalRate;
extern unsigned long iFrame;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp_rate = 0;
    for (unsigned long i = 0; i < total_frame_buffer; i++) {
        temp_rate += (unsigned long)Bit_Buffer[i];
    }
    TotalRate += temp_rate;
}
