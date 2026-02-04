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
    int offset = begin_bytepos;
    int length = end_bytepos - begin_bytepos;
    for (i = 0; i < length; i++) {
        byte temp = streamBuffer[offset + i];
        NAL_Payload_buffer[offset + i] = temp ^ 0xFF; // bitwise complement applied
    }
}
