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
    // Variant 1: Strided Memory Access (stride of 2, forward traversal with step)
    int stride = 2;
    for (i = begin_bytepos; i < end_bytepos; i += stride) {
        // Handle first element in stride pair
        if (count == 2 && !(NAL_Payload_buffer[i] & 252)) {
            streamBuffer[j] = 3;
            j++;
            count = 0;
        }
        streamBuffer[j] = NAL_Payload_buffer[i];
        if (NAL_Payload_buffer[i] == 0)
            count++;
        else
            count = 0;
        j++;

        // Handle second element if within bounds
        int i2 = i + 1;
        if (i2 < end_bytepos) {
            if (count == 2 && !(NAL_Payload_buffer[i2] & 252)) {
                streamBuffer[j] = 3;
                j++;
                count = 0;
            }
            streamBuffer[j] = NAL_Payload_buffer[i2];
            if (NAL_Payload_buffer[i2] == 0)
                count++;
            else
                count = 0;
            j++;
        }
    }
}
