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
    int local_count = 0;
    byte current_byte;
    for (i = begin_bytepos; i < end_bytepos; i++) {
        current_byte = NAL_Payload_buffer[i];
        streamBuffer[j++] = current_byte;
        if (current_byte == 0) {
            local_count++;
            if (local_count == 2 && !(current_byte & 252)) {
                streamBuffer[j++] = 3;
                local_count = 0;
            }
        } else {
            local_count = 0;
        }
    }
    count = local_count;
    j = j;
}
