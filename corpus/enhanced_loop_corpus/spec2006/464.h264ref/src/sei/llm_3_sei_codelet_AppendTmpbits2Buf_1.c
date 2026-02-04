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
    // Variant 2: Strided memory access
    // Instead of sequential byte position increment, write every other byte (stride of 2),
    // simulating a pattern where output is interleaved or reserved for alignment.
    int stride = 2; // Write every second position
    int buffer_limit = dest->byte_pos + (bits_in_last_byte + 7) / 8 * stride;
    int local_bits_to_go = dest->bits_to_go;
    byte local_byte_buf = dest->byte_buf;
    int temp_pos = dest->byte_pos;

    for (j = 0; j < bits_in_last_byte; j++) {
        local_byte_buf <<= 1;
        if (source->byte_buf & mask)
            local_byte_buf |= 1;
        local_bits_to_go--;
        mask >>= 1;
        if (local_bits_to_go == 0) {
            // Write with strided access
            if (temp_pos + stride <= buffer_limit) {
                dest->streamBuffer[temp_pos] = local_byte_buf;
                temp_pos += stride; // Stride instead of ++ 
            }
            local_bits_to_go = 8;
            local_byte_buf = 0;
        }
    }

    // Update global state
    dest->bits_to_go = local_bits_to_go;
    dest->byte_buf = local_byte_buf;
    dest->byte_pos = temp_pos;
}
