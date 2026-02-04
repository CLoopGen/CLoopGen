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
    int step = 2;
    for (i = begin_bytepos; i < end_bytepos; i += step) {
        if (i + 1 < end_bytepos) {
            NAL_Payload_buffer[i] = streamBuffer[i];
            NAL_Payload_buffer[i + 1] = streamBuffer[i + 1];
        } else {
            NAL_Payload_buffer[i] = streamBuffer[i];
        }
    }
}
