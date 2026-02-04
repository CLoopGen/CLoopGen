#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

typedef struct {
    int byte_pos;
    int bits_to_go;
    byte byte_buf;
    int stored_byte_pos;
    int stored_bits_to_go;
    byte stored_byte_buf;
    byte byte_buf_skip;
    int byte_pos_skip;
    int bits_to_go_skip;
    byte *streamBuffer;
    int write_flag;
} Bitstream;

extern Bitstream *dest;
extern Bitstream *source;
extern int j;
extern unsigned char mask;
extern int bits_in_last_byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of writing to streamBuffer one byte at a time, accumulate multiple bytes in a local array and write them consecutively.
    byte temp_buffer[8];
    int temp_index = 0;
    int local_bits_to_go = dest->bits_to_go;
    byte local_byte_buf = dest->byte_buf;
    int local_byte_pos = dest->byte_pos;

    for (j = 0; j < bits_in_last_byte; j++) {
        local_byte_buf <<= 1;
        if (source->byte_buf & mask)
            local_byte_buf |= 1;
        local_bits_to_go--;
        mask >>= 1;
        if (local_bits_to_go == 0) {
            temp_buffer[temp_index++] = local_byte_buf;
            local_bits_to_go = 8;
            local_byte_buf = 0;
        }
    }

    // Write accumulated bytes in consecutive fashion
    for (int k = 0; k < temp_index; k++) {
        dest->streamBuffer[local_byte_pos++] = temp_buffer[k];
    }

    dest->bits_to_go = local_bits_to_go;
    dest->byte_buf = local_byte_buf;
    dest->byte_pos = local_byte_pos;
}
