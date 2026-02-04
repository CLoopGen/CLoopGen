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
int count;
int val;
int i;
int x;

static uint8_t *internal_buffer = NULL;
static int *midbuf_data = NULL;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of data for midbuf (about 0.01 sec runtime)
    count = data_size / sizeof(int);
    val = 5;
    i = 0;
    x = 0;

    internal_buffer = calloc(data_size, 1);
    if (!internal_buffer) exit(1);

    midbuf_data = calloc(count, sizeof(int));
    if (!midbuf_data) exit(1);

    s = malloc(sizeof(InterplayACMContext));
    if (!s) exit(1);

    s->gb.buffer = internal_buffer;
    s->gb.buffer_end = internal_buffer + data_size;
    s->gb.index = 0;
    s->gb.size_in_bits = 8 * data_size;
    s->gb.size_in_bits_plus8 = s->gb.size_in_bits + 8;

    s->bitstream = internal_buffer;
    s->max_framesize = data_size;
    s->bitstream_size = data_size;
    s->bitstream_index = 0;
    s->level = 1;
    s->rows = 256;
    s->cols = 256;
    s->wrapbuf_len = 4096;
    s->block_len = 1024;
    s->skip = 0;

    s->block = calloc(s->block_len, sizeof(int));
    s->wrapbuf = calloc(s->wrapbuf_len, sizeof(int));
    s->ampbuf = calloc(count, sizeof(int));
    s->midbuf = midbuf_data;

    if (!s->block || !s->wrapbuf || !s->ampbuf) exit(1);
}