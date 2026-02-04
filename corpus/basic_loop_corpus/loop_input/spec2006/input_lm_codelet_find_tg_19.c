#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned short uint16;
typedef uint16 s3lmwid_t;
typedef struct {
    s3lmwid_t wid;
    uint16 probid;
} tg_t;

typedef int int32;

tg_t *tg;
s3lmwid_t w;
int32 i;
int32 b;
int32 e;

static tg_t tg_buffer[65536];
static const size_t data_size = sizeof(tg_buffer) / sizeof(tg_t);

void init_vars() {
    tg = tg_buffer;
    w = (s3lmwid_t)42;
    b = 0;
    e = data_size - 1;

    for (size_t idx = 0; idx < data_size; ++idx) {
        tg[idx].wid = (s3lmwid_t)(idx + 1);
        tg[idx].probid = (uint16)(idx % 30000);
    }

    tg[e].wid = w;
}