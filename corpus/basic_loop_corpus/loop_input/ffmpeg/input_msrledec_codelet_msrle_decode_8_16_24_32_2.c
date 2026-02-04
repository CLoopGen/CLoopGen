#include <stdint.h>
#include <stdlib.h>

uint8_t *output;
int p1;
int i;
uint8_t pix[3];

void init_vars() {
    const size_t total_output_size = 128 * 1024 * 1024; // 128 MB
    p1 = total_output_size / 3; // Each iteration writes 3 bytes

    output = (uint8_t*)malloc(total_output_size);
    if (!output) {
        exit(1);
    }

    pix[0] = 0x42;
    pix[1] = 0x6D;
    pix[2] = 0x9E;
}