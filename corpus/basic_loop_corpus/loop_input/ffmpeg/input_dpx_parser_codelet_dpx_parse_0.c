#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct DPXParseContext {
    ParseContext pc;
    uint32_t index;
    uint32_t fsize;
    uint32_t remaining_size;
    int is_be;
} DPXParseContext;

uint8_t *buf;
int buf_size;
DPXParseContext *d;
uint32_t state;
int i;

static uint8_t local_buf[134217728]; // 128MB buffer
static DPXParseContext local_d;

void init_vars() {
    buf_size = 134217728; // 128MB
    buf = local_buf;
    
    d = &local_d;
    d->pc.buffer = NULL;
    d->pc.index = 0;
    d->pc.last_index = 0;
    d->pc.buffer_size = 0;
    d->pc.state = 0;
    d->pc.frame_start_found = 0;
    d->pc.overread = 0;
    d->pc.overread_index = 0;
    d->pc.state64 = 0;
    d->index = 0;
    d->fsize = 0;
    d->remaining_size = 0;
    d->is_be = 0;

    state = 0;
    i = 0;

    // Place the signature near the end to ensure loop runs long enough (~0.01s)
    int pos = buf_size - 8;
    uint32_t sig_le = ('S') | (('D') << 8) | (('P') << 16) | ((unsigned int)('X') << 24);
    memcpy(&local_buf[pos], &sig_le, 4);
}