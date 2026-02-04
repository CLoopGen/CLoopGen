#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

byte *streamBuffer;
int begin_bytepos;
int end_bytepos;
int i;
int j;
int count;
byte *NAL_Payload_buffer;

#define INPUT_SIZE (128 << 20) // 128 MB

void init_vars() {
    begin_bytepos = 0;
    end_bytepos = INPUT_SIZE;
    j = 0;
    count = 0;

    NAL_Payload_buffer = (byte *)malloc(INPUT_SIZE);
    if (!NAL_Payload_buffer) {
        fprintf(stderr, "Failed to allocate NAL_Payload_buffer\n");
        exit(1);
    }

    // Initialize with mostly zeros to trigger the condition occasionally
    memset(NAL_Payload_buffer, 0, INPUT_SIZE);

    // Scatter some non-zero values to prevent over-triggering the escape condition
    for (int idx = 3; idx < INPUT_SIZE; idx += 7) {
        NAL_Payload_buffer[idx] = 1;
    }

    // Allocate streamBuffer: worst-case size is about double (if every byte is escaped)
    streamBuffer = (byte *)malloc(INPUT_SIZE * 2);
    if (!streamBuffer) {
        fprintf(stderr, "Failed to allocate streamBuffer\n");
        exit(1);
    }
}