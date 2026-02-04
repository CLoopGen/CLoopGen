#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Plane {
    uint8_t *buffers[2];
    uint8_t *pixels[2];
    uint32_t width;
    uint32_t height;
    ptrdiff_t pitch;
} Plane;

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

Plane *plane;
uint8_t *dst;
ptrdiff_t dst_pitch;
int dst_height;
int x;
int y;
uint8_t *src;
ptrdiff_t pitch;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static Plane plane_storage;

void init_vars() {
    const uint32_t data_size = 64 * 1024 * 1024; // ~64MB for sufficient runtime (~0.01s target)
    const uint32_t width = 8192;
    const uint32_t height = (data_size + width - 1) / width;
    
    src_buffer = (uint8_t*)aligned_alloc(32, data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, data_size);
    
    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    plane_storage.width = width;
    plane_storage.height = height;
    plane_storage.pitch = width;
    plane_storage.buffers[0] = src_buffer;
    plane_storage.buffers[1] = dst_buffer;
    plane_storage.pixels[0] = src_buffer;
    plane_storage.pixels[1] = dst_buffer;

    plane = &plane_storage;
    src = src_buffer;
    pitch = plane_storage.pitch;
    dst = dst_buffer;
    dst_pitch = plane_storage.pitch;
    dst_height = height;

    x = 0;
    y = 0;
}