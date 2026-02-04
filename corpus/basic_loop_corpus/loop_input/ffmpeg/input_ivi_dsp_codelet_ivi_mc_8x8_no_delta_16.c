#include <stdint.h>
#include <stddef.h>

int16_t *buf;
ptrdiff_t dpitch;
int16_t *ref_buf;
ptrdiff_t pitch;
int i;
int j;
int16_t *wptr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to target ~0.01s runtime
static int16_t buffer_pool[DATA_SIZE / sizeof(int16_t)];

void init_vars() {
    buf = buffer_pool;
    dpitch = 8;
    ref_buf = buffer_pool + 1024;
    pitch = 8;
    wptr = buffer_pool + 2048;
    
    i = 0;
    j = 0;
}