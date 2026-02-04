#include <inttypes.h>
#include <stdlib.h>

unsigned char *mask;
unsigned char dst[16];
size_t i;

void init_vars() {
    const size_t data_size = 1024 * 128; // 128KB
    mask = (unsigned char *)malloc(data_size);
    for (size_t idx = 0; idx < 5; ++idx) {
        dst[idx] = (unsigned char)(idx * 31); // arbitrary initialization
    }
    for (size_t idx = 0; idx < 5; ++idx) {
        mask[idx] = 0;
    }
}