#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
int i;
int j;
int block;
int h;
int w;

void init_vars() {
    s = (FMVCContext *)calloc(1, sizeof(FMVCContext));
    if (!s) return;

    s->bpp = 1;
    h = 112;
    w = 84;

    s->yb = 60;
    s->xb = 60;
    s->nb_blocks = (unsigned int)(s->yb * s->xb);
    block = 0;

    s->blocks = (InterBlock *)calloc(s->nb_blocks, sizeof(InterBlock));
    if (!s->blocks) {
        free(s);
        s = NULL;
        return;
    }

    s->buffer_size = 1024 * 1024 * 4;
    s->buffer = (uint8_t *)calloc(1, s->buffer_size);
    s->pbuffer_size = 1024 * 1024 * 4;
    s->pbuffer = (uint8_t *)calloc(1, s->pbuffer_size);
    s->stride = w * s->bpp;

    s->gb.buffer_start = (const uint8_t *)calloc(1, 1024);
    s->gb.buffer = s->gb.buffer_start;
    s->gb.buffer_end = s->gb.buffer_start + 1024;

    s->pb.buffer_start = (uint8_t *)calloc(1, 1024);
    s->pb.buffer = s->pb.buffer_start;
    s->pb.buffer_end = s->pb.buffer_start + 1024;
    s->pb.eof = 0;
}