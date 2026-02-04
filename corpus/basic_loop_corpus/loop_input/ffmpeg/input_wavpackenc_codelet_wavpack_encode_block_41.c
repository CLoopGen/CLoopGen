#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples_l;
int i;
int nb_samples;
uint32_t crc;

void init_vars() {
    nb_samples = 67108864; // Approximately 256MB of int32_t data (67M elements)
    samples_l = (int32_t*)calloc(nb_samples, sizeof(int32_t));
    if (!samples_l) {
        exit(1);
    }
    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (int32_t)(j & 0x7FFF);
    }
    i = 0;
    crc = 0;
}