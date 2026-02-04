#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

byte *streamBuffer;
int begin_bytepos;
int end_bytepos;
int i;
byte *NAL_Payload_buffer;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB for ~0.01 sec runtime on modern CPU

    streamBuffer = (byte *)aligned_alloc(32, data_size);
    NAL_Payload_buffer = (byte *)aligned_alloc(32, data_size);

    if (!streamBuffer || !NAL_Payload_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        streamBuffer[idx] = (byte)(idx & 0xFF);
    }

    begin_bytepos = 0;
    end_bytepos = (int)data_size;
}