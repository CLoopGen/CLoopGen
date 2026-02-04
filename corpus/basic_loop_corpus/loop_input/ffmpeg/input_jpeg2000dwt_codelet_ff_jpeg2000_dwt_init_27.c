#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTContext {
    int linelen[32][2];
    uint8_t mod[32][2];
    uint8_t ndeclevels;
    uint8_t type;
    int32_t *i_linebuf;
    float *f_linebuf;
} DWTContext;

DWTContext *s;
int i;
int j;
int lev;
int b[2][2];

static int32_t *alloc_int32_buffer(size_t size) {
    int32_t *ptr = (int32_t *)malloc(size);
    if (!ptr) exit(1);
    return ptr;
}

static float *alloc_float_buffer(size_t size) {
    float *ptr = (float *)malloc(size);
    if (!ptr) exit(1);
    return ptr;
}

void init_vars() {
    const size_t data_size = 16 << 20;

    s = (DWTContext *)malloc(sizeof(DWTContext));
    if (!s) exit(1);

    s->i_linebuf = alloc_int32_buffer(data_size);
    s->f_linebuf = alloc_float_buffer(data_size);

    s->ndeclevels = 32;
    s->type = 0;

    lev = 0;

    b[0][0] = 100; b[0][1] = 200;
    b[1][0] = 150; b[1][1] = 250;

    i = 0;
    j = 0;
}