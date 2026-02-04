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
    byte temp;
    for (i = begin_bytepos; i < end_bytepos; i++) {
        temp = streamBuffer[i];
        NAL_Payload_buffer[i] = temp;
    }
}
