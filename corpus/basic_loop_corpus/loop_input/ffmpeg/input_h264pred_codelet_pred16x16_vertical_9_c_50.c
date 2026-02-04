#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

int i;
uint16_t *src;
int stride;
uint64_t a = 0xdeadbeefdeadbeefULL;
uint64_t b = 0xc0defeedc0defeedULL;
uint64_t c = 0xbaadf00dbaadf00dULL;
uint64_t d = 0x1eaff1eaff1eaff1ULL;

static uint16_t *internal_src_buffer;
static int internal_buffer_size = 16 * 1024 * 1024; // ~16MB of data

void init_vars() {
    internal_src_buffer = (uint16_t*)aligned_alloc(64, internal_buffer_size);
    if (!internal_src_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    src = internal_src_buffer;
    stride = 8; // ensures we access 4 uint64_t per row -> 8 uint16_t apart
}

__attribute__((destructor)) void cleanup_vars() {
    if (internal_src_buffer) {
        free(internal_src_buffer);
        internal_src_buffer = NULL;
    }
}