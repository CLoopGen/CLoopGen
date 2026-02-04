#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *streamBuffer;
extern int begin_bytepos;
extern int end_bytepos;
extern int i;
extern byte *NAL_Payload_buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) - processes every second element forward, then second pass for odd indices
    int stride = 2;
    for (i = begin_bytepos; i < end_bytepos; i += stride)
        NAL_Payload_buffer[i] = streamBuffer[i];
    for (i = begin_bytepos + 1; i < end_bytepos; i += stride)
        NAL_Payload_buffer[i] = streamBuffer[i];
}
