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
    int temp_count = count;
    for (i = begin_bytepos; i < end_bytepos; i++) {
        byte current_byte = NAL_Payload_buffer[i];
        if (temp_count == 2 && !(current_byte & 252)) {
            streamBuffer[j] = 3;
            j++;
            temp_count = 0;
        }
        streamBuffer[j] = current_byte;
        if (current_byte == 0)
            temp_count++;
        else
            temp_count = 0;
        j++;
    }
    count = temp_count;
}
