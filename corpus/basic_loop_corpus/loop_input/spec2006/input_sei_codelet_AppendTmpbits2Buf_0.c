#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
int i;
int j;
unsigned char mask;

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime

static byte *source_buffer;
static byte *dest_buffer;
static Bitstream source_bs;
static Bitstream dest_bs;

void init_vars() {
    // Allocate buffers
    source_buffer = (byte*)calloc(DATA_SIZE, sizeof(byte));
    dest_buffer = (byte*)calloc(DATA_SIZE * 2, sizeof(byte)); // Larger to accommodate bit expansion
    
    if (!source_buffer || !dest_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize source data with non-trivial pattern
    for (int k = 0; k < DATA_SIZE; k++) {
        source_buffer[k] = (byte)(k ^ (k >> 8) ^ 0xAA);
    }
    
    // Initialize source bitstream
    memset(&source_bs, 0, sizeof(Bitstream));
    source_bs.byte_pos = DATA_SIZE;
    source_bs.bits_to_go = 8;
    source_bs.byte_buf = 0;
    source_bs.streamBuffer = source_buffer;
    source_bs.write_flag = 1;
    
    // Initialize dest bitstream
    memset(&dest_bs, 0, sizeof(Bitstream));
    dest_bs.byte_pos = 0;
    dest_bs.bits_to_go = 8;
    dest_bs.byte_buf = 0;
    dest_bs.streamBuffer = dest_buffer;
    dest_bs.write_flag = 1;
    
    // Set external pointers
    source = &source_bs;
    dest = &dest_bs;
    
    // Initialize loop variables
    i = 0;
    j = 0;
    mask = 0;
}