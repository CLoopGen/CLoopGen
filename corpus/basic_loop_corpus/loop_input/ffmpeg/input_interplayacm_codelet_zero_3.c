#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    int index;
    int size_in_bits;
    int size_in_bits_plus8;
} GetBitContext;

typedef struct InterplayACMContext {
    GetBitContext gb;
    uint8_t *bitstream;
    int max_framesize;
    int bitstream_size;
    int bitstream_index;
    int level;
    int rows;
    int cols;
    int wrapbuf_len;
    int block_len;
    int skip;
    int *block;
    int *wrapbuf;
    int *ampbuf;
    int *midbuf;
} InterplayACMContext;

InterplayACMContext *s;
unsigned int col;
unsigned int i;

static uint8_t static_buffer[1] = {0};
static int *block_mem;
static int *midbuf_mem;

void init_vars() {
    col = 0;
    i = 0;

    s = (InterplayACMContext*)calloc(1, sizeof(InterplayACMContext));
    if (!s) exit(1);

    s->level = 4;
    s->rows = 65536;
    s->cols = 1 << s->level;

    size_t block_size = s->rows * s->cols;
    size_t midbuf_size = 1;

    block_mem = (int*)calloc(block_size, sizeof(int));
    midbuf_mem = (int*)calloc(midbuf_size, sizeof(int));
    if (!block_mem || !midbuf_mem) exit(1);

    s->block = block_mem;
    s->midbuf = midbuf_mem;

    s->gb.buffer = static_buffer;
    s->gb.buffer_end = static_buffer + 1;
    s->bitstream = (uint8_t*)calloc(1, 1);
    s->max_framesize = 1;
    s->bitstream_size = 1;
    s->bitstream_index = 0;
    s->wrapbuf_len = 1;
    s->block_len = block_size;
    s->skip = 0;
    s->wrapbuf = (int*)calloc(1, sizeof(int));
    s->ampbuf = (int*)calloc(1, sizeof(int));
    if (!s->bitstream || !s->wrapbuf || !s->ampbuf) exit(1);
}