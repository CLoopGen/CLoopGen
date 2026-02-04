#include <stdint.h>
#include <string.h>

size_t kems_algs_len = 524288; // Approximately 0.01 seconds runtime
unsigned int i = 0;
uint8_t kems_doit[524288];

void init_vars() {
    for (size_t idx = 0; idx < kems_algs_len; idx++) {
        kems_doit[idx] = (uint8_t)(idx % 256);
    }
}