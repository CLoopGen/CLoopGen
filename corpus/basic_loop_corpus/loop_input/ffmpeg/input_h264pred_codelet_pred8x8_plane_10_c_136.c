#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 16;
uint16_t * src0;
uint16_t * src1;
uint16_t * src2;
int H = 0;
int V = 0;

static uint16_t data_pool[131072]; // 256KB of data (131072 elements)

void init_vars() {
    size_t total_size = sizeof(data_pool);
    size_t element_size = sizeof(uint16_t);
    size_t num_elements = total_size / element_size;

    src0 = data_pool;
    src1 = data_pool + (num_elements / 3);
    src2 = data_pool + (2 * num_elements / 3);

    stride = 64;
    k = 0;
    H = 0;
    V = 0;

    for (size_t i = 0; i < num_elements; ++i) {
        data_pool[i] = (uint16_t)(i % 30000);
    }
}