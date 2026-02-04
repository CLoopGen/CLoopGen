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
extern int i;
extern int j;
extern unsigned char mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < source->byte_pos; i++) {
        mask = 128;
        for (j = 0; j < 8; j++) {
            dest->byte_buf <<= 1;
            if (source->streamBuffer[i] & mask) {
                dest->byte_buf |= 1;
            }
            dest->bits_to_go--;
            mask >>= 1;
            for (; dest->bits_to_go == 0;) {
                dest->bits_to_go = 8;
                dest->streamBuffer[dest->byte_pos++] = dest->byte_buf;
                dest->byte_buf = 0;
            }
        }
    }
}
