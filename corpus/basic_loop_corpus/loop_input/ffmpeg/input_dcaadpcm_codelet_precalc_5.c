#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t premultiplied_coeffs[10];

const int16_t ff_dca_adpcm_vb[4096][4] = {{0}};
premultiplied_coeffs *data;
int i;
int j;
int k;

void init_vars() {
    static premultiplied_coeffs data_storage[4096];
    data = data_storage;

    for (int idx = 0; idx < 4096; idx++) {
        for (int jdx = 0; jdx < 4; jdx++) {
            ((int16_t*)ff_dca_adpcm_vb)[idx * 4 + jdx] = rand() % 16384 - 8192;
        }
    }
}