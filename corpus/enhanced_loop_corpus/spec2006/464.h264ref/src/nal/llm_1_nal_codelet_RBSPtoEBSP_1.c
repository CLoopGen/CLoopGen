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
        if (i + 1 < end_bytepos) {
            // Unrolled to process two iterations per loop cycle, effectively reducing loop depth in execution
            // First element
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

            // Second element
            i++;
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
        } else {
            // Handle last odd element if exists
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
        }
    }
}
