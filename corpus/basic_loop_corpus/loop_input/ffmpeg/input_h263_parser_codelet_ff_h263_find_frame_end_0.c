#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int vop_found;
int i;
uint32_t state;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU
    buf = (uint8_t *)malloc(buf_size);
    if (!buf) {
        exit(1);
    }
    for (int j = 0; j < buf_size; j++) {
        buf[j] = rand() & 0xFF;
    }
    // Ensure that no 22-bit pattern equals 32 in shifted state to prevent premature break
    // We initialize state to a safe value and avoid triggering condition
    state = 0x12345678U; // Arbitrary non-matching initial state
    vop_found = 0;
    i = 0;
}