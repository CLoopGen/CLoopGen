#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *y;
int lag;
float y_lp4[960];

void init_vars() {
    // Determine data size to achieve ~0.01s runtime
    // The loop runs lag>>2 iterations, each doing 2 loads and 1 store
    // Targeting ~10-20 million operations for ~0.01s on modern CPU
    
    lag = 960 * 2;  // Ensure we don't exceed y_lp4 bounds: j < lag>>2 => j < 480, but y_lp4 has 960 elements
    
    // Allocate y with sufficient size: need up to index 2*j where j < lag>>2
    // Maximum index: 2 * ((lag>>2) - 1) = 2 * (480 - 1) = 958, so we need at least 959 elements
    y = (float*)aligned_alloc(32, sizeof(float) * 1024);
    
    // Initialize y with dummy data
    for (int i = 0; i < 1024; i++) {
        y[i] = (float)(rand() % 1000) / 10.0f;
    }
    
    // Initialize y_lp4 with zeros
    memset(y_lp4, 0, sizeof(y_lp4));
}