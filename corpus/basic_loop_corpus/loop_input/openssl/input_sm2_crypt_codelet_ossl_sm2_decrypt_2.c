#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t *ptext_buf;
int i;
uint8_t *msg_mask;
uint8_t *C2;
int msg_len;

static uint8_t *alloc_zeroed(size_t size) {
    uint8_t *ptr = (uint8_t *)calloc(1, size);
    return ptr;
}

void init_vars() {
    msg_len = 512 * 1024; // 512 KB of data for ~0.01 sec runtime on modern CPU

    ptext_buf = alloc_zeroed(msg_len);
    msg_mask = alloc_zeroed(msg_len);
    C2 = alloc_zeroed(msg_len);

    for (int j = 0; j < msg_len; ++j) {
        C2[j] = (uint8_t)(j & 0xFF);
        msg_mask[j] = (uint8_t)((j + 31) & 0xFF);
    }
}