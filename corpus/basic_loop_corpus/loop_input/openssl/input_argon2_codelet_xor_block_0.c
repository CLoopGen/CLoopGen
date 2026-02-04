#include <stdint.h>
#include <string.h>

typedef struct {
    uint64_t v[128];
} BLOCK;

static BLOCK dst_block;
static BLOCK src_block;
BLOCK *dst = &dst_block;
BLOCK *src = &src_block;
int i;

void init_vars() {
    for (int j = 0; j < 128; ++j) {
        dst->v[j] = 0x5555555555555555ULL ^ j;
        src->v[j] = 0xAAAAAAAAAAAAAAAAULL ^ j;
    }
}