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
    int stride = 2;
    for (i = begin_bytepos; i < end_bytepos; i += stride) {
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
        if (i + 1 < end_bytepos) {
            streamBuffer[j] = NAL_Payload_buffer[i + 1];
            if (NAL_Payload_buffer[i + 1] == 0)
                count++;
            else
                count = 0;
            j++;
        }
    }
}
