#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *streamBuffer;
extern int begin_bytepos;
extern int end_bytepos;
extern int i;
extern int j;
extern int count;
extern byte *NAL_Payload_buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = begin_bytepos; i < end_bytepos; i++) {
    byte current = NAL_Payload_buffer[i];
    int skip_normal_write = 0;

    if (count == 2 && !(current & 252)) {
        streamBuffer[j++] = 3;
        count = 0;
        skip_normal_write = 1;
    }

    streamBuffer[j] = current;
    if (current == 0)
        count++;
    else
        count = 0;

    j++;

    if (skip_normal_write) {
        continue;
    }
}
}
