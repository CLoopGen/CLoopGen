#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t main_stride = 4;
ptrdiff_t ref_stride = 4;
int64_t (*sums)[4];
int width = 1024 * 64;
uint16_t *main16;
uint16_t *ref16;
int x;
int y;
int z;

void init_vars() {
    main16 = aligned_alloc(64, sizeof(uint16_t) * 4 * width);
    ref16 = aligned_alloc(64, sizeof(uint16_t) * 4 * width);
    sums = aligned_alloc(64, sizeof(int64_t[width][4]));

    for (int i = 0; i < 4 * width; i++) {
        main16[i] = rand() % 256;
        ref16[i] = rand() % 256;
    }
}