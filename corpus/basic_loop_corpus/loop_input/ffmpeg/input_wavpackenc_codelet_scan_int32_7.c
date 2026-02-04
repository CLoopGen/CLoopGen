#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *samples_l;
int32_t *samples_r;
int nb_samples;
uint32_t magdata;
uint32_t ordata;
uint32_t xordata;
uint32_t anddata;
uint32_t crc;
int i;

void init_vars() {
    // Set number of samples to achieve ~0.01s runtime
    // Each iteration does several operations; on modern CPU, ~1M-10M iterations typical for 0.01s
    // Using 4 million samples to target this range
    nb_samples = 4000000;

    // Allocate memory for sample arrays
    samples_l = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    // Initialize PRNG for reproducible results
    srand(0);
    
    // Fill arrays with random data
    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = rand() ^ (rand() << 15) ^ ((rand() & 0x7FFF) << 30);
        samples_r[j] = rand() ^ (rand() << 15) ^ ((rand() & 0x7FFF) << 30);
    }

    // Initialize accumulators
    magdata = 0;
    ordata = 0;
    xordata = 0;
    anddata = 0xFFFFFFFFU;
    crc = 0;
    i = 0;
}