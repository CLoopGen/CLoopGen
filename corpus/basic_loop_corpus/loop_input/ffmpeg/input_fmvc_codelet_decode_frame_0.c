#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct PutByteContext {
    uint8_t *buffer;
    uint8_t *buffer_end;
    uint8_t *buffer_start;
    int eof;
} PutByteContext;

typedef struct InterBlock {
    int w;
    int h;
    int size;
    int xor;
} InterBlock;

typedef struct FMVCContext {
    GetByteContext gb;
    PutByteContext pb;
    uint8_t *buffer;
    size_t buffer_size;
    uint8_t *pbuffer;
    size_t pbuffer_size;
    ptrdiff_t stride;
    int bpp;
    int yb;
    int xb;
    InterBlock *blocks;
    unsigned int nb_blocks;
} FMVCContext;

FMVCContext *s;
unsigned int block;

static uint8_t global_buffer[16777216]; // 16MB
static uint8_t global_pbuffer[16777216]; // 16MB
static InterBlock *global_blocks;

void init_vars() {
    global_blocks = calloc(65536, sizeof(InterBlock));
    if (!global_blocks) exit(1);

    s = malloc(sizeof(FMVCContext));
    if (!s) exit(1);

    s->gb.buffer = global_buffer;
    s->gb.buffer_start = global_buffer;
    s->gb.buffer_end = global_buffer + sizeof(global_buffer);

    s->pb.buffer = global_pbuffer;
    s->pb.buffer_start = global_pbuffer;
    s->pb.buffer_end = global_pbuffer + sizeof(global_pbuffer);
    s->pb.eof = 0;

    s->buffer = global_buffer;
    s->buffer_size = sizeof(global_buffer);
    s->pbuffer = global_pbuffer;
    s->pbuffer_size = sizeof(global_pbuffer);
    s->stride = 1920;
    s->bpp = 3;
    s->yb = 1080;
    s->xb = 1920;

    s->blocks = global_blocks;
    s->nb_blocks = 65536;

    for (unsigned int i = 0; i < s->nb_blocks; i++) {
        s->blocks[i].w = 16;
        s->blocks[i].h = 16;
        s->blocks[i].size = 256;
        s->blocks[i].xor = 1;
    }
}