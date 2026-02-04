#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

Bitstream *dest;
Bitstream *source;
int j;
unsigned char mask;
int bits_in_last_byte;

#define DATA_SIZE (16 << 20)  // 16 MB for ~0.01 sec runtime estimate

static byte *source_stream_buffer;
static byte *dest_stream_buffer;
static Bitstream source_impl;
static Bitstream dest_impl;

void init_vars() {
    source_stream_buffer = (byte *)calloc(DATA_SIZE, sizeof(byte));
    dest_stream_buffer = (byte *)calloc(DATA_SIZE, sizeof(byte));

    if (!source_stream_buffer || !dest_stream_buffer) {
        exit(1);
    }

    memset(&source_impl, 0, sizeof(Bitstream));
    memset(&dest_impl, 0, sizeof(Bitstream));

    source_impl.streamBuffer = source_stream_buffer;
    source_impl.byte_pos = 0;
    source_impl.bits_to_go = 8;
    source_impl.byte_buf = 0xAA;  // Arbitrary test pattern
    source = &source_impl;

    dest_impl.streamBuffer = dest_stream_buffer;
    dest_impl.byte_pos = 0;
    dest_impl.bits_to_go = 8;
    dest_impl.byte_buf = 0;
    dest = &dest_impl;

    j = 0;
    mask = 0x80;  // Start with high bit
    bits_in_last_byte = 8;  // Default to full byte
}