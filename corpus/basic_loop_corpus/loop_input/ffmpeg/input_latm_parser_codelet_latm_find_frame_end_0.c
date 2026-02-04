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

typedef struct LATMParseContext {
    ParseContext pc;
    int count;
} LATMParseContext;

uint8_t *buf;
int buf_size;
LATMParseContext *s;
int pic_found;
int i;
uint32_t state;

static uint8_t internal_buf[1 << 20]; // 1MB buffer
static LATMParseContext internal_s;

void init_vars() {
    buf = internal_buf;
    buf_size = sizeof(internal_buf);
    s = &internal_s;
    pic_found = 0;
    i = 0;
    state = 0;

    // Initialize other fields of s->pc if needed; minimal initialization for correctness
    s->pc.buffer = NULL;
    s->pc.index = 0;
    s->pc.last_index = 0;
    s->pc.buffer_size = 0;
    s->pc.state = 0;
    s->pc.frame_start_found = 0;
    s->pc.overread = 0;
    s->pc.overread_index = 0;
    s->pc.state64 = 0;
    s->count = 0;
}