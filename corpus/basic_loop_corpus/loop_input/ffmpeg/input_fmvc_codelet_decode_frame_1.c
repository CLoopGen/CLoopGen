#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
int y;
int x;
unsigned int block;
int k;
int l;
uint32_t *src;
uint32_t *dst;

static uint8_t *internal_buffer = NULL;
static uint8_t *internal_pbuffer = NULL;
static InterBlock *internal_blocks = NULL;
static uint32_t *internal_src_data = NULL;
static uint32_t *internal_dst_data = NULL;

void init_vars() {
    const int total_data_size = 16 * 1024 * 1024; // ~16MB for measurable runtime (~0.01s target)

    internal_buffer = (uint8_t*)calloc(1, total_data_size);
    internal_pbuffer = (uint8_t*)calloc(1, total_data_size);
    internal_src_data = (uint32_t*)calloc(1, total_data_size);
    internal_dst_data = (uint32_t*)calloc(1, total_data_size);

    if (!internal_buffer || !internal_pbuffer || !internal_src_data || !internal_dst_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize src with non-zero data to make XOR meaningful
    for (int i = 0; i < total_data_size / sizeof(uint32_t); ++i) {
        internal_src_data[i] = (uint32_t)(i * 7890123);
        internal_dst_data[i] = (uint32_t)(i * 5678901);
    }

    s = (FMVCContext*)calloc(1, sizeof(FMVCContext));
    if (!s) {
        fprintf(stderr, "FMVCContext allocation failed\n");
        exit(1);
    }

    s->buffer = internal_buffer;
    s->buffer_size = total_data_size;
    s->pbuffer = internal_pbuffer;
    s->pbuffer_size = total_data_size;
    s->stride = 256; // Simulate image stride of 256 pixels (1024 bytes per row)
    s->bpp = 4;
    s->yb = 64;
    s->xb = 64;

    s->nb_blocks = s->yb * s->xb;
    internal_blocks = (InterBlock*)calloc(s->nb_blocks, sizeof(InterBlock));
    if (!internal_blocks) {
        fprintf(stderr, "Blocks allocation failed\n");
        exit(1);
    }
    s->blocks = internal_blocks;

    // Distribute block sizes in a deterministic pattern
    for (unsigned int i = 0; i < s->nb_blocks; ++i) {
        int base_w = 4 + ((i * 17) % 8);  // 4-11
        int base_h = 4 + ((i * 19) % 8); // 4-11
        s->blocks[i].w = base_w;
        s->blocks[i].h = base_h;
        s->blocks[i].xor = 1;  // Ensure XOR path is taken
    }

    // Setup GetByteContext and PutByteContext
    s->gb.buffer_start = internal_buffer;
    s->gb.buffer = internal_buffer;
    s->gb.buffer_end = internal_buffer + total_data_size;

    s->pb.buffer_start = internal_pbuffer;
    s->pb.buffer = internal_pbuffer;
    s->pb.buffer_end = internal_pbuffer + total_data_size;
    s->pb.eof = 0;

    // Initialize global pointers
    src = internal_src_data;
    dst = internal_dst_data;
}