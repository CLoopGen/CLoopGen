#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t stride;
int32_t height;
int8_t cnt;

static uint8_t buffer[134217728]; // 128 MB buffer to ensure sufficient data size

void init_vars() {
    stride = 65536; // 64 KB stride for spatial separation
    height = 4096;
    src = buffer;
    cnt = 0;
}