#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    #pragma omp parallel for
    for (int i = 0; i < 256; i++) {
        int local_k = 1 + i * 256; // Eliminate loop-carried dependency on k
        for (int j = 1; j < 256; j++) {
            // Remove WAW and WAR hazards by making k access independent per i
            bb[j][i] = bb[j - 1][i] + flat_2d_array[local_k - 1] * cc[j][i];
            ++local_k;
        }
    }
}
}
