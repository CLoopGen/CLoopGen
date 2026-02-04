#include <inttypes.h>
#include <stdlib.h>

uint8_t *msg;
size_t msg_len;
size_t i;
uint8_t *msg_mask;

void init_vars() {
    msg_len = 512 * 1024; // 512 KB of data for ~0.01 sec runtime on modern CPU

    msg = (uint8_t*)malloc(msg_len);
    msg_mask = (uint8_t*)malloc(msg_len);

    for (size_t j = 0; j < msg_len; ++j) {
        msg[j] = (uint8_t)(j & 0xFF);
        msg_mask[j] = (uint8_t)((j + 32) & 0xFF);
    }

    i = 0;
}