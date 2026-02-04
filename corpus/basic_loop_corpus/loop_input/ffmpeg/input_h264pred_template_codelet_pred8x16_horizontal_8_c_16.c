#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
int i;
uint8_t *src;

#define DATA_SIZE (64 * 1024 * 1024)

static uint8_t buffer[DATA_SIZE];

void init_vars() {
    stride = 4096;
    src = buffer + 1;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}