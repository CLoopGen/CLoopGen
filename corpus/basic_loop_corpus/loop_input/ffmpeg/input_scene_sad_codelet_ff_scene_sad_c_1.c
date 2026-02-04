#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src1;
ptrdiff_t stride1;
uint8_t *src2;
ptrdiff_t stride2;
ptrdiff_t width;
ptrdiff_t height;
uint64_t sad;
int x;
int y;

static uint8_t *internal_src1;
static uint8_t *internal_src2;

void init_vars() {
    width = 2048;
    height = 128;
    stride1 = width;
    stride2 = width;

    size_t total_size = (size_t)width * height;

    internal_src1 = calloc(total_size, sizeof(uint8_t));
    internal_src2 = calloc(total_size, sizeof(uint8_t));

    if (!internal_src1 || !internal_src2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        internal_src1[i] = rand() % 256;
        internal_src2[i] = rand() % 256;
    }

    src1 = internal_src1;
    src2 = internal_src2;
    sad = 0;
    x = 0;
    y = 0;
}