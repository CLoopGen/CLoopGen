#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long mt[312];
extern unsigned long long init_key[];
extern unsigned long long key_length;
extern unsigned long long i;
extern unsigned long long j;
extern unsigned long long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Strided access pattern: process every 4th element in a round-robin fashion
const size_t stride = 4;
size_t local_i = i % (312 * stride); // Extended logical index with stride
for (; k; k--, local_i += stride) {
    size_t physical_i = (local_i / stride) % 312; // Map logical strided index to physical
    size_t prev_i = (physical_i == 0) ? 311 : physical_i - 1;
    mt[physical_i] = (mt[physical_i] ^ ((mt[prev_i] ^ (mt[prev_i] >> 62)) * 3935559000370003845ULL)) + init_key[j] + j;
    j = (j + 1) % key_length;
}
i = local_i % 312;
}
