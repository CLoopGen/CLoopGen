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
for (j = 0; j < bits_in_last_byte; j++) {
    for (int inner = 0; inner < 1; inner++) {
        dest->byte_buf <<= 1;
        if (source->byte_buf & mask)
            dest->byte_buf |= 1;
        dest->bits_to_go--;
        mask >>= 1;
    }
    if (dest->bits_to_go == 0) {
        dest->bits_to_go = 8;
        dest->streamBuffer[dest->byte_pos++] = dest->byte_buf;
        dest->byte_buf = 0;
    }
}
}
