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
    int local_j = j;
    int local_count = count;
    for (i = begin_bytepos; i < end_bytepos; i++) {
        byte val = NAL_Payload_buffer[i];
        if (local_count == 2 && !(val & 252)) {
            streamBuffer[local_j] = 3;
            local_j++;
            local_count = 0;
        }
        streamBuffer[local_j] = val;
        local_count = (val == 0) ? local_count + 1 : 0;
        local_j++;
    }
    j = local_j;
    count = local_count;
}
