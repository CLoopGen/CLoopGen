#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride1;
ptrdiff_t stride2;
ptrdiff_t width;
ptrdiff_t height;
uint64_t sad;
uint16_t *src1w;
uint16_t *src2w;
int x;
int y;

static uint16_t *src1_storage = NULL;
static uint16_t *src2_storage = NULL;

void init_vars() {
    width = 2048;
    height = 128;
    stride1 = width;
    stride2 = width;
    sad = 0;

    size_t total_size = (size_t)width * height * sizeof(uint16_t);

    src1_storage = (uint16_t *)aligned_alloc(32, total_size);
    src2_storage = (uint16_t *)aligned_alloc(32, total_size);

    if (!src1_storage || !src2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < width * height; i++) {
        src1_storage[i] = rand() % 1024;
        src2_storage[i] = rand() % 1024;
    }

    src1w = src1_storage;
    src2w = src2_storage;
}