#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB to ensure ~0.01s runtime on modern CPU
#define WIDTH 8
#define ALIGNMENT 32

static uint8_t *aligned_dst_buffer;
static uint8_t *aligned_src_buffer;

void init_vars() {
    // Initialize coefficients
    A = 16;
    B = 32;
    C = 48;
    D = 64;

    // Set image height and width
    h = DATA_SIZE / (WIDTH * sizeof(uint8_t)) / 2;  // Two buffers: dst and src
    if (h < 1) h = 1;
    if (h > 16384) h = 16384;  // Cap for reasonable size

    // Set stride to width for simplicity (contiguous rows)
    stride = WIDTH;

    // Allocate aligned memory to prevent cache line issues and allow SIMD optimizations
    posix_memalign((void**)&aligned_dst_buffer, ALIGNMENT, (size_t)h * stride + ALIGNMENT);
    posix_memalign((void**)&aligned_src_buffer, ALIGNMENT, (size_t)h * stride + ALIGNMENT);

    dst = aligned_dst_buffer;
    src = aligned_src_buffer;

    // Initialize src data to avoid undefined behavior
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < stride; x++) {
            src[y * stride + x] = (uint8_t)((x * y + x) % 256);
        }
    }

    // Initialize dst with some baseline values
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < stride; x++) {
            dst[y * stride + x] = (uint8_t)((y * 3 + x * 7) % 256);
        }
    }

    // Ensure that accesses like src[stride + x + 1] are safe by padding last row if necessary
    // Since we access up to [stride + x + 1] where x goes up to 7, we need at least one extra row
    // Our current allocation already has enough rows due to loop bounds.
}