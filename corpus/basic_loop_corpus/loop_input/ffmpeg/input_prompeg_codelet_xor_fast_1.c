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

uint8_t *in1;
uint8_t *in2;
uint8_t *out;
int i;
int n;
uint32_t v1;
uint32_t v2;

static uint8_t *in1_storage;
static uint8_t *in2_storage;
static uint8_t *out_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    size_t num_uint32 = data_size / sizeof(uint32_t);

    in1_storage = aligned_alloc(32, data_size);
    in2_storage = aligned_alloc(32, data_size);
    out_storage = aligned_alloc(32, data_size);

    if (!in1_storage || !in2_storage || !out_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_uint32; ++idx) {
        ((uint32_t*)in1_storage)[idx] = (uint32_t)(idx * 789);
        ((uint32_t*)in2_storage)[idx] = (uint32_t)(idx * 345);
    }

    in1 = in1_storage;
    in2 = in2_storage;
    out = out_storage;
    n = (int)num_uint32;
    i = 0;
    v1 = 0;
    v2 = 0;
}