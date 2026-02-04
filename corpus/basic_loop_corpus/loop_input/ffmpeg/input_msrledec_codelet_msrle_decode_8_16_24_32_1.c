#include <inttypes.h>
#include <stdlib.h>

uint8_t *output;
int p1;
int i;
uint16_t pix16;

void init_vars() {
    const size_t data_size = 134217728; // 128MB of data to target ~0.01s runtime
    output = (uint8_t *)aligned_alloc(2, data_size);
    if (!output) exit(1);
    p1 = data_size / 2;
    pix16 = 0xABCD;
}