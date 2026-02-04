#include <stdlib.h>
#include <stdint.h>

float *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    p = (float*)aligned_alloc(32, data_size);
    
    if (!p) exit(1);
    
    for (size_t idx = 0; idx < data_size / sizeof(float); idx++) {
        p[idx] = (float)(rand() % 1000) / 100.0f;
    }
    
    i0 = 2;  
    i1 = (data_size / sizeof(float)) / 2 - 4; 
}