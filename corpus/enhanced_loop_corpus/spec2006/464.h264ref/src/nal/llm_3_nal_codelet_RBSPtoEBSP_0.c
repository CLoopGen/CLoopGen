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
    // Variant 2: Reverse consecutive memory access - traverses from end to beginning
    for (i = end_bytepos - 1; i >= begin_bytepos; i--)
        NAL_Payload_buffer[i] = streamBuffer[i];
}
