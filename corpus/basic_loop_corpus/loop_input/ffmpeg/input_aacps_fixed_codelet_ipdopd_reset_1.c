#include <stdlib.h>
#include <stdint.h>

int8_t *ipd_hist;
int8_t *opd_hist;
int i;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 1MB of data
    ipd_hist = (int8_t *)calloc(data_size, sizeof(int8_t));
    opd_hist = (int8_t *)calloc(data_size, sizeof(int8_t));
}