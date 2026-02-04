#include <stdint.h>
#include <stddef.h>

uint8_t band_size_long[9][22];
uint16_t band_index_long[9][23];
int i;
int j;
int k;

void init_vars() {
    for (int idx_i = 0; idx_i < 9; idx_i++) {
        for (int idx_j = 0; idx_j < 22; idx_j++) {
            band_size_long[idx_i][idx_j] = 512;
        }
    }
}