#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
ptrdiff_t pitch;
int16_t tmp[16];
int i;
int j;

static int16_t *buf_storage;
static ptrdiff_t buf_pitch;

void init_vars() {
    buf_pitch = 256 / sizeof(int16_t);
    buf_storage = (int16_t*)aligned_alloc(32, 256 * 256 * sizeof(int16_t));
    
    if (!buf_storage) exit(1);
    
    buf = buf_storage;
    pitch = buf_pitch;
    
    for (int k = 0; k < 16; k++) {
        tmp[k] = (int16_t)(k * 1000);
    }
}