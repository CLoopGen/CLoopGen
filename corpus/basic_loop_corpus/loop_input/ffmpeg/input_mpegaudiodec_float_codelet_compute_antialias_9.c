#include <stdlib.h>
#include <string.h>

float csa_table[8][4] = {
    {1.0f, 0.5f, 0.0f, 0.0f},
    {0.9f, 0.4f, 0.0f, 0.0f},
    {0.8f, 0.3f, 0.0f, 0.0f},
    {0.7f, 0.25f, 0.0f, 0.0f},
    {0.6f, 0.2f, 0.0f, 0.0f},
    {0.5f, 0.15f, 0.0f, 0.0f},
    {0.4f, 0.1f, 0.0f, 0.0f},
    {0.3f, 0.05f, 0.0f, 0.0f}
};

float *ptr;
int n;
int i;

static float data_buffer[64 << 10]; // 256 KB of float data (~65536 elements)

void init_vars() {
    const int total_elements = sizeof(data_buffer) / sizeof(float);
    const int stride = 18;
    const int block_size = 8;
    
    // Initialize data buffer with non-zero values to avoid NaN/Inf propagation
    for (int idx = 0; idx < total_elements; idx++) {
        data_buffer[idx] = (float)(idx % 100) * 0.01f;
    }
    
    ptr = data_buffer + block_size; // Start such that -1-7 is valid
    n = (total_elements - 2 * block_size) / stride; // Ensure we don't overflow on last step
    if (n <= 0) n = 1;
}