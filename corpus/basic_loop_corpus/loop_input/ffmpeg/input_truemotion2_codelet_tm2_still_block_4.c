#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;

unsigned int *Uo;
unsigned int *Vo;
int oUstride;
int oVstride;

int *U;
int *V;
int Ustride;
int Vstride;

void init_vars() {
    const size_t total_data_size = 1 << 20; // 1MB of data for ~0.01 sec runtime estimate
    const int num_outer_iterations = 2;
    const int num_inner_iterations = 2;
    
    // Set strides in terms of element count (not bytes)
    oUstride = num_inner_iterations;
    oVstride = num_inner_iterations;
    Ustride = num_inner_iterations;
    Vstride = num_inner_iterations;

    // Allocate input/output arrays with padding to prevent overflow
    Uo = (unsigned int*)calloc(total_data_size, sizeof(unsigned int));
    Vo = (unsigned int*)calloc(total_data_size, sizeof(unsigned int));
    U = (int*)calloc(total_data_size, sizeof(int));
    V = (int*)calloc(total_data_size, sizeof(int));

    // Initialize input data to non-zero values for observable effects
    for (size_t idx = 0; idx < total_data_size; ++idx) {
        Uo[idx] = (unsigned int)(idx * 31);
        Vo[idx] = (unsigned int)(idx * 73 + 1);
    }
}