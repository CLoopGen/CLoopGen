#include <stdlib.h>
#include <stdint.h>

int32_t *p1;
int32_t *p2;
int i;
int order_half;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of total data
    order_half = data_size / sizeof(int32_t);

    p1 = (int32_t*)aligned_alloc(32, data_size);
    p2 = (int32_t*)aligned_alloc(32, data_size);

    for (int j = 0; j < order_half; j++) {
        p1[j] = rand() % 1000;
        p2[j] = rand() % 1000;
    }
}