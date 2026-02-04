#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ParseContext {
    uint8_t *buffer;
    int index;
    int last_index;
    unsigned int buffer_size;
    uint32_t state;
    int frame_start_found;
    int overread;
    int overread_index;
    uint64_t state64;
} ParseContext;

typedef struct MLPParseContext {
    ParseContext pc;
    int bytes_left;
    int in_sync;
    int num_substreams;
} MLPParseContext;

uint8_t *buf;
MLPParseContext *mp;
uint8_t parity_bits;
int i;
int p;

static uint8_t *internal_buf;
static MLPParseContext internal_mp;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16 MB for ~0.01 sec runtime estimate
    
    internal_buf = calloc(data_size, sizeof(uint8_t));
    if (!internal_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    buf = internal_buf;
    mp = &internal_mp;
    
    mp->num_substreams = 1000;
    mp->bytes_left = 0;
    mp->in_sync = 1;
    
    mp->pc.buffer = internal_buf;
    mp->pc.buffer_size = data_size;
    mp->pc.index = 0;
    mp->pc.last_index = 0;
    mp->pc.state = 0;
    mp->pc.frame_start_found = 1;
    mp->pc.overread = 0;
    mp->pc.overread_index = 0;
    mp->pc.state64 = 0;
    
    parity_bits = 0;
    i = 0;
    p = 0;
    
    for (size_t idx = 0; idx < data_size; idx++) {
        internal_buf[idx] = (uint8_t)(idx & 0xFF);
    }
}