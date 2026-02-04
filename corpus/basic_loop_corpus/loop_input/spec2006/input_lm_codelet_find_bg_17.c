#include <stdio.h>
#include <inttypes.h>

typedef unsigned short uint16;
typedef uint16 s3lmwid_t;

typedef struct {
    s3lmwid_t wid;
    uint16 probid;
    uint16 bowtid;
    uint16 firsttg;
} bg_t;

typedef int int32;

static bg_t *bg_data;
static int32 data_size;
s3lmwid_t w;
int32 i;
int32 b;
int32 e;

bg_t *bg;

void init_vars() {
    data_size = 64 * 1024 * 1024 / sizeof(bg_t);
    bg_data = (bg_t*)__builtin_malloc(data_size * sizeof(bg_t));
    bg = bg_data;
    w = (s3lmwid_t)42;
    b = 0;
    e = data_size;
    
    for (int32 idx = 0; idx < data_size; idx++) {
        bg_data[idx].wid = (s3lmwid_t)(idx == data_size - 1 ? w : w + 1);
        bg_data[idx].probid = (uint16)(idx + 1);
        bg_data[idx].bowtid = (uint16)(idx + 2);
        bg_data[idx].firsttg = (uint16)(idx + 3);
    }
}