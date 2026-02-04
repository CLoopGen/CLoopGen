#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;
uint8_t min_distance[2] = {1, 2};

static int16_t *quantizer_output_data = NULL;

int16_t *quantizer_output = NULL;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(int16_t);
    quantizer_output_data = malloc(data_size);
    if (!quantizer_output_data) {
        exit(1);
    }
    quantizer_output = quantizer_output_data;

    for (size_t idx = 0; idx < (data_size / sizeof(int16_t)); idx++) {
        quantizer_output[idx] = (int16_t)(idx % 30000);
    }
}